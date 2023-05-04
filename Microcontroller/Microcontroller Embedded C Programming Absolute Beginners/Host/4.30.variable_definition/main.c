/*
 ****************************************************************
 * @file           : Variable definition
 * @author         : Jose Luis Figueroa
 * @Date		   : 23 feb, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Perform a sum and print it on different
 * 				   : formats
 ****************************************************************
 */

#include<stdio.h>

int main(void)
{
	/*Variable definition*/
	unsigned char distance_ab = 160;
	unsigned char distance_bc = 40;
	unsigned char distance_ac;

	distance_ac = distance_ab + distance_bc;
	/*Print in decimals*/
	printf("Total distance from A to 2: %u \n", distance_ac);
	/*Print in hexadecimal*/
	printf("Total distance from A to 2 in hexadecimal: %x \n", distance_ac);
	/*Print in octal*/
	printf("Total distance from A to 2 in hexadecimal: %o", distance_ac);

	/*To see the execution*/
	getchar();

	return 0;
}
