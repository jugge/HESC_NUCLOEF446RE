/*
 * motor_control_wrapper.h
 *
 *  Created on: 20 Mar 2020
 *      Author: Jorgen.Persson
 */

#ifndef INC_MOTOR_CONTROL_WRAPPER_H_
#define INC_MOTOR_CONTROL_WRAPPER_H_

#ifdef MOTORCONTROLPWM
//#include "motor_control_pwm.h"
//#define FULL_SPEED_AHEAD ForwardGPIO
//#define HALF_SPEED_AHEAD ForwardGPIO
//#define SLOW_SPEED_AHEAD ForwardGPIO
//#define FULL_SPEED_REVERSE ReverseGPIO
//#define HALF_SPEED_REVERSE ReverseGPIO
//#define SLOW_SPEED_REVERSE ReverseGPIO
#else
#include "motor_control_gpio.h"
#define FULL_SPEED_AHEAD ForwardGPIO
#define HALF_SPEED_AHEAD ForwardGPIO
#define SLOW_SPEED_AHEAD ForwardGPIO
#define FULL_SPEED_REVERSE ReverseGPIO
#define HALF_SPEED_REVERSE ReverseGPIO
#define SLOW_SPEED_REVERSE ReverseGPIO
#define HARD_TURN_RIGHT TurnRightGPIO
#define EASY_TURN_RIGHT TurnRightGPIO
#define HARD_TURN_LEFT TurnLeftGPIO
#define EASY_TURN_LEFT TurnLeftGPIO
#define FULL_STOP StopMotorsGPIO
#endif


#endif /* INC_MOTOR_CONTROL_WRAPPER_H_ */
