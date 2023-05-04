/*
 ****************************************************************
 * @file           : UART string
 * @author         : Jose Luis Figueroa
 * @Date		   : 13 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : UART send a line of text
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

/*Varibles*/
char message[] = {"Hello from STM32F4\n\r"};

/*functions*/
void uart2_tx_init(void);
void uart2_write(int data);
static void uart_set_baudrate(USART_TypeDef *USARTx, 
uint32_t periphclk, uint32_t baudrate);
static uint16_t compute_uart_bd(uint32_t periphclk, 
uint32_t baudrate);

/****************************************************************
*Main
*****************************************************************/
int main(void)
{
    /*initialize uart*/
    uart2_tx_init();
    while(1)
    {
        /*Send character by character to UART port
        -1 is to remove the null value*/
        for(int i=0; i<sizeof(message)-1; i++)
        {
            uart2_write(message[i]);
        }
    }
}


/****************************************************************
*Functions
*****************************************************************/
void uart2_tx_init()
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
    uart_set_baudrate(USART2, SYS_FREQ, UART_BAUDRATE);
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

static void uart_set_baudrate(USART_TypeDef *USARTx, 
uint32_t periphclk, uint32_t baudrate)
{
    USARTx->BRR = compute_uart_bd(periphclk, baudrate);
}

static uint16_t compute_uart_bd(uint32_t periphclk, 
uint32_t baudrate)
{
    /*Formula to get USARTDIV*/
    return ((periphclk + (baudrate/2U))/baudrate);
}