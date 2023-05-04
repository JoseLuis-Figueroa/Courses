/*
 ******************************************************************************
 * @file           : Pin read volatile
 * @author         : Jose Luis Figueroa
 * @Date		   : 23 march, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Read the button of the board to turn off a LED. Use the
 * 				   : volatile keyword to avoid problems using the optimization
 ******************************************************************************
 */
#include <stdio.h>
#include <stdint.h>

int main()
{
    /*Register's address*/
    /*AHB1EBR*/
	volatile uint32_t *pclkctrlreg =     (uint32_t*)0x40023830;
    /*GPIOA*/
    volatile uint32_t *pportamodereg =   (uint32_t*)0x40020000;
    volatile uint32_t *pportdoutreg =    (uint32_t*)0x40020014;
    /*GPIOC*/
    volatile uint32_t *pportcmodereg =   (uint32_t*)0x40020800;
    volatile uint32_t *pportcinreg =     (uint32_t*)0x40020810;

    /*Enable the clock for GPIOA and GPIOC in the AHB1ENR*/
    *pclkctrlreg |= (1U<<0);
    *pclkctrlreg |= (1U<<2);

    /*Configure the mode of the PA5 pin as output*/
    *pportamodereg |= (1U<<10);
    *pportamodereg &=~(1U<<11);

    /*Configure the mode of the PC13 pin as input*/
    *pportcmodereg &=~(1U<<26);
    *pportcmodereg &=~(1U<<27);

    while(1)
    {
        if(*pportcinreg & (1U<<13))
        {
            /*Turn led on*/
            *pportdoutreg |= (1U<<5);
        }
        else
        {
            /*Turn led off*/
            *pportdoutreg &=~(1U<<5);
        }
    }
}
