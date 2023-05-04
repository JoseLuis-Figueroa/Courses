/*
 ****************************************************************
 * @file           : Input compare timer
 * @author         : Jose Luis Figueroa
 * @Date		   : 14 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : The timer 3(PA6) captures the signal produced
 *                 : by timer 2(PA5) a square signal of 1Hz and 
 *                 : save the value. Connect PA6 pin to PA5 pin.
 *                 : Use debug mode to see the behavior.
 ****************************************************************
 */
#include "stdio.h"
#include "timer.h"

volatile uint16_t timestamp = 0;

int main()
{
    /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    /*Configure PA5 as output compare*/
	/*Set PA5 as output pin*/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |= (1U<<11);
    /*Set PA5 alternate function type to TIM2_CH1 (AF1)*/
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL5_0;

    /*Configure PA6 as input capture*/
	/*Set PA6 as output pin*/
	GPIOA->MODER &=~(1U<<12);
	GPIOA->MODER |= (1U<<13);
    /*Set PA6 alternate function type to TIM3_CH1 (AF02)*/
    GPIOA->AFR[0] |= GPIO_AFRL_AFSEL6_1;

    /*Set output compare on timer2. The PA5 is toogled every second,
    this is creating a square signal with a frequency = 1Hz*/
    timer2_output_compare();
    /*Set input compare on timer3. PA6 will capture the PA5 signal*/
    timer3_input_capture();

    while(1)
    {
        /*Wait until input (rising edge) is captured*/
        while(!(TIM3->SR & TIM_SR_CC1IF))
        {
            asm("nop");
        }
        /*Read captured value*/
        timestamp = TIM3->CCR1;
    }
}