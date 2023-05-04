/*
 ****************************************************************
 * @file           : If statement exercise
 * @author         : Jose Luis Figueroa
 * @Date		   : 10 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Use two if to determinate the age to vote
 ****************************************************************
 */
#include<stdio.h>
#include<stdint.h>

int main()
{
	uint32_t age = 0;

	printf("Enter your age here: ");
	scanf("%d",&age);

	if(age >= 18)
	{
		printf("You can vote, as you are %d\n", age);
	}
	else
	{
		printf("Sorry! you are not eligible to vote\n");
	}

	printf("Press enter key to exit this application");

	while(getchar() != '\n')
	{
		/*Read the input buffer and do nothing*/
	}
	getchar();

	return 0;
}
