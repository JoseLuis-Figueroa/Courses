/*
 ****************************************************************
 * @file           : If-else statement exercise
 * @author         : Jose Luis Figueroa
 * @Date		   : 10 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Validate the input values to avoid to break
 * 				   : the code (defensive programming).
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Function prototype*/
void wait_for_user_input();


int main()
{
	/*Variables*/
	float number1, number2;
	int32_t num1, num2;

	/*User interface*/
	printf("Enter the first number: ");
	if(scanf("%f",&number1) == 0)
	{
		printf("Invalid input! exiting...\n");
		wait_for_user_input();
		return 0;
	}

	printf("Enter the second number: ");
	if(scanf("%f",&number2) == 0)
	{
		printf("Invalid input! exiting...\n");
		wait_for_user_input();
		return 0;
	}

	/*We are storing only integer part of the real numbers*/
	num1 = number1;
	num2 = number2;
	if((num1 != number1) || (num2 != number2))
	{
		printf("Warning! comparing only integer part\n");
	}

	/*Comparing the numbers*/
	if(num1 < num2)
	{
		printf("%d is bigger\n", num2);
	}
	else if(num2 < num1)
	{
		printf("%d is bigger\n", num1);
	}
	else
	{
		printf("Both numbers are equal\n");
	}

	wait_for_user_input();
	return 0;
}


/*Function implementation*/
void wait_for_user_input()
{
	/*Code used to pause the program*/
	printf("\nPress enter key to exit this application");
	while(getchar() != '\n')
	{
		/*Read the input buffer and do nothing*/
	}
	getchar();
}
