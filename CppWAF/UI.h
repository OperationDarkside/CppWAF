/*
 * UI.h
 *
 *  Created on: Sep 1, 2019
 *      Author: coldfusion
 */

#ifndef CPPWAF_UI_H_
#define CPPWAF_UI_H_

#include "Component.h"
#include <memory>
#include "Router.h"

namespace cwaf {
class UI {
public:
	void setContent(std::shared_ptr<Component> component) {
		if (rootComponent) {
			//connector.removeComponent(rootComponent->getId());
		}
		router.registerComponent(component);

		rootComponent = component;
	}

	std::shared_ptr<Component> getContent() {
		return rootComponent;
	}

private:
	std::shared_ptr<Component> rootComponent;
	Router router;
};
}

#endif /* CPPWAF_UI_H_ */
