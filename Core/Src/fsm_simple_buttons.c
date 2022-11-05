/*
 * fsm_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MyPC
 */

/*
 * fsm_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MyPC
 */

#include "fsm_simple_buttons.h"

void fsm_simple_buttons_run(){
	// LED toggle every a second
	if(timer_flag2==1){
		HAL_GPIO_TogglePin(LED_PORT, LED_Pin);
		setTimer2(1000);
	}
	switch (status){
	// System waiting state.
	case INIT:{
		// Display zero when the system is waiting every 1 second.
		if(timer_flag1==1){
			display7SEG(0,0);
			setTimer1(1000);
		}
		// When RESET is pressed
		resetButtonPress();
		// When INC is pressed
		incButtonPress();
		// When DEC is pressed
		decButtonPress();
		break;
	}
	// Status DEC button pressed
	case DEC:{
		if(timer_flag1==1){
			// Check the controller 10 seconds is enough, then the system switches in
			// countdown status
			if(counter_time[0]==10)
				status=SYSTEM;
			counter_time[0]++;
			// Control the time interval when the DEC button is pressed for more than 1 second
			// and only increment the counter when 3 seconds have passed since pressing DEC
			if (TimeOutForKeyPress[2]>200 ||TimeOutForKeyPress[2]<100){
				counter[0]--;
				if(counter[0]==-1) counter[0]=9;
				display7SEG(0,counter[0]);
			}
			setTimer1(1000);
		}
		// When RESET is pressed
		resetButtonPress();
		// When INC is pressed
		incButtonPress();
		// When DEC is pressed
		decButtonPress();
		// When pressing DEC
		decButtonLongPress();
		break;
	}
	// Status button pressed INC
	case INC:{
		if(timer_flag1==1){
			// Check the controller 10 seconds is enough, then the system switches in
			// countdown status
			counter_time[0]++;
			if(counter_time[0]==11)
				status=SYSTEM;
			// Control the time interval when the INC button is pressed for more than 1 second
			// and only increment the counter when 3 seconds have passed since pressing INC
			if( TimeOutForKeyPress[1]>200||TimeOutForKeyPress[1]<100){
				counter[0]++;
				if(counter[0]==10) counter[0]=0;
				display7SEG(0,counter[0]);
			}//
			setTimer1(1000);
		}
		// When RESET is pressed
		resetButtonPress();
		// When INC is pressed
		incButtonPress();
		// When DEC is pressed
		decButtonPress();
		// When pressing INC
		incButtonLongPress();
		break;
	}
	// System status starts counting down
	case SYSTEM:{
		if(timer_flag1==1){
			// Switch to system standby when counter=0;
			if(counter[0]>0){
				counter[0]--;
				display7SEG(0,counter[0]);
				setTimer1(1000);
			}
			if(counter[0]==0){
				status=INIT;
				counter[0]=0;
				setTimer1(1000);
			}
		}
		// When RESET is pressed
		resetButtonPress();
		// When INC is pressed
		incButtonPress();
		// When pressing DEC
		decButtonPress();
		break;
	}
	default:
		break;
	}
}

