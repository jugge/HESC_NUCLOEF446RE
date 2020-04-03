/*
 * main.h
 *
 *  Created on: Mar 13, 2020
 *      Author: Jorgen.Persson
 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_

void SystemClockConfig(void);

void GPIO_Init(void);

void TIMER6_Init(void);

void Error_handler(void);

void hundredms_wt(int deciseconds);

#endif /* INC_MAIN_H_ */
