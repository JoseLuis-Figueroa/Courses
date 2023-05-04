/*
 ****************************************************************
 * @file           : Timer implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 10 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : timer.c implements a timer of 1 second using
 *                 : SYSCLK=16MHz. Calculate: 
 *                 : Freq = SYSCLK / ((Prescaler-1)(Period-1))
 *                 : Freq = 16MHz / ((1599)(9999)) = 1Hz.
 *                 : PA5 is configured to toggle each second with 
 *                 : alternate function using output compare 
 *                 : timer 2, channel 1. 
 ****************************************************************
 */

#include "timer.h"


void timer2_1hz_init()
{
    /*Enable clock access to timer2*/
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    /*Set prescaler value*/
    TIM2->PSC = 1600 - 1;   
    /*Set auto-reload value*/
    TIM2->ARR = 10000 - 1;  
    /*Clear counter*/
    TIM2->CNT = 0;
    /*Enable timer*/
    TIM2->CR1 |= TIM_CR1_CEN;
}

void timer2_pa5_output_compare()
{
    /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	/*Set PA5 as output pin*/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |= (1U<<11);
    /*Set PA5 alternate function type to TIM2_CH1 (AF1)*/
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL5_0;
    /*Enable clock access to timer2*/
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    /*Set prescaler value*/
    TIM2->PSC = 1600 - 1;   
    /*Set auto-reload value*/
    TIM2->ARR = 10000 - 1;  
    /*Set output compare in toggle mode*/
    TIM2->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0;
    /*Enable timer2 ch1 in compare mode*/
    TIM2->CCER |= TIM_CCER_CC1E;
    /*Clear counter*/
    TIM2->CNT = 0;
    /*Enable timer*/
    TIM2->CR1 |= TIM_CR1_CEN;
}