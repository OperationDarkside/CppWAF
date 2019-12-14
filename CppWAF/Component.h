#ifndef CPPWAF_COMPONENT_H_
#define CPPWAF_COMPONENT_H_

#include <memory>

#include "Router.h"

namespace cwaf {

class Component {
public:

	virtual ~Component() = default;

	size_t getId() {
		return id;
	}
	void setId(size_t _id) {
		id = _id;
	}

	unsigned short getTypeId(){
		return typeId;
	}

	void setRouter(Router* newRouter){
		router = newRouter;
	}

	void clearRouter(){
		router = nullptr;
	}

	virtual void recieveCommand(InCommand& cmd) = 0;
	virtual void createCommand() = 0;

protected:
	size_t id = 0;
	unsigned short typeId = 0;
	Router* router = nullptr;
};
}

#endif
