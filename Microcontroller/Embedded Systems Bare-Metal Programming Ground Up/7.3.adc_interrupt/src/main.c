/*
 ****************************************************************
 * @file           : ADC interrupt
 * @author         : Jose Luis Figueroa
 * @Date		   : 2 Jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : ADC interrupt is configured to use the 
 *                 : channel 1(PA1), 12 bits, single channel and 
 *                 : continuous convertion. 
 *                 : Debug to test the code reviewing sensor 
 *                 : value
 ****************************************************************
 */
#include "adc.h"

/*Varibles*/
volatile uint32_t sensor_value = 0;

/*Function prototype*/
static void adc_callback(void);

/****************************************************************
*Main
*****************************************************************/
int main()
{
    /*Initialize the ADC interrupt using channel 1(PA1), single
     channel*/
    adc_ch1_interrupt_init();
    /*Start conversion and continuous conversion*/
    start_conversion();

    while(1)
    {
        asm("nop");
    }

}


/****************************************************************
*Functions
*****************************************************************/
static void adc_callback(void)
{
    /*Read ADC value*/
    sensor_value = ADC1->DR;
}

void ADC_IRQHandler(void)
{
    /*Check for eoc in SR*/
    if (ADC1->SR & EOC)
    {
        /*Read ADC value*/
        adc_callback();
    }
}