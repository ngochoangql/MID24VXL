/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MyPC
 */


#include "button.h"


int status_button[NUM_OF_BUTTON]={};
int KeyReg0[NUM_OF_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[NUM_OF_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[NUM_OF_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int TimeOutForKeyPress[NUM_OF_BUTTON] =  {300,300,300};

int button_flag_press[NUM_OF_BUTTON] = {};
int button_flag_longpress[NUM_OF_BUTTON] = {};

int isButtonPress(int button_idx){
	if(button_flag_press[button_idx]==1){
		button_flag_press[button_idx]=0;
		return 1;
	}
	return 0;
}
int isButtonLongPress(int idx_button){
	return button_flag_longpress[idx_button];
}

void getKeyInput(){
	for(int i=0;i<NUM_OF_BUTTON;i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON[i]);

		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if(KeyReg3[i]!=KeyReg2[i]){
				KeyReg3[i]=KeyReg2[i];
				if (KeyReg2[i]==PRESSED_STATE){
					TimeOutForKeyPress[i]=300;
					if(button_flag_longpress[i]!=1)
						button_flag_press[i]=1;
				}else{
					button_flag_longpress[i]=0;
					TimeOutForKeyPress[i]=300;
				}
			}else{
				TimeOutForKeyPress[i]--;
				if(TimeOutForKeyPress[i]==0){
					KeyReg3[i]=NORMAL_STATE;
					if(KeyReg2[i]==PRESSED_STATE)
						button_flag_longpress[i]=1;
				}
			}
		}
		/*

		switch(status_button[i]){
			// trang thai khong nhan
			case NOPRESS:
				// khoi tao lai TimeOutForKeyPress[i]=100
				TimeOutForKeyPress[i]=300;
				// khoi tao button_flag_longpress[i]=0
				button_flag_longpress[i]=0;
				// KeyReg0==KeyReg1=KeyReg2 thi la trang thai press
				if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i]))
					if(KeyReg3[i]!=KeyReg2[i]){
						if (KeyReg2[i]==PRESSED_STATE)
							status_button[i]=PRESS;
						KeyReg3[i]=KeyReg2[i];
					}

			break;
			// trang thai nhan
			case PRESS:
				if(TimeOutForKeyPress[i]>0){
					TimeOutForKeyPress[i]--;
					if(TimeOutForKeyPress[i]==0)
						//trang thai longpress
						status_button[i]=LONGPRESS;
					else
						//  dung co press
						button_flag_press[i]=1;
				}
				break;
			case LONGPRESS:
				// dung co longpress
				button_flag_longpress[i]=1;
				// tro ve trang thai nopress khi KeyReg2=NORMAL_STATE
				if(KeyReg2[i]==NORMAL_STATE)
					status_button[i]=NOPRESS;
				break;
			default:
			break;
			}*/
	}
}
