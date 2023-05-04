/*
 ****************************************************************
 * @file           : UART Tx
 * @author         : Jose Luis Figueroa
 * @Date		   : 13 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : UART protocol sends a letter (My way)
 ****************************************************************
 */
#include <stdint.h>
#include "stm32f4xx.h"

/****************************************************************
*Definitions
*****************************************************************/
/*bits*/
#define GPIOAEN (1U<<0)
#define UART2EN (1U<<17)

/*UART*/
#define CR1_TE          (1U<<3)
#define CR1_UE          (1U<<13)
#define SR_TXE          (1U<<7)
#define SYS_FREQ        16000000
#define APB1_CLK        SYS_FREQ
#define UART_BAUDRATE   9600

/*functions*/
void uart2_tx_init(USART_TypeDef *USARTx);
void uart2_write(int data);
/****************************************************************
*Main
*****************************************************************/
int main(void)
{
    /*initialize uart*/
    uart2_tx_init(USART2);

    while(1)
    {
        uart2_write('N');
    }
}


/****************************************************************
*Functions
*****************************************************************/
void uart2_tx_init(USART_TypeDef *USARTx)
{
    /********Configure uart gpio pin***********/
    /*Enable clock access to gpioa*/
    RCC->AHB1ENR |= GPIOAEN;
    /*Set PA2 mode to alternate function mode*/
    GPIOA->MODER &=~(1U<<4);
    GPIOA->MODER |= (1U<<5);
    /*Set PA2 alternate function type to UART_TX (AF07)*/
    GPIOA->AFR[0] |= (1U<<8);
    GPIOA->AFR[0] |= (1U<<9);
    GPIOA->AFR[0] |= (1U<<10);
    GPIOA->AFR[0] &=~(1U<<11);

    /********Configure uart module***********/
    /*Enable clock access to uart2*/
    RCC->APB1ENR |= UART2EN;
    /*Configure baudrate*/
    USARTx->BRR = APB1_CLK/UART_BAUDRATE;
    /*Enable the transmitter and set 1 start bit, 8 data bits, 
    1 stop bit*/
    USART2->CR1 = CR1_TE;
    /*Enable usart module*/
    USART2->CR1 |= CR1_UE;
}

void uart2_write(int data)
{
    /*Wait util data is transferred(TXE=1). While condition is 
    running while TXE bit is 0 (false(!)) when TXE bit is 1  the 
    while condition ends*/
    while(!(USART2->SR & SR_TXE))
    {
        asm("nop");
    }
    /*Write to transmit data register*/
    USART2->DR = (data & 0XFF);
    
}
