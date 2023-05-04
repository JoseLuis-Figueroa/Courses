/*
 ****************************************************************
 * @file           : Passing array to a function
 * @author         : Jose Luis Figueroa
 * @Date		   : 11 Apr, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Pass an array as a argument to a function
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

void array_display(uint8_t const *const ptr_array, uint32_t size);


int main(void)
{
	uint8_t some_data[10] = {0x0f,0xff,0x0f,0xff,0xff,0xff,0xff,
			0xff,0xff,0xff};

	for(uint32_t i=0;i<10;i++)
	{
		some_data[i] = 0x33;
	}

	uint32_t size = sizeof(some_data) / sizeof(uint8_t);
	array_display(some_data,size);

	return 0;
}


void array_display(uint8_t const *const ptr_array, uint32_t size)
{
	for(uint8_t i=0; i<size; i++)
	{
		printf("%x\t",ptr_array[i]);
	}
}
