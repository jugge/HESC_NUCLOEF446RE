/*
 * motor_control_gpio.c
 *
 *  Created on: 20 Mar 2020
 *      Author: Jorgen.Persson
 */

#include "stm32f4xx_hal.h"
#include "motor_control_gpio.h"

#define FRONT_RIGHT_WHEEL_PORT GPIOA
#define FRONT_LEFT_WHEEL_PORT GPIOB
#define REAR_RIGHT_WHEEL_PORT GPIOA
#define REAR_LEFT_WHEEL_PORT GPIOA

#define FRONT_RIGHT_WHEEL_FORWARD_PIN GPIO_PIN_0
#define FRONT_RIGHT_WHEEL_REVERSE_PIN GPIO_PIN_1
#define FRONT_LEFT_WHEEL_FORWARD_PIN GPIO_PIN_10
#define FRONT_LEFT_WHEEL_REVERSE_PIN GPIO_PIN_2
#define REAR_RIGHT_WHEEL_FORWARD_PIN GPIO_PIN_10
#define REAR_RIGHT_WHEEL_REVERSE_PIN GPIO_PIN_11
#define REAR_LEFT_WHEEL_FORWARD_PIN GPIO_PIN_8
#define REAR_LEFT_WHEEL_REVERSE_PIN GPIO_PIN_9

void MotorControlGPIO_Init(void) {

	GPIO_InitTypeDef gpio_init;



	/*
	 *  MOTOR CONTROL GPIO
	 */

	gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_init.Speed = GPIO_SPEED_LOW;
	gpio_init.Pull = GPIO_NOPULL;

	/*
	 * Front Wheel Left
	 * PA0 - Forward
	 * PA1 - Reverse
	 */
	gpio_init.Pin = GPIO_PIN_0;
	HAL_GPIO_Init(GPIOA, &gpio_init);
	gpio_init.Pin = GPIO_PIN_1;
	HAL_GPIO_Init(GPIOA, &gpio_init);

	/*
	 * Front Wheel Right
	 * PB10 - Forward
	 * PB2 - Reverse
	 */
	gpio_init.Pin = GPIO_PIN_10;
	HAL_GPIO_Init(GPIOB, &gpio_init);
	gpio_init.Pin = GPIO_PIN_2;
	HAL_GPIO_Init(GPIOB, &gpio_init);

	/*
	 * Rear Wheel Left
	 * PA8 - Forward
	 * PA9 - Reverse
	 */
	gpio_init.Pin = GPIO_PIN_8;
	HAL_GPIO_Init(GPIOA, &gpio_init);
	gpio_init.Pin = GPIO_PIN_9;
	HAL_GPIO_Init(GPIOA, &gpio_init);

	/*
	 * Rear Wheel Right
	 * PA10 - Forward
	 * PA11 - Reverse
	 */
	gpio_init.Pin = GPIO_PIN_10;
	HAL_GPIO_Init(GPIOA, &gpio_init);
	gpio_init.Pin = GPIO_PIN_11;
	HAL_GPIO_Init(GPIOA, &gpio_init);

	/*
	 * END OF MOTOR CONTROL GPIO
	 */

}

void MotorControlGPIOTest(void){


}

