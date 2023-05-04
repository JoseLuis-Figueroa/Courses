/*
 ****************************************************************
 * @file           : External interrupt
 * @author         : Jose Luis Figueroa
 * @Date		   : 15 sep, 2022
 * @board		   : Nucleo F401RE
 * @brief          : The external interrupts of pc13 pin (embedded
 *                 : button) and pc10(external button) are used to
 *                 : toogle the pa5 (embedded Led).
 ****************************************************************
 */
#include "stdio.h"
#include "exti.h"
#include "systick.h"

/******************************************************************************
*Definitions
******************************************************************************/
/*bits*/
#define PIN5	(1U<<5)
#define LED_PIN	PIN5

/*Function*/
static void exti_pc13_callback(void);
static void exti_pb10_callback(void);

int main(void)
{
    /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	/*Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);
    /*Initialize external interrupts*/
    pc13_exti_init();
    pb10_exti_init();

    while(1)
    {
        asm("nop");
    }

}


/******************************************************************************
*Functions
******************************************************************************/
static void exti_pc13_callback(void)
{
    /*Toogle the LED one times*/
    for(int i=0; i<2; i++)
    {
        systick_delayms(1000);
        /*Toogle the embedded LED*/
        GPIOA->ODR ^= LED_PIN;
    }
    
}

static void exti_pb10_callback(void)
{
    /*Toogle the LED two times*/
    for(int i=0; i<4; i++)
    {
        systick_delayms(1000);
        /*Toogle the embedded LED*/
        GPIOA->ODR ^= LED_PIN;
    }
}


void EXTI15_10_IRQHandler(void)
{
    if(EXTI->PR & EXTI_PR_PR13)
    {
        /*Clear PR flag*/
        EXTI->PR |= EXTI_PR_PR13;
        /*Callback function*/
        exti_pc13_callback();
    }
    else if(EXTI->PR & EXTI_PR_PR10)
    {
        /*Clear PR flag*/
        EXTI->PR |= EXTI_PR_PR10;
        /*Callback function*/
        exti_pb10_callback();
    }
}