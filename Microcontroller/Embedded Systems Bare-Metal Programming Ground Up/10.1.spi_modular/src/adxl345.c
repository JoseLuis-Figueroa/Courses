/*
 ****************************************************************
 * @file           : ADXL345 implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 10 Aug, 2022
 * @board		   : Nucleo F401RE
 * @brief          : ADXL345 is implemented using SPI protocol 
 *                 : containing all the function implementation.
 ****************************************************************
*/
#include "adxl345.h"

/****************************************************************
*Definitions
*****************************************************************/
/*Variables*/
char data;

/*Function Prototype*/
static void adx1_write(uint8_t address, char value);

/****************************************************************
*Standard functions
*****************************************************************/
void adx1_int(void)
{
    /*Enable SPI gpio*/
    spi1_gpioa_init();
    /*Enable SPI protocol*/
    spi1_config();
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
void adx1_read(uint8_t address, uint8_t *rxdata)
{
    /*Set read operation*/
    address |= READ_OPERATION;
    /*Enable multi-byte*/
    address |= MULTI_BYTE_EN;
    /*Pull cs line low to enable slave*/
    cs_enable();
    /*Send the address*/
    spi1_transmit(&address, 1);
    /*Read 6 bytes*/
    spi1_receive(rxdata, 6);
    /*Pull cs line high to disable slave*/
    cs_disable();
}

/****************************************************************
*Write Functions
*****************************************************************/
static void adx1_write(uint8_t address, char value)
{
    /*Local buffer*/
    uint8_t data[2];
    /*Enable multi-byte, place address into buffer*/
    data[0] = address | MULTI_BYTE_EN;
    /*Place the data into buffer*/
    data[1] = value;
    /*Pull cs line low to enable slave*/
    cs_enable();
    /*Transmit data and address*/
    spi1_transmit(data, 2);
    /*Pull cs line high to disable slave*/
    cs_disable();
}