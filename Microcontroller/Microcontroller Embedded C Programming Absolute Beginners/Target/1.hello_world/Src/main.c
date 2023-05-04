/*
 ******************************************************************************
 * @file           : Hello world
 * @author         : Jose Luis Figueroa
 * @Date		   : 28 feb, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Use the SWD protocol to print the message on the ITM data
 * 				   : console. It didn't work on my pc
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>


int main(void)
{
	printf("Hello world");
    /* Loop forever */
	for(;;);
}
