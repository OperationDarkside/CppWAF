/*
 * Button.h
 *
 *  Created on: Dec 13, 2019
 *      Author: coldfusion
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <iostream>
#include <string>
#include <functional>

#include "Component.h"
#include "ClickEvent.h"
#include "Property.h"

namespace cwaf {

class Button: public Component {
public:

	Button(){
		setTypeId();
	}

	void setCaption(const std::string capt){
		caption.setValue(capt);
	}

	virtual void recieveCommand(InCommand& cmd) override {
		if(cmd.getType() == IN_COMMAND_TYPE::CLICK){
			ClickEvent event;
			for(const auto& listener : clickListeners){
				listener(event);
			}
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
		outCmd.setCustomOutput("{\"caption\":\"" + caption.getValue() + "\"}");

		router->addCommand(outCmd);
	}

	constexpr void setTypeId(){
		typeId = 1;
	}

	void addClickListener(std::function<void(const ClickEvent&)>&& listener){
		clickListeners.emplace_back(std::move(listener));
	}

protected:
	virtual void setRouterInternal(Router* newRouter) override {
		caption.setRouter(newRouter);
	}

private:
	static const std::string& toString(const std::string& str){
		return str;
	}

	Property<std::string, &Button::toString> caption {"caption"};
	std::vector<std::function<void(const ClickEvent&)>> clickListeners;


};
}

#endif /* BUTTON_H_ */
