/*
 ****************************************************************
 * @file           : Interrupt implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 15 sep, 2022
 * @board		   : Nucleo F401RE
 * @brief          : exti.c implements an external interrupt 
 *                 : using the pc13(embedded button) and pc10
 *                 : (external button).
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
    NVIC_EnableIRQ(EXTI15_10_IRQn);
    /*Enable global interrupts*/
    __enable_irq();
}

void pb10_exti_init(void)
{
    /*Disable globla interrupts(ARM Cortex)*/
    __disable_irq();
    /*Enable clock access for GPIOC*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    /*Set PC10 as input*/
    GPIOB->MODER &=~GPIO_MODER_MODER10_0;
    GPIOB->MODER &=~GPIO_MODER_MODER10_1;
    /*Set pull-up registors for PC10*/
    GPIOB->PUPDR &=~GPIO_PUPDR_PUPD10_0;
    GPIOB->PUPDR &=~GPIO_PUPDR_PUPD10_1;
    /*Enable clock access to SYSCFG*/
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    /*Select PORTB for EXT10*/
    SYSCFG->EXTICR[2] |= SYSCFG_EXTICR3_EXTI10_PB;
    /*Unmask EXTI13*/
    EXTI->IMR |= EXTI_IMR_MR10;
    /*Select falling edge trigger*/
    EXTI->FTSR |= EXTI_FTSR_TR10;
    /*Enable EXTI13 line in NVIC(ARM Cortex)*/
    NVIC_EnableIRQ(EXTI15_10_IRQn);
    /*Enable global interrupts*/
    __enable_irq();
}