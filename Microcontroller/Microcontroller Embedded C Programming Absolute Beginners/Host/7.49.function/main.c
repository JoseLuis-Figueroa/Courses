/*
 ****************************************************************
 * @file           : Function
 * @author         : Jose Luis Figueroa
 * @Date		   : 25 feb, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Implement a normal function with arguments
 ****************************************************************
 */
#include <stdio.h>

/*Function prototype*/
int function_add_numbers(int a, int b, int c);


int main()
{
	int result;

	//Call function
	result = function_add_numbers(10, 20, 50);
	printf("The sum result: %d", result);

	return 0;
}


/*Function definition*/
int function_add_numbers(int a, int b, int c)
{
	int sum;
	sum = a+b+c;

	return sum;
}
