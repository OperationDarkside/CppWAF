/*
 * Router.h
 *
 *  Created on: Sep 1, 2019
 *      Author: coldfusion
 */

#ifndef CPPWAF_ROUTER_H_
#define CPPWAF_ROUTER_H_

#include <functional>
#include <vector>

#include "InCommand.h"
#include "OutCommand.h"

namespace cwaf {

class Component;

class Router {
public:

	void registerComponent(Component *component) {
		addFunc(nextId++, component);
	}

	void unregisterComponent(size_t id) {
		removeFunc(id);
	}

	void addCommand(OutCommand cmd) {
		commands.push_back(cmd);
	}

	std::vector<OutCommand>& getCommands() {
		return commands;
	}

	size_t getNextId(){
		return nextId++;
	}

	void clearId(){
		nextId = 1;
	}

	std::function<void(size_t, Component*)> addFunc;
	std::function<void(size_t)> removeFunc;
private:
	size_t nextId = 1;
	std::vector<OutCommand> commands;
};
}

#endif /* CPPWAF_CONNECTOR_H_ */
