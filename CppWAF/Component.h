#ifndef CPPWAF_COMPONENT_H_
#define CPPWAF_COMPONENT_H_

#include <memory>
#include <vector>

#include "Router.h"
#include "PropertyBase.h"

namespace cwaf {

class Component {
public:

	virtual ~Component() = default;

	std::size_t getId() {
		return id;
	}
	void setId(std::size_t _id) {
		id = _id;
	}

	std::uint16_t getTypeId(){
		return typeId;
	}

	void setRouter(Router* newRouter){
		router = newRouter;
		setRouterInternal(router);
		for(const auto prop : properties){
			prop->setComponentId(id);
			prop->setRouter(router);
		}
	}

	// Could be omitted and replaced with setRouter
	void clearRouter(){
		router = nullptr;
		setRouter(router);
	}

	virtual void recieveCommand(InCommand& cmd) = 0;
	virtual void createCommand() = 0;

protected:
	std::size_t id = 0;
	std::uint16_t typeId = 0;
	Router* router = nullptr;
	std::vector<PropertyBase*> properties;

	virtual void setRouterInternal(Router* newRouter) = 0;
};
}

#endif
