/*
 ****************************************************************
 * @file           : String
 * @author         : Jose Luis Figueroa
 * @Date		   : 19 Apr, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Show how to use a char array as string
 ****************************************************************
 */
#include <stdio.h>

int main()
{
	char name[30];
	printf("Enter your name: ");
	fflush(stdout);
	scanf("%s", name);

	printf("Hi, %s\n", name);

	return 0;
}
