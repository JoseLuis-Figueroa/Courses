/*
 ****************************************************************
 * @file           : Unions
 * @author         : Jose Luis Figueroa
 * @Date		   : 31 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Implement a union to see its behavior
 ****************************************************************
 */
#include<stdio.h>
#include<stdint.h>


union address
{
	uint16_t short_addr;
	uint32_t long_addr;
};


int main(void)
{
	union address addr;

	addr.short_addr = 0xAAFF;
	addr.long_addr = 0xAAAAFFFF;

	printf("Short addr = %#x\n", addr.short_addr);
	printf("Long addr = %#x\n", addr.long_addr);

	getchar();

	return 0;
}
