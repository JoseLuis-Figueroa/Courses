/*
 ****************************************************************
 * @file           : Mask
 * @author         : Jose Luis Figueroa
 * @Date		   : 14 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Make a mask to determinate if a number is
 * 				   : even or odd
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>


/*Function prototype*/
void wait_for_user_input();


int main()
{
	uint32_t number;
	printf("Enter a number: \n");
	scanf("%d", &number);

	if (number & 1)
	{
		printf("%d is odd\n", number);
	}
	else
	{
		printf("%d is even\n", number);
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
