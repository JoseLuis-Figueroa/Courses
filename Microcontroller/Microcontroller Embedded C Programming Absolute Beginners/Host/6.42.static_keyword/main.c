/*
 ****************************************************************
 * @file           : Static keyword
 * @author         : Jose Luis Figueroa
 * @Date		   : 24 feb, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Use of static makes the variable global and
 * 				   : only visible on the function(inside).
 ****************************************************************
 */

#include <stdio.h>

void function(void);

int main ()
{
	/*Calls to the function*/
	function();
	function();
	function();

	return 0;
}

void function(void)
{
	/*The scope of this variable is global,but visible only on
	 * the function.
	 */
	static int count = 0;
	count += 1;
	printf("This function executed %d time(s)\n", count);
}
