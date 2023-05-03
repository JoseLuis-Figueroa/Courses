/*
 ****************************************************************
 * @file           : Bitwise
 * @author         : Jose Luis Figueroa
 * @Date		   : 11 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Make logical operation with two numbers
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Function prototype*/
void wait_for_user_input();


int main()
{
	/*Variable*/
	uint32_t number1 = 0;
	uint32_t number2 = 0;
	uint32_t and;
	uint32_t or;
	uint32_t xor;
	uint32_t not;
	uint32_t not_2;

	/*User interface*/
	printf("Bitwise operation");
	printf("\nEnter first number: ");
	if(scanf("%d",&number1) == 0)
	{
		printf("\nInvalid number! Exiting...");
		wait_for_user_input();
		return 0;
	}
	printf("\nEnter second number: ");
	if(scanf("%d",&number2) == 0)
		{
			printf("\nInvalid number! Exiting...");
			wait_for_user_input();
			return 0;
		}

	/*Logical Operation*/
	printf("\nLogical AND operation");
	and = number1 & number2;
	printf("\nResult: %d", and);

	printf("\nLogical OR operation");
	or = number1 | number2;
	printf("\nResult: %d", or);

	printf("\nLogical XOR operation");
	xor = number1 ^ number2;
	printf("\nResult: %d", xor);

	printf("\nLogical not operation");
	not = ~number1;
	printf("\nResult: %d", not);
	not_2 = ~number2;
	printf("\nResult: %d", not_2);

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



