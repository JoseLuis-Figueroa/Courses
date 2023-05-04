/*
 ****************************************************************
 * @file           : Timer implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 3 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : timer.c implements a timer of 1 second using
 *                 : SYSCLK=16MHz. Calculate: 
 *                 : Freq = SYSCLK / ((Prescaler-1)(Period-1))
 *                 : Freq = 16MHz / ((1599)(9999)) = 1Hz
 ****************************************************************
 */
#include "timer.h"


void timer2_1hz_init(void)
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

void timer2_1hz_interrupt_init(void)
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
    /*Enable TIM2 interrupt*/
    TIM2->DIER |= TIM_DIER_UIE;
    /*Enable TIM2 interrupt in NVIC*/
    NVIC_EnableIRQ(TIM2_IRQn);
}