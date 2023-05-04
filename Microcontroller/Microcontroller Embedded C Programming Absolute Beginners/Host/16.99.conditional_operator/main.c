/*
 ****************************************************************
 * @file           : Conditional Operator
 * @author         : Jose Luis Figueroa
 * @Date		   : 11 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Use Conditional operator to review the age
 ****************************************************************
 */
#include<stdio.h>
#include<stdint.h>

int main()
{
	uint32_t age = 0;

	printf("Enter your age here: ");
	scanf("%d",&age);

	(age < 18) ? printf("You're not eligible to vote\n") :
			printf("Congrats! you can vote\n");

	printf("\nPress enter key to exit this application");

	while(getchar() != '\n')
	{
		/*Read the input buffer and do nothing*/
	}
	getchar();

	return 0;
}
