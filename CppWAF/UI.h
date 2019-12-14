/*
 * UI.h
 *
 *  Created on: Sep 1, 2019
 *      Author: coldfusion
 */

#ifndef CPPWAF_UI_H_
#define CPPWAF_UI_H_

#include "Router.h"
#include "Component.h"
#include <memory>
#include <map>
#include <vector>

namespace cwaf {
class UI {
public:

	UI() {
		router.addFunc = [&](size_t id, Component *c) {
			c->setId(id);
			c->setRouter(&router);
			index.emplace(id, c);
		};

		router.removeFunc = [&](size_t id) {
			auto it = index.find(id);
			if(it == index.end()){
				return;
			}
			it->second->setId(0);
			it->second->clearRouter();
			index.erase(it);
		};
	}

	UI(const UI& newUI) {
		std::cout << "Copy" << std::endl;
	}

	void setComponent(std::unique_ptr<Component> &&newRoot) {
		for(auto&[id, comp] : index) {
			comp->setId(0);
			comp->clearRouter();
		}
		index.clear();
		router.clearId();

		root = std::move(newRoot);
		root->setId(router.getNextId());
		root->setRouter(&router);
		index.emplace(root->getId(), root.get());
	}

	void distributeCommands(std::vector<InCommand> &cmds) {
		for(InCommand& cmd : cmds){
			index.at(cmd.getComponentId())->recieveCommand(cmd);
		}
	}

	std::vector<OutCommand>& getInitCommands() {
		std::cout << &router << std::endl;
		for(auto const&it : index) {
			it.second->createCommand();
		}

		std::vector<OutCommand> &out = router.getCommands();
		if (!index.empty()) {
			OutCommand rootOutCmd;
			rootOutCmd.setCommandType(OUT_COMMAND_TYPE::RELATION);
			rootOutCmd.setComponentId(root->getId());
			rootOutCmd.setCustomOutput("{\"target\":0}");
			out.push_back(std::move(rootOutCmd));
		}

		return out;
	}

	std::vector<OutCommand>& getOutCommands() {
		return router.getCommands();
	}

private:
	Router router;
	std::map<size_t, Component*> index;
	std::unique_ptr<Component> root;
};
}

#endif /* CPPWAF_UI_H_ */
