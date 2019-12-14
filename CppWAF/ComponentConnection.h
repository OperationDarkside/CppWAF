/*
 * ComponentConnection.h
 *
 *  Created on: Sep 10, 2019
 *      Author: coldfusion
 */

#ifndef COMPONENTCONNECTION_H_
#define COMPONENTCONNECTION_H_

#include <functional>
#include <utility>

#include "InCommand.h"

namespace cwaf {

class Component;

class ComponentConnection {

public:

	void setReg(std::function<void(const std::shared_ptr<Component>&)>&& reg){
		registerCallback = std::forward<std::function<void(const std::shared_ptr<Component>&)>>(reg);
	}

	void setCmd(std::function<void(const std::vector<Command>&)>&& cmd){
		cmdCallback = std::forward<std::function<void(const std::vector<Command>&)>>(cmd);
	}

	void registerComponent(const std::shared_ptr<Component> &component) {
		registerCallback(component);
	}

	void sendCommands(const std::vector<Command> &cmds) {
		cmdCallback(cmds);
	}

private:
	std::function<void(const std::shared_ptr<Component>&)> registerCallback;
	std::function<void(const std::vector<Command>&)> cmdCallback;
};

}

#endif /* COMPONENTCONNECTION_H_ */
