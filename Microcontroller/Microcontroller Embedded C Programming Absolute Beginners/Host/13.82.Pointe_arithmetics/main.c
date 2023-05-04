/*
 ****************************************************************
 * @file           : Pointer data types arithmetics
 * @author         : Jose Luis Figueroa
 * @Date		   : 9 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : The pointer is increased according to the
 * 				   : data type.
 ****************************************************************
 */
#include <stdio.h>

long long int g_data = 0xFFFEABCD11112345;

int main ()
{
	/*Create a char pointer*/
	char *ptr_address = (char*)&g_data;
	printf("Value of ptr_address %p\n",ptr_address);
	printf("Value at address %p is %x\n", ptr_address, *ptr_address);

	/*Increases the pointer by 1*/
	ptr_address++;
	printf("Value of ptr_address %p\n",ptr_address);
	printf("Value at address %p is %x\n\n", ptr_address, *ptr_address);


	/*Create a short pointer*/
	short *ptr_address2 = (short*)&g_data;
	printf("Value of ptr_address %p\n",ptr_address2);
	printf("Value at address %p is %x\n", ptr_address2, *ptr_address2);

	/*Increases the pointer by 2. The increment depends on the type
	 *of variable
	 */
	ptr_address2++;
	printf("Value of ptr_address %p\n",ptr_address2);
	printf("Value at address %p is %x\n\n", ptr_address2, *ptr_address2);


	/*Create a int pointer*/
	int *ptr_address3 = (int*)&g_data;
	printf("Value of ptr_address %p\n",ptr_address3);
	printf("Value at address %p is %x\n", ptr_address3, *ptr_address3);

	/*Increases the pointer by 4. The increment depends on the type
	 *of variable
	 */
	ptr_address3++;
	printf("Value of ptr_address %p\n",ptr_address3);
	printf("Value at address %p is %x\n", ptr_address3, *ptr_address3);


}
