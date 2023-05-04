/*
 ****************************************************************
 * @file           : External interrupt
 * @author         : Jose Luis Figueroa
 * @Date		   : 1 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : 
 *                 :  
 ****************************************************************
 */
#include "stdio.h"
#include "exti.h"
#include "uart.h"

/******************************************************************************
*Definitions
******************************************************************************/
/*bits*/
#define PIN5	(1U<<5)
#define LED_PIN	PIN5

/*Varibles*/
char message[] = {"Pressed button\n\r"};

/*Function*/
static void exti_callback(void);

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
    /*Initialize external interrupt*/
    pc13_exti_init();
    uart2_tx_init();

    while(1)
    {
        asm("nop");
    }
}


/******************************************************************************
*Functions
******************************************************************************/

static void exti_callback(void)
{
    /*Send character by character to UART port-1 is to remove the null value*/
    for(int i=0; i<sizeof(message)-1; i++)
    {
        uart2_write(message[i]);
    }
    /*Toogle the embedded LED*/
    GPIOA->ODR ^= LED_PIN;
}

void EXTI15_10_IRQHandler(void)
{
    if(EXTI->PR & EXTI_PR_PR13)
    {
        /*Clear PR flag*/
        EXTI->PR |= EXTI_PR_PR13;
        /*Send message to PC*/
        exti_callback();
    }

}