/*
 * UI.h
 *
 *  Created on: Sep 1, 2019
 *      Author: coldfusion
 */

#ifndef CPPWAF_UI_H_
#define CPPWAF_UI_H_

#include "Component.h"
#include "Connector.h"

#include <memory>

namespace cwaf {
class UI {
public:
	void setContent(std::shared_ptr<Component> component) {
		if (rootComponent) {
			connector.removeComponent(rootComponent->getId());
		}
		connector.registerComponent(component);

		rootComponent = component;
	}

	std::shared_ptr<Component> getContent() {
		return rootComponent;
	}

private:
	std::shared_ptr<Component> rootComponent;
	Connector connector;
};
}

#endif /* CPPWAF_UI_H_ */
