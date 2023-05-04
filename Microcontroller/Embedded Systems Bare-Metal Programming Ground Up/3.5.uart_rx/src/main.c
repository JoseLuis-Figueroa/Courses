/*
 ****************************************************************
 * @file           : UART RX
 * @author         : Jose Luis Figueroa
 * @Date		   : 17 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : The PC send a caracter and if the caracter
 *                 : is '1' a led is turned on
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"

/****************************************************************
*Definitions
*****************************************************************/
/*Bits*/
#define GPIOAEN     (1U<<0)
#define GPIOA_5     (1U<<5)
/*Pins*/
#define LED_PIN     (GPIOA_5)
/*Variables*/
char key;


/****************************************************************
*Main
*****************************************************************/
int main(void)
{
    /*Enable clock access to GPIOA*/
    RCC->AHB1ENR |= GPIOAEN;
    /*Set PA5 as output pin*/
    GPIOA->MODER |= (1U<<10);
    GPIOA->MODER &=~(1U<<11);

    /*initialize uart*/
    uart2_rxtx_init();

    while(1)
    {
        key = uart2_read();
        if (key == '1')
        {
            GPIOA->ODR |= LED_PIN;
        }
        else
        {
            GPIOA->ODR &= ~LED_PIN;
        }
    }
}