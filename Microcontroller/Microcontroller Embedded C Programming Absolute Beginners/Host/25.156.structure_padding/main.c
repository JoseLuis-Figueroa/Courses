/*
 ****************************************************************
 * @file           : Structure padding
 * @author         : Jose Luis Figueroa
 * @Date		   : 28 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Explain how structure data is placed in
 * 				   : memory
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
};


int main()
{
	/*Structure initialization*/
	struct data_set data;
	data.data1 = 0x11;
	data.data2 = 0xFFFFEEEE;
	data.data3 = 0x22;
	data.data4 = 0xABCD;

	/*Print the address and data of the structure*/
	uint8_t *ptr;
	ptr = (uint8_t*)&data;
	uint32_t total_size = sizeof(struct data_set);

	printf("Memory address      content\n");
	for(uint8_t i=0; i<=total_size; i++)
	{
		printf("%p ,   %X\n", ptr, *ptr);
		ptr++;
	}

	printf("Total memory consumed by this structure variable = %I64llu\n", sizeof(struct data_set));

	getchar();
}
