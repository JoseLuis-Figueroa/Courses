/*
 ****************************************************************
 * @file           : Interrupt implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 1 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : exti.c implements an external interrupt 
 *                 : using the pc13().
 ****************************************************************
 */
#include "exti.h"


void pc13_exti_init(void)
{
    /*Disable globla interrupts(ARM Cortex)*/
    __disable_irq();
    /*Enable clock access for GPIOC*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    /*Set PC13 as input*/
    GPIOC->MODER &=~(1U<<26);
    GPIOC->MODER &=~(1U<<27); 
    /*Enable clock access to SYSCFG*/
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    /*Select PORTC for EXTI13*/
    SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;
    /*Unmask EXTI13*/
    EXTI->IMR |= EXTI_IMR_MR13;
    /*Select falling edge trigger*/
    EXTI->FTSR |= EXTI_FTSR_TR13;
    /*Enable EXTI13 line in NVIC(ARM Cortex)*/
    NVIC_enableIRQ(EXTI15_10_IRQn);
    /*Enable global interrupts*/
    __enable_irq();
}