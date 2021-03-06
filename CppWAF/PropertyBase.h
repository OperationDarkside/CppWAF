/*
 * PropertyBase.h
 *
 *  Created on: Apr 4, 2020
 *      Author: coldfusion
 */

#ifndef PROPERTYBASE_H_
#define PROPERTYBASE_H_

#include "Router.h"

namespace cwaf {
class PropertyBase {
public:

	PropertyBase (std::uint16_t type_id, std::uint16_t prop_id) : typeId(type_id), property_id(prop_id) {

	}

	virtual ~PropertyBase() = default;

	void setRouter(Router* newRouter){
		router = newRouter;
	}

	void setComponentId(std::size_t id) {
		comp_id = id;
	}

	virtual OutCommand getCreateCommand() = 0;

protected:
	std::uint16_t property_id;
	std::uint16_t typeId = 0;
	std::size_t comp_id = 0;
	Router* router = nullptr;
};
}


#endif /* PROPERTYBASE_H_ */
