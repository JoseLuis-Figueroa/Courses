/*
 ****************************************************************
 * @file           : Timer header
 * @author         : Jose Luis Figueroa
 * @Date		   : 3 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Timer header contains all the prototype 
 *                 : functions used to control the Timer
 ****************************************************************
 */
#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f4xx.h"

void timer2_1hz_init(void);
void timer2_1hz_interrupt_init(void);

#endif /*TIMER_H_*/