/*
 ****************************************************************
 * @file           : Typedef
 * @author         : Jose Luis Figueroa
 * @Date		   : 29 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Use typedef in a structure
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Structure definition*/
typedef struct
{
	char data1;
	int data2;
	char data3;
	short data4;
}Data_t;

Data_t data; /*This consumes 12 bytes in memory(RAM)*/

int main(void)
{
	data.data1 = 0xAA;
	data.data2 = 0xFFFFEEEE;
	data.data3 = 0x55;
	data.data4 = 0xA5A5;

	printf("data.data1 = %d\n", data.data1);
	printf("data.data2 = %d\n", data.data2);
	printf("data.data3 = %d\n", data.data3);
	printf("data.data4 = %d\n", data.data4);

	getchar();
}
