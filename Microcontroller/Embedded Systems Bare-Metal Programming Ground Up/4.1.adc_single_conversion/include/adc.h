#ifndef ADC_H_
#define ADC_H

#include <stdint.h>
#include "stm32f4xx.h"

/*Functions*/
void adc_ch1_init();
void start_conversion();
uint32_t adc_read();

#endif  /*ADC_H_*/