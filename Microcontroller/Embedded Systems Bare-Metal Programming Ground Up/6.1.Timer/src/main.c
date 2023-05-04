/*
 ****************************************************************
 * @file           : Timer
 * @author         : Jose Luis Figueroa
 * @Date		   : 10 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Toggle a led each second using the timer 2.
 *                 : Use the interrupt flag to wait until the
 *                 : count finishes
 ****************************************************************
 */
#include "stdio.h"
#include "timer.h" 

/******************************************************************************
*Definitions
******************************************************************************/
#define GPIOAEN	(1U<<0)

#define PIN5	(1U<<5)
#define LED_PIN	PIN5

int main()
{
    /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;
	/*Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);

    /*Initialize timer2*/
    timer2_1hz_init();

    while(1)
    {
        /*Wait for interrupt flag*/
        while(!(TIM2->SR & TIM_SR_UIF))
        {
            asm("nop");

        }
        /*Crear UIF*/
        TIM2->SR &=~TIM_SR_UIF;
        /*Toggle led*/
        GPIOA->ODR ^= LED_PIN;
        
    }
}