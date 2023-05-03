/*
 ****************************************************************
 * @file           : String using scanset
 * @author         : Jose Luis Figueroa
 * @Date		   : 19 Apr, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Use scanset to print part of the message.
 * 				   : Print until finding 's' character
 ****************************************************************
 */
#include <stdio.h>

int main(void)
{
	char name[30];

	printf("Enter your full name: ");
	fflush(stdout);
	/*scanset*/
	scanf("%[^s]s", name);
	printf("Your name is: %s\n", name);

	return 0;
}
