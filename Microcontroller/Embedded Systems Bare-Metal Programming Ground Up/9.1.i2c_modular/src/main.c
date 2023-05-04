/*
 ****************************************************************
 * @file           : Accelerometer (ADXL345)
 * @author         : Jose Luis Figueroa
 * @Date		   : 13 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Control acceleromete using the I2C protocol.
 *                 : PB9 => SDA and PB8 => SCL.
 ****************************************************************
 */
#include <stdio.h>
#include "adxl345.h"

/*Variables*/
int16_t x, y, z;
float xg, yg, zg;
extern uint8_t data_axis[6];

int main(void)
{
    /*Initialize accelerometer*/
    adx1_int();

    while (1)
    {
        /*Read the axis values*/
        adx1_read_axis(DATA_START_R);
        /*Get x. Order the bytes (x1 and x0) on one 16 bits 
        variable*/
        x = ((data_axis[1]<<8) | data_axis[0]);
        y = ((data_axis[3]<<8) | data_axis[2]);
        z = ((data_axis[5]<<8) | data_axis[4]);
        /*Multiply for four g scale factor*/
        xg = (x * 0.0078);
        yg = (y * 0.0078);
        zg = (z * 0.0078);
    }

}