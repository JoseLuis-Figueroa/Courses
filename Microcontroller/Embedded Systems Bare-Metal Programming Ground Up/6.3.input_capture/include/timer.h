/*
 ****************************************************************
 * @file           : Timer header
 * @author         : Jose Luis Figueroa
 * @Date		   : 14 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Timer header contains all the prototype 
 *                 : functions used to control the Timer
 ****************************************************************
 */
#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f4xx.h"

void timer2_1hz_init(void);
void timer2_output_compare(void);
void timer3_input_capture(void);

#endif /*TIMER_H_*/