#ifndef CPPWAF_COMPONENT_H_
#define CPPWAF_COMPONENT_H_

#include "Connector.h"

namespace cwaf {

class Component {
public:

	size_t getId() {
		return id;
	}
	void setId(size_t _id) {
		id = _id;
	}

	void setConnector(Connector* connector) {
		conn = connector;
	}
private:
	size_t id = 0;
	Connector* conn = nullptr;
};
}

#endif
