/*
 ****************************************************************
 * @file           : Structure and pointers
 * @author         : Jose Luis Figueroa
 * @Date		   : 29 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Pointer and structure are used together
 ****************************************************************
 */
#include<stdio.h>
#include<stdint.h>


struct data_set
{
	char data1;
	int data2;
	char data3;
	short data4;
};


int main(void)
{
	/*Create struct variable and initialize all the members*/
	struct data_set data;
	data.data1 = 0x11;
	data.data2 = 0xFFFFEEEE;
	data.data3 = 0x22;
	data.data4 = 0xABCD;
	printf("Before pointer: data.data1 = %x\n", data.data1);

	/*Create a structure type pointer*/
	struct data_set *ptr_data;
	ptr_data = &data;
	ptr_data->data1 = 0x50;
	printf("data.data1 = %x\n", data.data1);
	printf("ptr_data->data1 = %x\n", ptr_data->data1);

	getchar();

	return 0;
}


