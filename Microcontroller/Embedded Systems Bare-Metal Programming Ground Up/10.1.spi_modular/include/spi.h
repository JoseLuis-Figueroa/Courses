/*
 ****************************************************************
 * @file           : SPI header
 * @author         : Jose Luis Figueroa
 * @Date		   : 8 jul, 2022
 * @board		   : Nucleo F401RE
 * @brief          : SPI header contains all the prototype 
 *                 : functions used to control the SPI
 ****************************************************************
 */
#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>
#include "stm32f4xx.h"

/*Definitions*/
/*Accelerometer pin*/
#define PIN9        (1U<<9)
#define ADXL345_PIN PIN9

/*Function prototype*/
void spi1_gpioa_init(void);
void spi1_config(void);
void spi1_transmit(uint8_t *data, uint32_t size);
void spi1_receive(uint8_t *data, uint32_t size);
void cs_enable(void);
void cs_disable(void);

#endif /*SPI_H_*/