/*
 * TextBox.h
 *
 *  Created on: Sep 1, 2019
 *      Author: coldfusion
 */

#ifndef CPPWAF_TEXTBOX_H_
#define CPPWAF_TEXTBOX_H_

#include <functional>
#include <string>
#include <vector>

#include "Component.h"
#include "ValueChangeEvent.h"

namespace cwaf {
class TextBox : Component {
public:

	const std::string& getValue(){
		return value;
	}
	void setValue(std::string _value){
		value = std::move(_value);
	}

	void addValueChangeListener(std::function<void(const ValueChangeEvent&)>&& listener){
		valChangeListeners.emplace(std::move(listener));
	}
private:
	std::string value;
	std::vector<std::function<void(const ValueChangeEvent&)>> valChangeListeners;
};
}

#endif /* CPPWAF_TEXTBOX_H_ */
