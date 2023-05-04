/*
 ****************************************************************
 * @file           : Interrupt header
 * @author         : Jose Luis Figueroa
 * @Date		   : 15 sep, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Interrupt header contains all the prototype 
 *                 : functions used to control the Timer
 ****************************************************************
 */
#ifndef EXTI_H_
#define EXTI_H_

#include "stm32f4xx.h"

void pc13_exti_init(void);
void pb10_exti_init(void);

#endif /*EXTI_H_*/