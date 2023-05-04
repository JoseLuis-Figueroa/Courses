/*
 ****************************************************************
 * @file           : Timer header
 * @author         : Jose Luis Figueroa
 * @Date		   : 10 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Timer header contains all the prototipe 
 *                 : functions used to control the Timer
 ****************************************************************
 */
#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f4xx.h"

void timer2_1hz_init();
void timer2_pa5_output_compare();

#endif /*TIMER_H_*/