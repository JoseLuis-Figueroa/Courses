/*
 ****************************************************************
 * @file           : System Tick Timer implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 3 Jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : systick.c implements different delays using
 *                 : SYSCLK=16MHz. Calculate N: N=Delay/SYSCKL
 *                 : => N=Delay*SYSCLK
 *                 : Systick was configured using the user guide 
 *                 : for ARM (DUI0553A) and System Tick Timer 
 *                 : notes to calculate N
 ****************************************************************
 */
#include "systick.h"

/****************************************************************
*Delays
*****************************************************************/
void systick_delayms(uint16_t delay)
{
    /*Implements a timer of 1 ms. Calculate N: N=Delay/SYSCKL=>
    N=Delay*SYSCLK=0.001*16M = 16000 cycles.*/

    /*Reload with number of clocks per millisecond(1ms). This is 
    where the initial count value is placed.
    SYST_RVR(N)*/
    SysTick->LOAD = MILLI_SECOND_VAL;
    /*Clear systick current value register. It cointains the 
    current count value.
    SYST_CVR*/
    SysTick->VAL = 0;
    /*Enable systick and select internal clksrc
    SYST_CSR*/
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
    for(int i=0; i<delay; i++)
    {
        /*Wait until the COUNTFLAG is set*/
        while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0)
        {
            asm("nop");
        }
    }
    SysTick->CTRL = 0;
}