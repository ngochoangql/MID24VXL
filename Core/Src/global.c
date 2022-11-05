/*
 * global.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MyPC
 */

#include "global.h"

int status = 0;
int counter[NUM_OF_LED7SEG] = {0};
int counter_time[NUM_OF_LED7SEG]={0};
GPIO_PinState A[NUM_OF_LED7SEG]={A0_Pin};
GPIO_PinState B[NUM_OF_LED7SEG]={B0_Pin};
GPIO_PinState C[NUM_OF_LED7SEG]={C0_Pin};
GPIO_PinState D[NUM_OF_LED7SEG]={D0_Pin};
GPIO_PinState E[NUM_OF_LED7SEG]={E0_Pin};
GPIO_PinState F[NUM_OF_LED7SEG]={F0_Pin};
GPIO_PinState G[NUM_OF_LED7SEG]={G0_Pin};
GPIO_PinState BUTTON[NUM_OF_BUTTON]={BUTTON1_Pin,BUTTON2_Pin,BUTTON3_Pin};

