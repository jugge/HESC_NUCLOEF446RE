/*
 * motor_control_gpio.h
 *
 *  Created on: 20 Mar 2020
 *      Author: Jorgen.Persson
 */

#ifndef INC_MOTOR_CONTROL_GPIO_H_
#define INC_MOTOR_CONTROL_GPIO_H_

void MotorControlGPIO_Init(void);
void MotorControlGPIOTest(void);
void StopMotorsGPIO(void);
void ForwardGPIO(void);
void ReverseGPIO(void);
void TurnLeftGPIO(void);
void TurnRightGPIO(void);

#endif /* INC_MOTOR_CONTROL_GPIO_H_ */
