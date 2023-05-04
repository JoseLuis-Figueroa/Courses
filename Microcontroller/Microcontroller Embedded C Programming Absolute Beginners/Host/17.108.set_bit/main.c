/*
 ****************************************************************
 * @file           : Set, clear and xor bits
 * @author         : Jose Luis Figueroa
 * @Date		   : 14 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Set the 4th and 7th positions of a number.
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>


/*Function prototype*/
void wait_for_user_input();

int main()
{
	uint32_t number;

	/*User interface*/
	printf("Enter a number: \n");
	scanf("%d", &number);

	/*Set bits*/
	uint32_t new_number = number | 0x90;
	/*Better way to do it*/
	/*number |= (1U<<7) | (1U<<4);*/
	printf("%d is the new number\n", new_number);

	/*Clear bits*/
	number &= ~(1U<<6) & ~(1U<<5) & ~(1U<<4);
	printf("The bits were cleared: %d\n", number);


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
