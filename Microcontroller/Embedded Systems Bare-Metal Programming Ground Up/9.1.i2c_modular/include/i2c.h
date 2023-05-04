/*
 ****************************************************************
 * @file           : I2C header
 * @author         : Jose Luis Figueroa
 * @Date		   : 7 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : I2C header contains all the prototype 
 *                 : functions used to control the I2C
 ****************************************************************
 */
#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>
#include "stm32f4xx.h"

/*Constants*/
#define I2C_100KHZ      (0x50)   /*Decimal = 80*/
#define MAX_RISE_TIME   (0x11)   /*Decimal = 17*/
#define RECOVERY_CLOCKS (0X12)   /*Decimal = 10*/

/*Function prototype*/
void i2c1_init(void);
void i2c1_byte_read(char slave_add, char memory_add, char* data);
void i2c1_burst_read(char slave_add, char memory_add, uint16_t n,
char* data);
void i2c1_burst_write(char slave_add, char memory_add, uint16_t n,
char* data);

#endif /*I2C_H_*/