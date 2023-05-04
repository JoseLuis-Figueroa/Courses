/*
 ****************************************************************
 * @file           : Timer
 * @author         : Jose Luis Figueroa
 * @Date		   : 3 Jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Toggle a led each second using the timer 2.
 *                 : Use the interrupt flag to wait until the
 *                 : count finishes
 ****************************************************************
 */
#include "stdio.h"
#include "timer.h" 

/****************************************************************
*Definitions
****************************************************************/
#define GPIOAEN	(1U<<0)

/*Pins*/
#define PIN5	(1U<<5)
#define LED_PIN	PIN5

/*Function*/
static void tim2_callback(void);

/****************************************************************
*Main
****************************************************************/
int main()
{
    /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	/*Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);

    /*Initialize timer2*/
    timer2_1hz_interrupt_init();

    while(1)
    {
        asm("nop");
    }
}

/***************************************************************
*Functions implementation
***************************************************************/
static void tim2_callback(void)
{
    /*Crear UIF*/
    TIM2->SR &=~TIM_SR_UIF;
    /*Toggle led*/
    GPIOA->ODR ^= LED_PIN;
}

void TIM2_IRQHandler(void)
{
    if(TIM2->SR & TIM_SR_UIF)
    {
        tim2_callback();
    }

}