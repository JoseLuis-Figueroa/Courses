/*
 ******************************************************************************
 * @file           : Volatile using optimization
 * @author         : Jose Luis Figueroa
 * @Date		   : 23 march, 2022
 * @board		   : Nucleo F401RE
 * @brief          : This code is used to see how volatile works using
 * 				   : optimization (Properties/Settings/Optimization)
 ******************************************************************************
 */

#include <stdint.h>

int main(void)
{
	volatile uint8_t data1;
	volatile uint8_t data2;

	data1 = 50;

	data2 = data1;
	data2 = data1;

	for(;;);
}
