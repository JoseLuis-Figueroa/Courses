/*
 ****************************************************************
 * @file           : Address of variables
 * @author         : Jose Luis Figueroa
 * @Date		   : 24 feb, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Print the address of the different variables
 ****************************************************************
 */

#include<stdio.h>

int main(void)
{
	/*Print the address*/
	char character = 'a';
	printf("Address of character variable: %p\n", &character);

	/* Use long long (64bit) because the pointer is of 64 bits
	 * as the machine is of 64 bits. Use type casting.
	*/
	unsigned long long int address = (unsigned long long int)&character;
	/*Print address on hexadecimal*/
	printf("Address of character variable: %llu\n", address);


	return 0;
}


