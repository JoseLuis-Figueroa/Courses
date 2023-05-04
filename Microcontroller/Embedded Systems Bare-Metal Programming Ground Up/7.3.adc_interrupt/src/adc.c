/*
 ****************************************************************
 * @file           : ADC implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 2 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : adc.c implements an adc peripherial 
 *                 : containing all the function implementation.
 ****************************************************************
 */
#include "adc.h"

/****************************************************************
*Functions
*****************************************************************/
void adc_ch1_interrupt_init(void)
{
    /*** Configure GPIOA pin to work as ADC ***/
    /*Enable clock access to GPIOA*/
    RCC->AHB1ENR |= GPIOAEN;
    /*Set the mode of PA1 to analog (MODER1[0b11])*/
    GPIOA->MODER |= (1U<<2);
    GPIOA->MODER |= (1U<<3);

    /*** Configure ADC module *****************/
    /*Enable clock access to ADC1*/
    RCC->APB2ENR |= ADC1EN;
    /*Conversion sequence start. Set the ADC_CH1 (PA1) to start*/
    ADC1->SQR3 |= ADC_CH1;
    /*Conversion sequence length. Set the number of conversions in
    the regular channel conversion sequence*/
    ADC1->SQR1 &=~ ADC_CH1_LEN0;
    ADC1->SQR1 &=~ ADC_CH1_LEN1;
    ADC1->SQR1 &=~ ADC_CH1_LEN2;
    ADC1->SQR1 &=~ ADC_CH1_LEN3;
    /*Enable ADC interrupt*/
    ADC1->CR1 |= EOCIE;
    /*Enable ADC interrupt in NVIC*/
    NVIC_EnableIRQ(ADC_IRQn);
    /*Enable ADC mode*/
    ADC1->CR2 |= ADON;
}

void adc_ch1_init(void)
{
    /*** Configure GPIOA pin to work as ADC ***/
    /*Enable clock access to GPIOA*/
    RCC->AHB1ENR |= GPIOAEN;
    /*Set the mode of PA1 to analog (MODER1[0b11])*/
    GPIOA->MODER |= (1U<<2);
    GPIOA->MODER |= (1U<<3);

    /*** Configure ADC module *****************/
    /*Enable clock access to ADC1*/
    RCC->APB2ENR |= ADC1EN;
    /*Conversion sequence start. Set the ADC_CH1 (PA1) to start*/
    ADC1->SQR3 |= ADC_CH1;
    /*Conversion sequence length. Set the number of conversions in
    the regular channel conversion sequence*/
    ADC1->SQR1 &=~ ADC_CH1_LEN0;
    ADC1->SQR1 &=~ ADC_CH1_LEN1;
    ADC1->SQR1 &=~ ADC_CH1_LEN2;
    ADC1->SQR1 &=~ ADC_CH1_LEN3;
    /*Enable ADC mode*/
    ADC1->CR2 |= ADON;
}

void start_conversion(void)
{
    /*Enable continuous conversion*/
    ADC1->CR2 |= CONT;
    /*Start adc conversion*/
    ADC1->CR2 |= SWSTART;
}

uint32_t adc_read(void)
{
    /*Wait for conversion to be completed*/
    while (!(ADC1->SR & EOC))
    {
        asm("nop");
    }
    return ADC1->DR;
}