void StopMotorsGPIO(void){
	HAL_GPIO_WritePin(FRONT_RIGHT_WHEEL_PORT, FRONT_RIGHT_WHEEL_FORWARD_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FRONT_LEFT_WHEEL_PORT, FRONT_LEFT_WHEEL_FORWARD_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(REAR_RIGHT_WHEEL_PORT, REAR_RIGHT_WHEEL_FORWARD_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(REAR_LEFT_WHEEL_PORT, REAR_LEFT_WHEEL_FORWARD_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FRONT_RIGHT_WHEEL_PORT, FRONT_RIGHT_WHEEL_REVERSE_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FRONT_LEFT_WHEEL_PORT, FRONT_LEFT_WHEEL_REVERSE_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(REAR_RIGHT_WHEEL_PORT, REAR_RIGHT_WHEEL_REVERSE_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(REAR_LEFT_WHEEL_PORT, REAR_LEFT_WHEEL_REVERSE_PIN, GPIO_PIN_RESET);
}

void ForwardGPIO(void){
	HAL_GPIO_WritePin(FRONT_RIGHT_WHEEL_PORT, FRONT_RIGHT_WHEEL_FORWARD_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(FRONT_LEFT_WHEEL_PORT, FRONT_LEFT_WHEEL_FORWARD_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(REAR_RIGHT_WHEEL_PORT, REAR_RIGHT_WHEEL_FORWARD_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(REAR_LEFT_WHEEL_PORT, REAR_LEFT_WHEEL_FORWARD_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(FRONT_RIGHT_WHEEL_PORT, FRONT_RIGHT_WHEEL_REVERSE_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FRONT_LEFT_WHEEL_PORT, FRONT_LEFT_WHEEL_REVERSE_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(REAR_RIGHT_WHEEL_PORT, REAR_RIGHT_WHEEL_REVERSE_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(REAR_LEFT_WHEEL_PORT, REAR_LEFT_WHEEL_REVERSE_PIN, GPIO_PIN_RESET);
}

void ReverseGPIO(void){
	HAL_GPIO_WritePin(FRONT_RIGHT_WHEEL_PORT, FRONT_RIGHT_WHEEL_FORWARD_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FRONT_LEFT_WHEEL_PORT, FRONT_LEFT_WHEEL_FORWARD_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(REAR_RIGHT_WHEEL_PORT, REAR_RIGHT_WHEEL_FORWARD_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(REAR_LEFT_WHEEL_PORT, REAR_LEFT_WHEEL_FORWARD_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FRONT_RIGHT_WHEEL_PORT, FRONT_RIGHT_WHEEL_REVERSE_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(FRONT_LEFT_WHEEL_PORT, FRONT_LEFT_WHEEL_REVERSE_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(REAR_RIGHT_WHEEL_PORT, REAR_RIGHT_WHEEL_REVERSE_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(REAR_LEFT_WHEEL_PORT, REAR_LEFT_WHEEL_REVERSE_PIN, GPIO_PIN_SET);
}

void TurnLeftGPIO(void){
	HAL_GPIO_WritePin(FRONT_RIGHT_WHEEL_PORT, FRONT_RIGHT_WHEEL_FORWARD_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(FRONT_LEFT_WHEEL_PORT, FRONT_LEFT_WHEEL_FORWARD_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(REAR_RIGHT_WHEEL_PORT, REAR_RIGHT_WHEEL_FORWARD_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(REAR_LEFT_WHEEL_PORT, REAR_LEFT_WHEEL_FORWARD_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FRONT_RIGHT_WHEEL_PORT, FRONT_RIGHT_WHEEL_REVERSE_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(FRONT_LEFT_WHEEL_PORT, FRONT_LEFT_WHEEL_REVERSE_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(REAR_RIGHT_WHEEL_PORT, REAR_RIGHT_WHEEL_REVERSE_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(REAR_LEFT_WHEEL_PORT, REAR_LEFT_WHEEL_REVERSE_PIN, GPIO_PIN_SET);
}

void TurnRightGPIO(void) {
	HAL_GPIO_WritePin(FRONT_RIGHT_WHEEL_PORT, FRONT_RIGHT_WHEEL_FORWARD_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(FRONT_LEFT_WHEEL_PORT, FRONT_LEFT_WHEEL_FORWARD_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(REAR_RIGHT_WHEEL_PORT, REAR_RIGHT_WHEEL_FORWARD_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(REAR_LEFT_WHEEL_PORT, REAR_LEFT_WHEEL_FORWARD_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(FRONT_RIGHT_WHEEL_PORT, FRONT_RIGHT_WHEEL_REVERSE_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(FRONT_LEFT_WHEEL_PORT, FRONT_LEFT_WHEEL_REVERSE_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(REAR_RIGHT_WHEEL_PORT, REAR_RIGHT_WHEEL_REVERSE_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(REAR_LEFT_WHEEL_PORT, REAR_LEFT_WHEEL_REVERSE_PIN, GPIO_PIN_RESET);
}