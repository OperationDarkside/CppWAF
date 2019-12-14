/*
 * OutCommand.h
 *
 *  Created on: Dec 13, 2019
 *      Author: coldfusion
 */

#ifndef OUTCOMMAND_H_
#define OUTCOMMAND_H_

#include <string>

#include "OutCommandType.h"

namespace cwaf {

class OutCommand {
public:

	size_t getComponentId() {
		return componentId;
	}

	void setComponentId(size_t id) {
		componentId = id;
	}

	unsigned short getComponentTypeId() {
		return componentTypeId;
	}

	void setComponentTypeId(unsigned short id) {
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

private:
	size_t componentId = 0;
	unsigned short componentTypeId = 0;
	OUT_COMMAND_TYPE type;
	std::string customOutput;
};
}

#endif /* OUTCOMMAND_H_ */
