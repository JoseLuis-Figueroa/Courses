/*
 ****************************************************************
 * @file           : uart implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 2 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : uart.c implements an uart protocol 
 *                 : containing all the function implementation.
 ****************************************************************
 */
#include "uart.h"

/****************************************************************
*Functions prototype
*****************************************************************/
static uint16_t compute_uart_bd(uint32_t periphclk,
uint32_t baudrate);
static void uart_set_baudrate(USART_TypeDef *USARTx, 
uint32_t periphclk, uint32_t baudrate);

/****************************************************************
*Functions definition
*****************************************************************/
void uart2_rx_interrupt_init(void)
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
    /*Set PA3 mode to alternate function mode*/
    GPIOA->MODER &=~(1U<<6);
    GPIOA->MODER |= (1U<<7); 
    /*Set PA3 mode to alternate type to UART_RX (AF07)*/
    GPIOA->AFR[0] |= (1U<<12);
    GPIOA->AFR[0] |= (1U<<13);
    GPIOA->AFR[0] |= (1U<<14);
    GPIOA->AFR[0] &=~(1U<<15);

    /********Configure uart module***********/
    /*Enable clock access to uart2*/
    RCC->APB1ENR |= UART2EN;
    /*Configure baudrate*/
    uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);
    /*Enable the transmitter and Reciever.Set 1 start bit, 
    8 data bits, 1 stop bit*/
    USART2->CR1 = (CR1_TE | CR1_RE);
    /*Enable the RXNE interrupt*/
    USART2->CR1 |= RXNEIE;
    /*Enable UART2 interupt in VNIC*/
    NVIC_EnableIRQ(USART2_IRQn);
    /*Enable usart module*/
    USART2->CR1 |= CR1_UE;
}

void uart2_rxtx_init(void)
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
    /*Set PA3 mode to alternate function mode*/
    GPIOA->MODER &=~(1U<<6);
    GPIOA->MODER |= (1U<<7); 
    /*Set PA3 mode to alternate type to UART_RX (AF07)*/
    GPIOA->AFR[0] |= (1U<<12);
    GPIOA->AFR[0] |= (1U<<13);
    GPIOA->AFR[0] |= (1U<<14);
    GPIOA->AFR[0] &=~(1U<<15);

    /********Configure uart module***********/
    /*Enable clock access to uart2*/
    RCC->APB1ENR |= UART2EN;
    /*Configure baudrate*/
    uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);
    /*Enable the transmitter and Reciever.Set 1 start bit, 
    8 data bits, 1 stop bit*/
    USART2->CR1 = (CR1_TE | CR1_RE);
    /*Enable usart module*/
    USART2->CR1 |= CR1_UE;
}

void uart2_tx_init(void)
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
    uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);
    /*Enable the transmitter and set 1 start bit, 8 data bits, 
    1 stop bit*/
    USART2->CR1 = CR1_TE;
    /*Enable usart module*/
    USART2->CR1 |= CR1_UE;
}

char uart2_read(void)
{
    /*Make sure the receive data register is not empty*/
    while(!(USART2->SR & SR_RXNE))
    {
        asm("nop");
    }
    /*Read data*/
    return USART2->DR;
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