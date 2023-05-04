/*
 ******************************************************************************
 * @file           : GPIO using bit set/reset register (bsrr)
 * @author         : Jose Luis Figueroa
 * @Date		   : 12 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Toggle PA5 using bsrr
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
		/*Set the PA5 pin (On)*/
		GPIOA->BSRR = (1U<<5);
		for(int i=1; i<100000; i++)
        {
            asm("nop");
        }

		/*Reset the PA5 pin (OFF)*/
		GPIOA->BSRR = (1U<<21);
		for(int i=1; i<100000; i++)
        {
            asm("nop");
        }
        
	}
}
