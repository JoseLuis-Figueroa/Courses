#include "adc.h"

/****************************************************************
*Definitions
*****************************************************************/
#define GPIOAEN         (1U<<0)

/*ADC bits*/
#define ADC1EN          (1U<<8)
#define ADC_CH1         (1U<<0)     
#define ADC_CH1_LEN0    (1U<<20)   
#define ADC_CH1_LEN1    (1U<<21)
#define ADC_CH1_LEN2    (1U<<22)
#define ADC_CH1_LEN3    (1U<<23)
#define ADON            (1U<<0)
#define SWSTART         (1U<<30)
#define ECO             (1U<<1)



/****************************************************************
*Functions
*****************************************************************/
void adc_ch1_init()
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
    /*Start adc conversion*/
    ADC1->CR2 |= SWSTART;
}

uint32_t adc_read(void)
{
    /*Wait for conversion to be completed*/
    while (!(ADC1->SR & ECO))
    {
        asm("nop");
    }
    return ADC1->DR;
}