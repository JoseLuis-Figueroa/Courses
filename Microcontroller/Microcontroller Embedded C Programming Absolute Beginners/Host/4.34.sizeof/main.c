/*
 ****************************************************************
 * @file           : Sizeof function
 * @author         : Jose Luis Figueroa
 * @Date		   : 23 feb, 2022
 * @board		   : CPU (Standard C)
 * @brief          : It is used to know the size of data type or
 * 				   : variable
 ****************************************************************
 */

#include<stdio.h>

int main(void)
{
	long long mylong = 900;

	/*Using data type*/
	printf("Size of char data type: %d \n", sizeof(char));
	printf("Size of char data type: %d \n", sizeof(short));
	printf("Size of char data type: %d \n", sizeof(int));
	printf("Size of char data type: %d \n", sizeof(long));
	/*Using variable*/
	printf("Size of char data type: %d \n", sizeof(mylong));

	/*To see the execution*/
	getchar();

	return 0;
}
