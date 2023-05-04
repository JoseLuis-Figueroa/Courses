/*
 ****************************************************************
 * @file           : Timer implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 9 sep, 2022
 * @board		   : Nucleo F401RE
 * @brief          : timer.c implements a timer of 1 second using
 *                 : SYSCLK=16MHz. Calculate: 
 *                 : Freq = SYSCLK / ((Prescaler-1)(Period-1))
 *                 : Freq = 16MHz / ((1599)(9999)) = 1Hz.
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


void timer2_output_compare()
{
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


void timer3_input_capture()
{
    /*Enable clock access to GPIOA*/
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    /*Set prescaler*/
    TIM3->PSC = 16000 - 1; 
    /*Ch1 is configured as input mode on timer 3*/
    TIM3->CCMR1 = TIM_CCMR1_CC1S_0;
    /*Capture enabled and set ch1 to capture at rising edge*/
    TIM3->CCER = TIM_CCER_CC1E;
    /*Enable timer 3*/
    TIM3->CR1 |= TIM_CR1_CEN;
}

void timer2_pwm_1()
{
    /*Issac function*/
    /*Enable clock access to timer2*/
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    /*Set prescaler value*/
    TIM2->PSC = 256 - 1;
    /*Set auto-reload value*/
    TIM2->ARR = 62746 - 1;
    /*Enable pwm mode in upcounting*/
    TIM2->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
    /*Set the pin as an output*/
    TIM2->CCER |= TIM_CCER_CC1E;
    /*Set the duty cycle to 50%*/
    TIM2->CCR1 = 31374 - 1;
    /*Clear counter*/
    TIM2->CNT = 0;
    /*Enable timer*/
    TIM2->CR1 |= TIM_CR1_CEN;
}

void timer2_pwm()
{
    /*This routine uses the timer2 to generate a PWM 
    of a period = 1s*/
    /*Enable clock access to timer2*/
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    /*Set prescaler value*/
    TIM2->PSC = 256 - 1;
    /*Set auto-reload value*/
    TIM2->ARR = 62746 - 1;
    /*Enable pwm mode in upcounting*/
    TIM2->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
    /*Set the pin as an output*/
    TIM2->CCER |= TIM_CCER_CC1E;
    /*Configure the ARR register as a buffer*/
    TIM2->CR1 |= TIM_CR1_ARPE;
    /*Set the duty cycle to 50%*/
    TIM2->CCR1 = 31374 - 1;
    /*Clear counter*/
    TIM2->CNT = 0;
    /*Enable timer*/
    TIM2->CR1 |= TIM_CR1_CEN;
}