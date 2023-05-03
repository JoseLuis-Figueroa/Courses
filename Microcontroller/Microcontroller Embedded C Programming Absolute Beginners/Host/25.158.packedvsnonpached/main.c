/*
 ****************************************************************
 * @file           : Packed vs non packed
 * @author         : Jose Luis Figueroa
 * @Date		   : 28 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Show the use of packed attribute. Reduce the
 * 				   : memory, but increase the code size and the
 * 				   : processor talks to memory more times.
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Structure definition*/
struct data_set
{
	char data1;
	int data2;
	char data3;
	short data4;
}__attribute__((packed));

struct data_set data; /*This consumes 12 bytes in memory(RAM)*/

int main()
{
	data.data1 = 0xAA;
	data.data2 = 0xFFFFEEEE;
	data.data3 = 0x55;
	data.data4 = 0xA5A5;

	printf("data.data1 = %d\n", data.data1);
	printf("data.data2 = %d\n", data.data2);
	printf("data.data3 = %d\n", data.data3);
	printf("data.data4 = %d\n", data.data4);

	for(;;);
}
