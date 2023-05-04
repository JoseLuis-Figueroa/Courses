/*
 ****************************************************************
 * @file           : System Tick Timer header
 * @author         : Jose Luis Figueroa
 * @Date		   : 1 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Systick header contains all the prototipe 
 *                 : functions used to control the Systick
 ****************************************************************
 */
#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stm32f4xx.h"

void systick_delayms(uint16_t delay);

#endif /*SYSTICK_H_*/
