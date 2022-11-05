/*
 * status_3button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: MyPC
 */

#ifndef INC_STATUS_3BUTTON_H_
#define INC_STATUS_3BUTTON_H_

#include "main.h"
#include "global.h"
#include "fsm_simple_buttons.h"
#include "timer.h"
#include "led_display.h"
#include "button.h"

void resetButtonPress();
void incButtonPress();
void decButtonPress();
void incButtonLongPress();
void decButtonLongPress();


#endif /* INC_STATUS_3BUTTON_H_ */
