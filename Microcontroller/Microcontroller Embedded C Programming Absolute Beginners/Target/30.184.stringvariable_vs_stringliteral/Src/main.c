/*
 ****************************************************************
 * @file           : String variable vs string literal
 * @author         : Jose Luis Figueroa
 * @Date		   : 13 Apr, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Implement 2 type of arrays. Use SWV to print
 * 				   : the data
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

int main (void)
{
	char msg1[] = "Hello how are you?";
	/*Keep this type of array constant*/
	char const *pmsg2 = "fastbitlab.com";

	msg1[0] = 'b';

	/*Print the array and address*/
	printf("Message is :%s\n",msg1);
	printf("Address of 'msg1' variable = %p\n",&msg1);
	printf("Value of 'msg1' variable = %p\n",msg1);

	printf("Message is :%s\n",pmsg2);
	printf("Address of 'msg1' variable = %p\n",&pmsg2);
	printf("Value of 'msg1' variable = %p\n",pmsg2);


	for(;;);
}
