/*
 * WafSession.h
 *
 *  Created on: Sep 1, 2019
 *      Author: coldfusion
 */

#ifndef CPPWAF_WAFSESSION_H_
#define CPPWAF_WAFSESSION_H_


namespace cwaf {

template<typename UI_Type>
class WafSession {
public:

	const UI_Type& getUI() {
		return ui;
	}

private:
	UI_Type ui;
};
}


#endif /* CPPWAF_WAFSESSION_H_ */
