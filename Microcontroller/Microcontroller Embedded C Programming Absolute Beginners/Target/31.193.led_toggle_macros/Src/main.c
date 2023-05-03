/*
 ******************************************************************************
 * @file           : Led toggle with macros
 * @author         : Jose Luis Figueroa
 * @Date		   : 9 May, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Toggle a led using struct to handle the register map.
 ******************************************************************************
 */
#include<stdio.h>
#include<stdint.h>
#include "main.h"

#define PIN_STATE (1)
#define DELAY_COUNT (1000000ul)

int main()
{
    /*Register's address*/
	RCC_AHB1ENR_t *rcc_ahb1enr = ADDR_REG_AHB1ENR;
	GPIOx_MODER_t *gpiox_moder = ADDR_REG_GPIOD_MODE;
	GPIOx_ODR_t *gpiox_odr =   	 ADDR_REG_GPIOD_OD;

    /*Enable the clock for GPIOA in the AHB1ENR*/
    rcc_ahb1enr->gpioaen = CLOCK_ENABLE;

    /*Configure the mode of the IO pin as output*/
    gpiox_moder->moder5 = MODE_CONF_OUTPUT;

    while(1)
    {
        /*Toggle I/O pin 5 (PA5)*/
        gpiox_odr->odr5 ^= PIN_STATE;
        for(uint32_t i=0; i<DELAY_COUNT; i++)
        {
            asm("nop");
        }
    }
}
