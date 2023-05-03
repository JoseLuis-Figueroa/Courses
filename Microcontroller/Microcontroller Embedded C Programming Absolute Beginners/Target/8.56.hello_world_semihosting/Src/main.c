/*
 ******************************************************************************
 * @file           : Hello world semihosting
 * @author         : Jose Luis Figueroa
 * @Date		   : 28 feb, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Use OpenOCD to debug an ARM-cortem M0/M0+.
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

extern void initialise_monitor_handles(void);

int main(void)
{
	initialise_monitor_handles();

	printf("Hello world\n");
    /* Loop forever */
	for(;;);
}
