/*
 ****************************************************************
 * @file           : ADC CPU temperature
 * @author         : Jose Luis Figueroa
 * @Date		   : 23 sep, 2022
 * @board		   : Nucleo F401RE
 * @brief          : ADC is configured to use the channel 18 
 *                 : (temperature sensor) and output compara 
 *                 : timer 2 is configured with a period of 1 sec
 *                 : and used as external event to enable the ADC 
 *                 : Note: printf function does not work on VSC
 ****************************************************************
 */
#include "adc.h"
#include "timer.h"
#include "uart.h"

volatile uint16_t data;
volatile double voltage;
volatile double celsius;

/*Function to use printf*/
int __io_putchar(int ch)
{
    uart2_write(ch);
    return ch;
}

int main(void)
{
    /*Set timer 2 as output compare 2*/
    timer2_output_compare_2();
    /*Initialize the channel 18(temperature sensor)) of ADC1*/
    adc_ch18_init();
    /*Set the uart2 as a tx*/
    uart2_tx_init();

    while(1)
    {
        while((ADC1->SR & ADC_SR_EOC))
        {
            data = ADC1->DR;
            voltage = (double)data / 4095 * 3.3;
            celsius = (voltage - 0.76) / 0.0025+25;
            printf("%d, %.2f\370C\r\n", data, celsius);
        }
    }
}