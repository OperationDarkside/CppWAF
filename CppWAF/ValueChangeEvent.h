#ifndef CPPWAF_VALUECHANGEEVENT_H_
#define CPPWAF_VALUECHANGEEVENT_H_

#include <string>

namespace cwaf {
class ValueChangeEvent {
public:
	ValueChangeEvent(std::string _newValue, std::string _oldValue, bool uOrigin) :
			newValue(std::move(_newValue)), oldValue(std::move(_oldValue)), userOriginated(
					uOrigin) {
	}

	const std::string& getNewValue() {
		return newValue;
	}

	const std::string& getOldValue() {
		return newValue;
	}

	bool isUserOriginated() {
		return userOriginated;
	}

private:
	std::string newValue;
	std::string oldValue;
	bool userOriginated = true;
};
}

#endif
