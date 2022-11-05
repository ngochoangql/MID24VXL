/*
 * led_display.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MyPC
 */

#include "led_display.h"

void display7SEG(int idx_led,int num){

	HAL_GPIO_WritePin(LED7SEG_PORT, A[idx_led]|B[idx_led]|C[idx_led]|D[idx_led]|
	E[idx_led]|F[idx_led]|G[idx_led], RESET);

	if(num==0){
		HAL_GPIO_WritePin(LED7SEG_PORT, G[idx_led], SET);
	}
	if(num==1){
		HAL_GPIO_WritePin(LED7SEG_PORT, A[idx_led]|D[idx_led]|
		E[idx_led]|F[idx_led]|G[idx_led], SET);
	}
	if(num==2){
		HAL_GPIO_WritePin(LED7SEG_PORT, C[idx_led]|F[idx_led], SET);
	}
	if(num==3){
		HAL_GPIO_WritePin(LED7SEG_PORT, E[idx_led]|F[idx_led], SET);
	}
	if(num==4){
		HAL_GPIO_WritePin(LED7SEG_PORT, A[idx_led]|D[idx_led]|E[idx_led], SET);
	}
	if(num==5){
		HAL_GPIO_WritePin(LED7SEG_PORT, B[idx_led]|E[idx_led], SET);
	}
	if(num==6){
		HAL_GPIO_WritePin(LED7SEG_PORT, B[idx_led], SET);
		}
	if(num==7){
		HAL_GPIO_WritePin(LED7SEG_PORT, D[idx_led]|E[idx_led]|F[idx_led]|G[idx_led], SET);
	}
	if(num==9){
		HAL_GPIO_WritePin(LED7SEG_PORT, E[idx_led], SET);
	}
}
