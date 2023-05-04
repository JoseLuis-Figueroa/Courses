/*
 ******************************************************************************
 * @file           : GPIO output
 * @author         : Jose Luis Figueroa
 * @Date		   : 11 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Configure PA5(LED) to toggle using include files
 ******************************************************************************
 */
#include "stm32f4xx.h"

/******************************************************************************
*Definitions
******************************************************************************/
#define GPIOAEN	(1U<<0)

#define PIN5	(1U<<5)
#define LED_PIN	PIN5


/******************************************************************************
*Main
******************************************************************************/
int main (void)
{
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;
	/*Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);
	while(1)
	{
		/*Toggle PA5*/
		GPIOA->ODR ^= LED_PIN;
		for(int i=1; i<1000000; i++)
        {
            asm("nop");
        }

	}
}
