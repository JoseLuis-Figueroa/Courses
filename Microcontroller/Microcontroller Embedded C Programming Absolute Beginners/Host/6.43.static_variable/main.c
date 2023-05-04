/*
 ****************************************************************
 * @file           : Static with variable
 * @author         : Jose Luis Figueroa
 * @Date		   : 24 feb, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Static keyword makes that private_data only
 * 				   : works on main.c file (encapsulation). It's
 * 				   : similar to use private modifiers on C++.
 ****************************************************************
 */
#include <stdio.h>

void file_function(void);

/*Definition*/
static int private_data;

int main()
{
	private_data = 100;
	printf("Private data: %d\n", private_data);

	file_function();
	printf("Private data: %d\n", private_data);

	return 0;
}
