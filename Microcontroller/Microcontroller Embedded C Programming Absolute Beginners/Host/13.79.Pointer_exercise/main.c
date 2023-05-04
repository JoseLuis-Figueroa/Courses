/*
 ****************************************************************
 * @file           : Pointer exercise
 * @author         : Jose Luis Figueroa
 * @Date		   : 3 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Show the use of pointers
 ****************************************************************
 */
#include<stdio.h>

int main (void)
{
	/*1.Create a char type variable and initialize it to 100*/
	char value = 100;
	printf("Value variable: %d\n", value);
	/*2.Print the address*/
	printf("Address of value: %p\n",&value);
	/*3.Create a pointer and store the address of the value*/
	char *ptr_value = &value;
	/*4.Perform read on the pointer variable to fetch 1 byte of
	 * data from the pointer*/
	char read_value = *ptr_value;
	/*5.Print the data obtained*/
	printf("Data obtained from the pointer: %d\n", read_value);
	/*6.Perform write on the pointer to store 65*/
	*ptr_value= 65;
	/*7.Print the value variable*/
	printf("Value variable: %d\n", value);

	return 0;
}
