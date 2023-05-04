/*
 ****************************************************************
 * @file           : System Tick Timer
 * @author         : Jose Luis Figueroa
 * @Date		   : 3 Jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Create a function usign the system tick 
 *                 : timer to implementa timer that counts per  
 *                 : 1ms. Provide the number of ms to count.
 ****************************************************************
 */
#include <stdio.h>
#include "systick.h"

/****************************************************************
*Definitions
*****************************************************************/
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

    while(1)
    {
        GPIOA->ODR ^= LED_PIN;
        systick_delayms(5000);
    }
}