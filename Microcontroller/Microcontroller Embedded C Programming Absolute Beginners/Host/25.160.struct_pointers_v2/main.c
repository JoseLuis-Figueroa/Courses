/*
 ****************************************************************
 * @file           : Structure and pointers
 * @author         : Jose Luis Figueroa
 * @Date		   : 29 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Pointer are used on structure so that the
 * 				   : members can be used on another function or
 * 				   : files. For example the stm32 registers.
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


void display_members(struct data_set *ptr_data);


int main(void)
{
	/*Create struct variable and initialize all the members*/
	struct data_set data;
	data.data1 = 0x11;
	data.data2 = 0xFFFFEEEE;
	data.data3 = 0x22;
	data.data4 = 0xABCD;
	printf("Before pointer: data.data1 = %x\n", data.data1);

	display_members(&data);

	getchar();

	return 0;
}


void display_members(struct data_set *ptr_data)
{
	/*Create a structure type pointer*/
	ptr_data->data1 = 0x50;
	printf("data.data1 = %x\n", ptr_data->data1);
	printf("data.data2 = %x\n", ptr_data->data2);
	printf("data.data3 = %x\n", ptr_data->data3);
	printf("data.data4 = %x\n", ptr_data->data4);

}
