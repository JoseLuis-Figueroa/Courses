/*
 ****************************************************************
 * @file           : If-else-if statement exercise
 * @author         : Jose Luis Figueroa
 * @Date		   : 10 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Calculate the tax using if-else-if statement
 * 				   : (defensive programming)
 ****************************************************************
 */
#include<stdio.h>
#include<stdint.h>


/*Function Prototype*/
void wait_for_user_input();


int main()
{
	/*Variables*/
	float income;
	float tax;

	/*User interface*/
	printf("Enter your income: ");
	if(scanf("%f",&income) == 0)
	{
		printf("Invalid value! Exiting...");
		wait_for_user_input();
		return 0;
	}

	if(income < 0)
	{
		printf("Income cannot be negative\n");
		wait_for_user_input();
		return 0;
	}

	/*Tax Calculation*/
	if(income <= 9525)
	{
		tax = 0;
	}
	else if((income >= 9526) && (income <= 38700))
	{
		tax = income*0.12;
	}
	else if((income >= 38701) && (income <= 82500))
	{
		tax = income*0.22;
	}
	else
	{
		tax = (income*0.32)+1000;
	}
	printf("Your tax payable is $%f\n", tax);

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
