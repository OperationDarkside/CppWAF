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

#include "Command.h"

namespace cwaf {

class Component;

class Router {
public:
	Router() {

	}

	void registerComponent(const Component *component) {
		addFunc(nextId++, component);
	}

	void unregisterComponent(size_t id) {
		removeFunc(id);
	}

	void addCommand(Command cmd) {
		commands.push_back(cmd);
	}

	auto& getCommands() {
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
	std::vector<Command> commands;
};
}

#endif /* CPPWAF_CONNECTOR_H_ */
