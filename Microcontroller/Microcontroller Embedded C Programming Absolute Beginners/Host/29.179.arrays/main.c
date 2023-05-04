/*
 ****************************************************************
 * @file           : Array
 * @author         : Jose Luis Figueroa
 * @Date		   : 31 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Read and write on an array
 ****************************************************************
 */
#include<stdio.h>
#include<stdint.h>

int main(void)
{
	uint8_t some_data[10] = {0x0f,0xff,0x0f,0xff,0xff,0xff,0xff,
			0xff,0xff,0xff};
	/*Print size of the array*/
	printf("Size of an array = %llu\n",sizeof(some_data));

	/*Show how write and read on an array*/
	printf("Before: 2nd data item = %x\n",*(some_data+1));
	printf("Before: 2nd data item = %x\n",some_data[1]);

	*(some_data+1) = 0x9;

	printf("Before: 2nd data item = %x\n",*(some_data+1));
	printf("Before: 2nd data item = %x\n",some_data[1]);

	printf("\nContents of this array\n");
	for(uint8_t i=0; i<=9; i++)
	{
		printf("Array value %d: %x\n", i, some_data[i]);
	}

	return 0;
}
