/*
 * Connector.h
 *
 *  Created on: Sep 1, 2019
 *      Author: coldfusion
 */

#ifndef CPPWAF_CONNECTOR_H_
#define CPPWAF_CONNECTOR_H_

#include <memory>
#include <unordered_map>

#include "Component.h"

namespace cwaf {
class Connector {
public:

	void registerComponent(const std::shared_ptr<Component>& component) {
		size_t id = nextId++;

		auto comp = component.get();
		comp->setId(id);
		comp->setConnector(this);

		std::weak_ptr<Component> wpComp = component;
		compMap.emplace(id, wpComp);
	}

	void removeComponent(size_t id) {
		compMap.erase(id);
	}
private:
	size_t nextId = 0;
	std::unordered_map<int, std::weak_ptr<Component>> compMap;
};
}

#endif /* CPPWAF_CONNECTOR_H_ */
