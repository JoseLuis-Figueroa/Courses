/*
 ****************************************************************
 * @file           : UART with DMA
 * @author         : Jose Luis Figueroa
 * @Date		   : 7 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : MCU usart send a message to the PC using DMA
 *                 : generating a interrupt turn on a LED.
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

/*Function prototype*/
static void uart_dma_callback(void);

/******************************************************************************
*Main
******************************************************************************/
int main(void)
{
    /*Variables*/
    char message[31] = "Hello from stm32 DMA transfer\n\r";
    /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	/*Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);
    /*Configure the uart2 tx with DMA*/
    uart2_tx_init();
    dma1_stream6_init((uint32_t)message, (uint32_t)&USART2->DR, 31);
    
    while(1)
    {
        asm("nop");
    }
}


/******************************************************************************
*Functions
******************************************************************************/
static void uart_dma_callback(void)
{
    GPIOA->ODR |= LED_PIN;
}

void DMA1_Stream6_IRQHandler(void)
{
    /*Check for transfer complete interrupt*/
    if(DMA1->HISR & DMA_HISR_TCIF6)
    {
        /*Clear flag*/
        DMA1->HIFCR |= DMA_HIFCR_CTCIF6;
        /*Task*/
        uart_dma_callback();
    }

}