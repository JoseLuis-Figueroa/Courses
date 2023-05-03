/*
 ****************************************************************
 * @file           : Scanf
 * @author         : Jose Luis Figueroa
 * @Date		   : 2 mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Use of scanf and how to be implemented.
 *                 : fflush(stdout) is used to flush the content
 *                 : of the output buffer to the console
 ****************************************************************
 */
#include<stdio.h>

int main()
{
	float number1, number2, number3;
	float result;

	printf("Provide the first number: ");
	fflush(stdout);
	scanf("%f",&number1);

	printf("\nProvide the second number: ");
	fflush(stdout);
	scanf("%f",&number2);

	printf("\nProvide the first number: ");
	fflush(stdout);
	scanf("%f",&number3);

	result = (number1 + number2 + number3) / 3;
	printf("\nThe average is: %f", result);

	return 0;
}

