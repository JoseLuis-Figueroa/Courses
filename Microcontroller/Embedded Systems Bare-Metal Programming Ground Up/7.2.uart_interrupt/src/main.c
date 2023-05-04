/*
 ****************************************************************
 * @file           : UART rx interrupt
 * @author         : Jose Luis Figueroa
 * @Date		   : 1 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : uart receives a data of the PC and turn on a
 *                 : LED using the rx interrupt. 
 ****************************************************************
 */
#include "stdio.h"
#include "uart.h"

/******************************************************************************
*Definitions
******************************************************************************/
/*bits*/
#define PIN5    (1U<<5)
#define LED_PIN PIN5

/*Variables*/
char key;

/*Function Prototype*/
static void uart_callback(void);

/******************************************************************************
*Main
******************************************************************************/
int main(void)
{
    /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	/*Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);
    /*Configure the uart2 rx interrupt*/
    uart2_rx_interrupt_init();
    
    while(1)
    {
        asm("nop");
    }
}


/******************************************************************************
*Functions
******************************************************************************/
static void uart_callback(void)
{
    key = USART2->DR;
    if(key == '1')
    {
        GPIOA->ODR |= LED_PIN;
    }
    else
    {
        GPIOA->ODR &=~LED_PIN;
    }
}

void USART2_IRQHandler(void)
{
    /*Check if RXNE is set*/
    if(USART2->SR & SR_RXNE)
    {
        /*Task*/
        uart_callback();
    }
}
