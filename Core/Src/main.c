/*
 * main.c
 *
 *  Created on: Mar 13, 2020
 *      Author: Jorgen.Persson
 */

#include <stdio.h>


#include "stm32f4xx_hal.h"
#include "main.h"
#include "motor_control_wrapper.h"

int main(void) {

	HAL_Init();
	SystemClockConfig();
	GPIO_Init();
	for(;;){
		//TODO: Make the test sequence delay controlled and only run when in certain debug mode. But first test this on HW.
		//Test Sequence
		FULL_SPEED_AHEAD();
		FULL_STOP();
		FULL_SPEED_REVERSE();
		FULL_STOP();
		HARD_TURN_LEFT();
		HARD_TURN_RIGHT();
		FULL_STOP();
	}


	return 0;
}

void SystemClockConfig(void) {


}


void GPIO_Init(void){
	/*
	 * Enable GPIOA Clk
	 */

	__GPIOA_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();

	/*
	 * GPIO Sections
	 */
	MotorControlGPIO_Init();

}



void Error_handler(void) {
	//printf("error");
	//return 0;
}
