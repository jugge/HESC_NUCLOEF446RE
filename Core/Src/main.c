/*
 * main.c
 *
 *  Created on: Mar 13, 2020
 *      Author: Jorgen.Persson
 */

#include <stdio.h>


#include "stm32f4xx_hal.h"

#include "stm32f4xx_hal_tim.h"

#include "main.h"
#include "motor_control_wrapper.h"

TIM_HandleTypeDef htimer6;

int main(void) {

	HAL_Init();
	SystemClockConfig();
	GPIO_Init();
	TIMER6_Init();
	//Start the timer
	HAL_TIM_Base_Start(&htimer6);

	for(;;){
		//TODO: Make the test sequence delay controlled and only run when in certain debug mode.
		//Test Sequence
		FULL_SPEED_AHEAD();
		hundredms_wt(10);
		FULL_STOP();
		hundredms_wt(10);
		FULL_SPEED_REVERSE();
		hundredms_wt(10);
		FULL_STOP();
		hundredms_wt(10);
		HARD_TURN_LEFT();
		hundredms_wt(10);
		HARD_TURN_RIGHT();
		hundredms_wt(10);
		FULL_STOP();
		hundredms_wt(10);


		/* Try Udemys example */
//		while ( ! (TIM6->SR & TIM_SR_UIF) );
//		TIM6->SR = 0;
//		printf("1");
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

	/* led gpio init */
	GPIO_InitTypeDef ledgpio;
	ledgpio.Pin = GPIO_PIN_5;
	ledgpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledgpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &ledgpio);
}


void TIMER6_Init(void){
	htimer6.Instance = TIM6;
	htimer6.Init.Prescaler = 24;
	htimer6.Init.Period = 64-1;
	if (HAL_TIM_Base_Init(&htimer6) != HAL_OK){
		Error_handler();
	}
}


void Error_handler(void) {
	//printf("error");
	//return 0;
}


void hundredms_wt(int deciseconds) {
//	for (int i=0;i<deciseconds;i++) {
//		TIM6->SR = 0;
//		while( ! (TIM6->SR & TIM_SR_UIF) );
//		TIM6->SR = 0;
//	}
//
/* Temporarily use the predefined delay to test the function with the kids */
	HAL_Delay(deciseconds*100);

}
