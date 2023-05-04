/*
 ****************************************************************
 * @file           : Systick interrupt
 * @author         : Jose Luis Figueroa
 * @Date		   : 3 Jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : System tick timer implements a timer that  
 *                 : counts per second using an interrupt. A
 *                 : led is toogled and a message is sent to the
 *                 : PC (uart).
 ****************************************************************
 */
#include <stdio.h>
#include "systick.h"
#include "uart.h"

/****************************************************************
*Definitions
*****************************************************************/
#define GPIOAEN	(1U<<0)

#define PIN5	(1U<<5)
#define LED_PIN	PIN5

/*Varibles*/
char message[] = {"Second\n\r"};

/*Function prototype*/
static void systick_callback(void);

/****************************************************************
*Main
*****************************************************************/
int main()
{
    /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;
	/*Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);
    /*Set up systick as interrupt*/
    systick_delay_interrupt();
    /*Initialize the uart tx*/
    uart2_tx_init();
    
    while(1)
    {
        asm("nop");
    }
}

/****************************************************************
*Function implementation
*****************************************************************/
static void systick_callback(void)
{
    GPIOA->ODR ^= LED_PIN;
    /*Send character by character to UART port
    -1 is to remove the null value*/
    for(int i=0; i<sizeof(message)-1; i++)
    {
        uart2_write(message[i]);
    }
}

void SysTick_Handler(void)
{
    systick_callback();
}
