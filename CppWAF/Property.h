/*
 * Property.h
 *
 *  Created on: Mar 28, 2020
 *      Author: coldfusion
 */

#ifndef PROPERTY_H_
#define PROPERTY_H_

#include <string>

#include "PropertyBase.h"

namespace cwaf {
template<typename Type, const std::string& Stringifier(const std::string& str)>
class Property : public PropertyBase {
public:

	Property (std::uint16_t type_id, std::uint16_t prop_id) : PropertyBase(type_id, prop_id) {

	}

	const Type& getValue() {
		return value;
	}

	void setValue(const Type& newValue, const bool isUserOriginated){
		value = newValue;

		if(router == nullptr || isUserOriginated){
			return;
		}

		router->addCommand(getCreateCommand());
	}

	OutCommand getCreateCommand() override {
		OutCommand outCmd;
		outCmd.setCommandType(OUT_COMMAND_TYPE::UPDATE);
		outCmd.setPropertyId(property_id);
		outCmd.setComponentId(comp_id);
		outCmd.setComponentTypeId(typeId);
		outCmd.setCustomOutput("\"" + Stringifier(value) + "\"");

		return outCmd;
	}

private:
	Type value;
};
}


#endif /* PROPERTY_H_ */
