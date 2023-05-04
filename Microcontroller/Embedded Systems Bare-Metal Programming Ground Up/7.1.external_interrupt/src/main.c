/*
 ****************************************************************
 * @file           : External interrupt
 * @author         : Jose Luis Figueroa
 * @Date		   : 1 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : The external interrupt of pc13 pin (embedded
 *                 : button) is used to toogle the pa5 (embedded 
 *                 : Led).
 ****************************************************************
 */
#include "stdio.h"
#include "exti.h"

/******************************************************************************
*Definitions
******************************************************************************/
/*bits*/
#define PIN5	(1U<<5)
#define LED_PIN	PIN5

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
    /*Toogle the embedded LED*/
    GPIOA->ODR ^= LED_PIN;
}

void EXTI15_10_IRQHandler(void)
{
    if(EXTI->PR & EXTI_PR_PR13)
    {
        /*Clear PR flag*/
        EXTI->PR |= EXTI_PR_PR13;
        /*Callback function*/
        exti_callback();
    }

}