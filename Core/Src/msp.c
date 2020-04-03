/*
 * msp.c
 *
 *  Created on: Mar 13, 2020
 *      Author: Jorgen.Persson
 */

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"

void HAL_MspInit(void) {
//Here we will do low level processor specific inits
	//1. Setup priority grouping
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. Enable the required system exceptions
	SCB->SHCSR |= 0x7 << 16; //usage_fault, memory_fault, bus_fault exceptions

	//3. Congfigure the priority for the system exceptions.
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htimer) {
	//First enable the clock for TIM6
	__HAL_RCC_TIM6_CLK_ENABLE();

	//Enable IRQ SETTINGS
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

	//Configure the priority for this IRQ number
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 15, 0);
}
