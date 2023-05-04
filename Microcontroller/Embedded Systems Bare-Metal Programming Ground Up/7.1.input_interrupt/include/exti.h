/*
 ****************************************************************
 * @file           : Interrupt header
 * @author         : Jose Luis Figueroa
 * @Date		   : 1 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Interrupt header contains all the prototype 
 *                 : functions used to control the Timer
 ****************************************************************
 */
#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f4xx.h"

void pc13_exti_init(void);

#endif /*TIMER_H_*/