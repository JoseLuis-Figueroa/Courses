/*
 ****************************************************************
 * @file           : Pointer data types
 * @author         : Jose Luis Figueroa
 * @Date		   : 3 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : You can use a pointer with different data
 * 				   : type using type-casting. But it is
 * 				   : recommended to use the same data type
 ****************************************************************
 */
#include <stdio.h>

long long int g_data = 0xFFFEABCD11112345;

int main()
{
	/*Use char pointer to handle long long int variable*/
	char *ptr_address1;
	/*Type-casting g_data to char*/
	ptr_address1 = (char*)&g_data;
	printf("value at address %p is: %x\n", ptr_address1, *ptr_address1);

	/*Use int pointer to handle long long int variable*/
	int *ptr_address2;
	ptr_address2 = (int*)&g_data;
	printf("value at address %p is: %x\n", ptr_address2, *ptr_address2);

	/*Use short pointer to handle long long int variable*/
	short *ptr_address3;
	ptr_address3 = (short*)&g_data;
	printf("value at address %p is: %x\n", ptr_address3, *ptr_address3);

	/*Use long long int pointer to handle long long int variable*/
	long long *ptr_address4;
	ptr_address4 = (long long*)&g_data;
	printf("value at address %p is: %I64x\n", ptr_address4, *ptr_address4);

	return 0;
}
