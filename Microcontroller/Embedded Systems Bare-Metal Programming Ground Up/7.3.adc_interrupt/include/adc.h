/*
 ****************************************************************
 * @file           : ADC header
 * @author         : Jose Luis Figueroa
 * @Date		   : 2 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : ADC header contains all the prototype 
 *                 : functions used to control the ADC
 ****************************************************************
 */
#ifndef ADC_H_
#define ADC_H

#include <stdint.h>
#include "stm32f4xx.h"

/*Functions*/
void adc_ch1_interrupt_init(void);
void adc_ch1_init(void);
void start_conversion(void);
uint32_t adc_read(void);

/*RCC bits*/
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
#define EOC             (1U<<1)
#define CONT            (1U<<1)
#define EOCIE           (1U<<5)

#endif  /*ADC_H_*/