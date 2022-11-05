/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: MyPC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define LED_PORT 		GPIOA
#define LED7SEG_PORT 	GPIOB
#define BUTTON_PORT 	GPIOA


#define NUM_OF_BUTTON  	4
#define NUM_OF_LED7SEG	1

#define INIT 	0
#define DEC 	1
#define INC 	2
#define SYSTEM 	3

extern int status;
extern int counter[NUM_OF_LED7SEG];
extern int counter_time[NUM_OF_LED7SEG];
extern GPIO_PinState A[NUM_OF_LED7SEG];
extern GPIO_PinState B[NUM_OF_LED7SEG];
extern GPIO_PinState C[NUM_OF_LED7SEG];
extern GPIO_PinState D[NUM_OF_LED7SEG];
extern GPIO_PinState E[NUM_OF_LED7SEG];
extern GPIO_PinState F[NUM_OF_LED7SEG];
extern GPIO_PinState G[NUM_OF_LED7SEG];
extern GPIO_PinState BUTTON[NUM_OF_BUTTON];

#endif /* INC_GLOBAL_H_ */
