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
#define CONT            (1U<<1)


/****************************************************************
*Functions
*****************************************************************/
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

void adc_ch18_init(void)
{
    /*Configure the ADC to work with channel 18 
    (temperature sensor)*/
    /*Enable clock access to ADC1*/
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    /*Enable temperature sensor and VREFINT*/
    ADC->CCR |= ADC_CCR_TSVREFE; 
    /*Disable VBATE, as it must be disabled for temp sensor*/
    ADC->CCR &=~ADC_CCR_VBATE;
    /*Set sampling time on 84cycles*/
    ADC1->SMPR1 |= ADC_SMPR1_SMP18_2;
    /*Conversion sequence start. Set the ADC_CH18 (tempeture sensor)
    to start*/
    ADC1->SQR3 |= ADC_SQR3_SQ1_1 | ADC_SQR3_SQ1_4;
    /*Select timer 2 as external event and trigger detection 
    on rising edge*/
    ADC1->CR2 |= ADC_CR2_EXTEN_0 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0;
    /*Enable ADC mode*/
    ADC1->CR2 |= ADC_CR2_ADON;
}

void start_conversion(void)
{
    /*Start adc conversion*/
    ADC1->CR2 |= SWSTART;
}

void start_continuous_conversion(void)
{
    /*Enable continuous conversion*/
    ADC1->CR2 |= CONT;
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