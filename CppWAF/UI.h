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
		router.addFunc = [&](size_t id, Component* c) {
			c->setId(id);
			c->setRouter(&router);
			index.emplace(id, c);
		};

		router.removeFunc = [&](size_t id){
			auto it = index.extract(id);
			it.value().setId(0);
			it.value().clearRouter();
		};
	}

	void setComponent(std::unique_ptr<Component> &&newRoot) {
		for(auto&[id, comp] : index){
			comp->setId(0);
			comp->clearRouter();
		}
		index.clear();
		router.clearId();

		root = std::move(newRoot);
		root->setId(router.getNextId());
		root->setRouter(&router);
	}

	void distributeCommands(std::vector<Command>& cmds){

	}

	std::vector<Command> getInitCommands() {

	}

private:
	Router router;
	std::map<size_t, Component*> index;
	std::unique_ptr<Component> root;
};
}

#endif /* CPPWAF_UI_H_ */
