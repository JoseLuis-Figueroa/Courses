/*
 ******************************************************************************
 * @file           : Add
 * @author         : Jose Luis Figueroa
 * @Date		   : 1 Mar, 2022
 * @board		   : Nucleo F401RE
 * @brief          : This code was used to review the memory of the code called
 * 				   : flash (0x08000000) and the memory where the variable are
 * 				   : saved SRAM or RAM (0x20000000). Besides, we analyzed the
 * 				   : .elf file (debug file) and all the files created  during
 * 				   : the debug process.
 ******************************************************************************
 */
#include <stdint.h>
#include <stdio.h>

/*Global variable*/
int g_data1 = -4000;
int g_data2 = 200;
int result = 0;


int main(void)
{
	result = g_data1 + g_data2;
	printf("Result = %d\n", result);

    /* Loop forever */
	for(;;);
}
