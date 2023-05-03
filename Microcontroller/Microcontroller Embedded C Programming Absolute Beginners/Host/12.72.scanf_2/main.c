/*
 ****************************************************************
 * @file           : Scanf 2
 * @author         : Jose Luis Figueroa
 * @Date		   : 2 mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Take 3 values using one scanf
 ****************************************************************
 */
#include<stdio.h>

int main()
{
	double number1, number2, number3;
	double result;

	printf("Provide 3 numbers: ");
	fflush(stdout);
	scanf("%lf %lf %lf",&number1,&number2,&number3);


	result = (number1 + number2 + number3) / 3;
	printf("\nThe average is: %0.3lf", result);

	return 0;
}

