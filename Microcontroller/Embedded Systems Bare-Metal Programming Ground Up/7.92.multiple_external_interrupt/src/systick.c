/*
 ****************************************************************
 * @file           : System Tick Timer implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 1 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : systick.c implements a timer of 1ms using
 *                 : SYSCLK=16MHz. Calculate N: N=Delay/SYSCKL=>
 *                 : N=Delay*SYSCLK=0.001*16M = 16000 cycles.
 *                 : Systick was configured using the user guide 
 *                 : for ARM (DUI0553A) and System Tick Timer 
 *                 : notes to calculate N
 ****************************************************************
 */
#include "systick.h"

/****************************************************************
*Definitions
*****************************************************************/
/*Constants*/
#define SYSTICK_LOAD_VAL    16000

/*Systick bits*/
/*SYST_CSR*/
#define ENABLE         (1U<<0)
#define CLKSRC         (1U<<2)
#define COUNTFLAG      (1U<<16)

/****************************************************************
*Functions
*****************************************************************/
void systick_delayms(uint16_t delay)
{
    /*Reload with number of clocks per millisecond. This is where
    the initial count value is placed.
    SYST_RVR(N)*/
    SysTick->LOAD = SYSTICK_LOAD_VAL;

    /*Clear systick current value register. It cointains the 
    current count value.
    SYST_CVR*/
    SysTick->VAL = 0;

    /*Enable systick and select internal clksrc
    SYST_CSR*/
    SysTick->CTRL |= ENABLE | CLKSRC;

    for(int i=0; i<delay; i++)
    {
        /*Wait until the COUNTFLAG is set*/
        while((SysTick->CTRL & COUNTFLAG) == 0)
        {
            asm("nop");
        }
    }

    SysTick->CTRL = 0;
}