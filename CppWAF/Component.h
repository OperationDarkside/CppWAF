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

	void setRouter(Router* newRouter){
		router = newRouter;
	}

	void clearRouter(){
		router = nullptr;
	}

	virtual void recieveCommand(Command& cmd) = 0;

private:
	size_t id = 0;
	Router* router = nullptr;
};
}

#endif
