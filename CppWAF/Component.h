#ifndef CPPWAF_COMPONENT_H_
#define CPPWAF_COMPONENT_H_

#include <memory>

#include "ComponentConnection.h"

namespace cwaf {

class Component {
public:

	size_t getId() {
		return id;
	}
	void setId(size_t _id) {
		id = _id;
	}

	void connect(std::weak_ptr<ComponentConnection>&& _conn) {
		conn = std::move(_conn);
	}

	void disconnect(){

	}
private:
	size_t id = 0;
	std::weak_ptr<ComponentConnection> conn;
};
}

#endif
