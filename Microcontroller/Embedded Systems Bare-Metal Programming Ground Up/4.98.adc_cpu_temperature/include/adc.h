#ifndef ADC_H_
#define ADC_H

#include <stdint.h>
#include "stm32f4xx.h"

/*Functions*/
void adc_ch1_init();
void adc_ch18_init();
void start_conversion();
void start_continuous_conversion();
uint32_t adc_read();

#endif  /*ADC_H_*/