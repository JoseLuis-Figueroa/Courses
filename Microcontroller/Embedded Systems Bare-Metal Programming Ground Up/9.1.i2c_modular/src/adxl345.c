/*
 ****************************************************************
 * @file           : ADXL345 implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 13 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : ADXL345 implements an I2C protocol containing
 *                 : all the function implementation.
 ****************************************************************
*/
#include "adxl345.h"

/****************************************************************
*Definitions
*****************************************************************/
/*Variables*/
char data;
volatile uint8_t data_axis[6];

/*Function Prototype*/
static void adxl_read_address(uint8_t reg);
static void adx1_write(uint8_t reg, char value);

/****************************************************************
*Standard functions
*****************************************************************/
void adx1_int(void)
{
    /*Enable I2C protocol*/
    i2c1_init();
    /*Read the DEVID = 0xE5. To ensure that it works*/
    adxl_read_address(DEVID_R);
    /*Set data format range to +-4g*/
    adx1_write(DATA_FORMAT_R, FOUR_G);
    /*Reset all bits*/
    adx1_write(POWER_CTL_R, RESET);
    /*configure power control measure bit*/
    adx1_write(POWER_CTL_R, SET_MEASURE);
}

/****************************************************************
*Read Functions
*****************************************************************/
void adx1_read_axis(uint8_t reg)
{
    /*Read the Axis data*/
    i2c1_burst_read(DEVICE_ADDR, reg, 6, (char *)data_axis);
}

static void adxl_read_address(uint8_t reg)
{
    /*Read the device address (one byte)*/
    i2c1_byte_read(DEVICE_ADDR, reg, &data);
}

/****************************************************************
*Write Functions
*****************************************************************/
static void adx1_write(uint8_t reg, char value)
{
    /*Local buffer*/
    char data[1];
    data[0] = value;

    i2c1_burst_write(DEVICE_ADDR, reg, 1, data);
}