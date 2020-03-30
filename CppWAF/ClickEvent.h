/*
 * ClickEvent.h
 *
 *  Created on: Mar 28, 2020
 *      Author: coldfusion
 */

#ifndef CLICKEVENT_H_
#define CLICKEVENT_H_

class ClickEvent {
public:

	bool isUserOriginated(){
		return userOriginated;
	}

	void setUserOriginated(bool userOrigin){
		userOriginated = userOrigin;
	}

private:
	bool userOriginated = true;
};


#endif /* CLICKEVENT_H_ */
