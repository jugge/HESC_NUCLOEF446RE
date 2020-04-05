/*
 * it.c
 *
 *  Created on: Mar 13, 2020
 *      Author: Jorgen.Persson
 */

#include "stm32f4xx_hal.h"

void SysTick_Handler(void){
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
