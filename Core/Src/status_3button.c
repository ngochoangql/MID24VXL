/*
 * status_3button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MyPC
 */

#include "status_3button.h"

void resetButtonPress(){
	// counter set to 0
	if(isButtonPress(0)==1){
		counter_time[0]=0;
		counter[0]=0;
		display7SEG(0,0);
		setTimer1(1000);
	}
}
void incButtonPress(){
	// The next system session is the INC pressed state.
	if(isButtonPress(1)==1){
		status=INC;
		setTimer1(1000);
		counter[0]++;
		if(counter[0]==10) counter[0]=0;
		display7SEG(0,counter[0]);
		//Create a 10 second timer from pressing
		counter_time[0]=0;
	}
}
void decButtonPress(){
	// The next system session is the DEC pressed state.
	if(isButtonPress(2)==1){
		status=DEC;
		counter[0]--;
		setTimer1(1000);
		if(counter[0]==-1) counter[0]=9;
		display7SEG(0,counter[0]);
		// Create a 10 second timer from pressing
		counter_time[0]=0;
	}
}

void incButtonLongPress(){
	//While holding down the INC button
	if(isButtonLongPress(1)==1){
		status=INC;
		if(timer_flag1==1){
			counter[0]++;
			// Create a 10 second timer from pressing
			counter_time[0]=0;
			if(counter[0]==10) counter[0]=0;
			display7SEG(0,counter[0]);
			setTimer1(1000);
		}
	}
}
void decButtonLongPress(){
	// While holding down the DEC button
	if(isButtonLongPress(2)==1){
		if(timer_flag1==1){
			counter[0]--;
			if(counter[0]==-1) counter[0]=9;
			// Create a 10 second timer from pressing
			counter_time[0]=0;
			display7SEG(0,counter[0]);
			setTimer1(1000);
		}
	}
}

