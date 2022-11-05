/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: MyPC
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NOPRESS 	0
#define PRESS 		1
#define LONGPRESS 	2

#define NORMAL_STATE 	SET
#define PRESSED_STATE 	RESET

extern int TimeOutForKeyPress[NUM_OF_BUTTON];
void getKeyInput();

int isButtonPress();
int isButtonLongPress();


#endif /* INC_BUTTON_H_ */
