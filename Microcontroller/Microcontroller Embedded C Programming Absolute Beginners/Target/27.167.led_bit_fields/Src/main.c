/*
 ******************************************************************************
 * @file           : Led toggle using bit fields
 * @author         : Jose Luis Figueroa
 * @Date		   : 1 april, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Toggle a led using struct to handle the register map.
 ******************************************************************************
 */
#include<stdio.h>
#include<stdint.h>
#include "main.h"


int main()
{
    /*Register's address*/
	RCC_AHB1ENR_t *rcc_ahb1enr = (RCC_AHB1ENR_t*)0x40023830;
	GPIOx_MODER_t *gpiox_moder = (GPIOx_MODER_t*)0x40020000;
	GPIOx_ODR_t *gpiox_odr =   	 (GPIOx_ODR_t*)0x40020014;

    /*Enable the clock for GPIOA in the AHB1ENR*/
    rcc_ahb1enr->gpioaen = 1;

    /*Configure the mode of the IO pin as output*/
    gpiox_moder->moder5 = 1;

    while(1)
    {
        /*Toggle I/O pin 5 (PA5)*/
        gpiox_odr->odr5 ^= 1;
        for(uint32_t i=0; i<1000000; i++)
        {
            asm("nop");
        }
    }
}
