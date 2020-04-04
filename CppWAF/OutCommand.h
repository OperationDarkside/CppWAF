/*
 * OutCommand.h
 *
 *  Created on: Dec 13, 2019
 *      Author: coldfusion
 */

#ifndef OUTCOMMAND_H_
#define OUTCOMMAND_H_

#include <string>
#include <vector>

#include "OutCommandType.h"

namespace cwaf {

class OutCommand {
public:

	std::size_t getComponentId() {
		return componentId;
	}

	void setComponentId(std::size_t id) {
		componentId = id;
	}

	std::size_t getPropertyId() {
		return propertyId;
	}

	void setPropertyId(std::size_t id) {
		propertyId = id;
	}

	std::uint16_t getComponentTypeId() {
		return componentTypeId;
	}

	void setComponentTypeId(std::uint16_t id) {
		componentTypeId = id;
	}

	OUT_COMMAND_TYPE getCommandType() {
		return type;
	}

	void setCommandType(OUT_COMMAND_TYPE t) {
		type = t;
	}

	std::string getCustomOutput() {
		return customOutput;
	}

	void setCustomOutput(std::string custOut) {
		customOutput = std::move(custOut);
	}

	std::vector<OutCommand>& getSubCommands() {
		return subCommands;
	}

private:
	std::uint16_t propertyId = 0;
	std::uint16_t componentTypeId = 0;
	std::size_t componentId = 0;
	OUT_COMMAND_TYPE type;
	std::string customOutput;
	std::vector<OutCommand> subCommands;
};
}

#endif /* OUTCOMMAND_H_ */
