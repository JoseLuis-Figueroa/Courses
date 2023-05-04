/*
 ****************************************************************
 * @file           : System Tick Timer header
 * @author         : Jose Luis Figueroa
 * @Date		   : 3 Jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Systick header contains all the prototipe 
 *                 : functions used to control the Systick
 ****************************************************************
 */
#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stm32f4xx.h"

/*Constants*/
#define MICRO_SECOND_VAL    16
#define MILLI_SECOND_VAL    16000
#define ONE_SECOND_VAL      16000000

void systick_delayms(uint16_t delay);
void systick_delayus(uint16_t delay);
void systick_delay_interrupt(void);

#endif /*SYSTICK_H_*/
