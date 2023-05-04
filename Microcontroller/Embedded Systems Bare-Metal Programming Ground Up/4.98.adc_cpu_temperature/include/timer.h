/*
 ****************************************************************
 * @file           : Timer header
 * @author         : Jose Luis Figueroa
 * @Date		   : 9 sep, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Timer header contains all the prototype 
 *                 : functions used to control the Timer
 ****************************************************************
 */
#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f4xx.h"

void timer2_1hz_init(void);
void timer2_output_compare_1(void);
void timer2_output_compare_2(void);
void timer3_input_capture(void);
void timer2_pwm(void);

#endif /*TIMER_H_*/