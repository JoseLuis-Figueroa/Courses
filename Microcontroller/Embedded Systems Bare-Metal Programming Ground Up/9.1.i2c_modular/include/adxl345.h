/*
 ****************************************************************
 * @file           : ADXL345 header
 * @author         : Jose Luis Figueroa
 * @Date		   : 13 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : ADXL345 header contains all the prototype 
 *                 : functions used to control the ADXL345
 ****************************************************************
 */
#ifndef ADXL345_H_
#define ADXL345_H_

#include <stdint.h>
#include "stm32f4xx.h"
#include "i2c.h"

/****************************************************************
*Definitions
*****************************************************************/
/*adxl345 registers*/
#define DEVID_R             (0x00)
#define POWER_CTL_R         (0x2D)
#define DATA_FORMAT_R       (0x31)
#define DATA_START_R        (0x32)

/*Constants*/
#define RESET               (0x00)
#define FOUR_G              (0x01)
#define SET_MEASURE         (0x08)
#define DEVICE_ADDR         (0x53)
#define FOUR_G_SCALE_FACTOR (0.0078)

/****************************************************************
*Functions prototype
*****************************************************************/
void adx1_int(void);
void adx1_read_axis(uint8_t reg);

#endif /*ADXL345_H_*/