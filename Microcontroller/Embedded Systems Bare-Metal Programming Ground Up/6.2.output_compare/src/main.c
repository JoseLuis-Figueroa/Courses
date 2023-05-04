/*
 ****************************************************************
 * @file           : Output compare timer
 * @author         : Jose Luis Figueroa
 * @Date		   : 11 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Toggle a embedded led (PA5) each second 
 *                 : using the output compare timer 2, channel 1. 
 ****************************************************************
 */
#include "stdio.h"
#include "timer.h" 

int main()
{
    /*Initialize timer2*/
    timer2_pa5_output_compare();

    while(1)
    {
        /*Super loop*/
    }
}