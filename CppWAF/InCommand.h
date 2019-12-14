/*
 * Command.h
 *
 *  Created on: Sep 10, 2019
 *      Author: coldfusion
 */

#ifndef INCOMMAND_H_
#define INCOMMAND_H_

#include "InCommandType.h"

namespace cwaf {
class InCommand {
public:

	size_t getComponentId() {
		return componentId;
	}

	void setComponentId(size_t id) {
		componentId = id;
	}

	IN_COMMAND_TYPE getType() {
		return type;
	}

	void setType(IN_COMMAND_TYPE newType) {
		type = newType;
	}

private:
	size_t componentId = 0;
	IN_COMMAND_TYPE type;
};
}

#endif /* INCOMMAND_H_ */
