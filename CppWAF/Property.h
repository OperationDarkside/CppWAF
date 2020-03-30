/*
 * Property.h
 *
 *  Created on: Mar 28, 2020
 *      Author: coldfusion
 */

#ifndef PROPERTY_H_
#define PROPERTY_H_

#include <string>

#include "Router.h"

namespace cwaf {
template<typename Type, const std::string& Stringifier(const std::string& str)>
class Property {
public:

	Property (std::string n) : name(std::move(n)) {

	}

	void setRouter(Router* newRouter){
		router = newRouter;
	}

	void setComponentId(size_t id) {
		comp_id = id;
	}

	const Type& getValue() {
		return value;
	}

	void setValue(const Type& newValue){
		value = newValue;

		if(router == nullptr){
			return;
		}
		OutCommand outCmd;
		outCmd.setCommandType(OUT_COMMAND_TYPE::UPDATE);
		outCmd.setComponentId(comp_id);
		outCmd.setCustomOutput("{\"" + name + "\":\"" + Stringifier(value) + "\"}");

		router->addCommand(outCmd);
	}

private:
	size_t comp_id = 0;
	std::string name;
	Type value;
	Router* router = nullptr;
};
}


#endif /* PROPERTY_H_ */
