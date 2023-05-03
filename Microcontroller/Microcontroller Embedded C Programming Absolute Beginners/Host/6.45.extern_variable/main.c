/*
 ****************************************************************
 * @file           : Extern with variables
 * @author         : Jose Luis Figueroa
 * @Date		   : 25 feb, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Extern keyword is used to use private_data
 * 				   : (global variable) out of main.c
 ****************************************************************
 */
#include <stdio.h>

void file_function(void);

/*Definition*/
int private_data;

int main()
{
	private_data = 100;
	printf("Private data: %d\n", private_data);

	file_function();
	printf("Private data: %d\n", private_data);

	return 0;
}
