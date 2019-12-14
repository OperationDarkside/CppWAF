/*
 * Button.h
 *
 *  Created on: Dec 13, 2019
 *      Author: coldfusion
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <iostream>

#include "Component.h"

namespace cwaf {

class Button: public Component {
public:

	Button(){
		setTypeId();
	}

	virtual void recieveCommand(InCommand& cmd) override {
		if(cmd.getType() == IN_COMMAND_TYPE::CLICK){
			std::cout << "Receivied Click" << std::endl;
		}
	}

	virtual void createCommand() override {
		if(router == nullptr){
			return;
		}
		OutCommand outCmd;
		outCmd.setCommandType(OUT_COMMAND_TYPE::CREATE);
		outCmd.setComponentId(id);
		outCmd.setComponentTypeId(typeId);
		outCmd.setCustomOutput("{\"caption\":\"Click Me!\"}");

		router->addCommand(outCmd);
	}

	constexpr void setTypeId(){
		typeId = 1;
	}

private:
};

}

#endif /* BUTTON_H_ */
