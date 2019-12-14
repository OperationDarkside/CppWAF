/*
 * WafSession.h
 *
 *  Created on: Sep 1, 2019
 *      Author: coldfusion
 */

#ifndef CPPWAF_WAFSESSION_H_
#define CPPWAF_WAFSESSION_H_

#include <memory>

namespace cwaf {

template<typename UI_Type>
class WafSession {
public:

	UI_Type& getUI() {
		return *ui;
	}

private:
	std::unique_ptr<UI_Type> ui = std::make_unique<UI_Type>();
};
}


#endif /* CPPWAF_WAFSESSION_H_ */
