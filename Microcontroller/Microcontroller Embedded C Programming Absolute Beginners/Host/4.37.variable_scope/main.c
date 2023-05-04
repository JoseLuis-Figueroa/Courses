/*
 ****************************************************************
 * @file           : Variable scope
 * @author         : Jose Luis Figueroa
 * @Date		   : 24 feb, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Show the global and local variables
 ****************************************************************
 */

#include<stdio.h>

/*This is a function prototype*/
void myfunc(void);

/*Global variable*/
int myscope;

int main(void)
{
	myscope = 900;
	printf("Value of the variable: %d\n", myscope);

	/*Call myfunc*/
	myfunc();

	/*To see the execution*/
	getchar();

	return 0;
}


void myfunc(void)
{
	/*Local variable*/
	int myscope_2 = 50;
	printf("Value of the variable: %d\n", myscope_2);
}
