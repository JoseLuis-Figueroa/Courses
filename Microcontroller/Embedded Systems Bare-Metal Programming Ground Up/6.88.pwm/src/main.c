/*
 ****************************************************************
 * @file           : pulse width modulation (pwm)
 * @author         : Jose Luis Figueroa
 * @Date		   : 9 sep, 2022
 * @board		   : Nucleo F401RE
 * @brief          : The timer 2(PA5) is configured as pwm mode.
 *                 :  
 ****************************************************************
 */
#include "stdio.h"
#include "timer.h"

int main(void)
{
    /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    /*Configure PA5 as pwm mode*/
	/*Set PA5 as output pin*/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |= (1U<<11);
    /*Set PA5 alternate function type to TIM2_CH1 (AF1)*/
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL5_0;

    /*Set output compare on timer2*/
    timer2_pwm();

    while(1)
    {
        asm("nop");
    }
}