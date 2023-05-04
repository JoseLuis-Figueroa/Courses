/*
 ****************************************************************
 * @file           : ADC continuous channel
 * @author         : Jose Luis Figueroa
 * @Date		   : 28 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : ADC is configured to use the channel 1(PA1),
 *                 : 12 bits, single channel and convertion. 
 *                 : Debug to test the code reviewing sensor 
 *                 : value
 ****************************************************************
 */
#include "adc.h"

/*Varibles*/
uint32_t sensor_value;

int main()
{
    /*Initialize the channel 1(PA1) of ADC1, single channel*/
    adc_ch1_init();
    /*Start conversion and continuous conversion*/
    start_conversion();

    while(1)
    {
        /*Read ADC value*/
        sensor_value = adc_read();
    }

}