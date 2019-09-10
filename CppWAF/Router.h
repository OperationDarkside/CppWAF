/*
 * Router.h
 *
 *  Created on: Sep 1, 2019
 *      Author: coldfusion
 */

#ifndef CPPWAF_ROUTER_H_
#define CPPWAF_ROUTER_H_

#include <memory>
#include <unordered_map>

#include "Component.h"
#include "ComponentConnection.h"

namespace cwaf {
class Router {
public:
	Router (){
		std::function<void(const std::shared_ptr<Component>&)> reg = [&](const std::shared_ptr<Component>& component){
			size_t id = nextId++;

			auto comp = component.get();
			comp->setId(id);

			std::weak_ptr<Component> wpComp = component;
			compMap.emplace(id, wpComp);
		};
		std::function<void(const std::vector<Command>&)> cmd = [&](const std::vector<Command> &cmds){

		};
		conn = std::make_shared<ComponentConnection>();
		conn->setReg(std::move(reg));
		conn->setCmd(std::move(cmd));
	}

	void registerComponent(const std::shared_ptr<Component>& component) {
		size_t id = nextId++;

		auto comp = component.get();
		comp->setId(id);
		comp->connect(conn);

		std::weak_ptr<Component> wpComp = component;
		compMap.emplace(id, wpComp);
	}

	void sendCommands(const std::vector<Command> &cmds) {

	}

private:
	size_t nextId = 0;
	std::shared_ptr<ComponentConnection> conn;
	std::unordered_map<int, std::weak_ptr<Component>> compMap;
};
}

#endif /* CPPWAF_CONNECTOR_H_ */
