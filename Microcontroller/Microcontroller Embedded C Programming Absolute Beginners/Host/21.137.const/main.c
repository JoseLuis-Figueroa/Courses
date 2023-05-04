/*
 ****************************************************************
 * @file           : Const
 * @author         : Jose Luis Figueroa
 * @Date		   : 15 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Implementation of const. You cannot modify
 * 				   : the constant. But a pointer can be used to
 * 				   : modify the address of a const.
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Constant declaration*/
uint8_t const data = 10;

int main ()
{
	printf("Value = %u\n", data);
	/*Compiler will send an error as the data cannot be changed */
	/*data = 50;*/

	/*Const data can be changed using pointers*/
	uint8_t *ptr = (uint8_t*)&data;
	/*Address can be changed. I do not change because I know a
	 * Address to assign*/
	printf("Value = %u\n",data);

	/*getchar();*/

	return 0;
}
