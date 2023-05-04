/*
 ****************************************************************
 * @file           : While
 * @author         : Jose Luis Figueroa
 * @Date		   : 15 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Print and count even numbers
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Function prototype*/
void wait_for_user_input(void);

int main ()
{
	int32_t start_num, end_num, even=0;

	/*User interface*/
	printf("Enter starting number: \n");
	scanf("%d", &start_num);
	printf("Enter ending number: \n");
	scanf("%d", &end_num);

	/*Validating if end_num is lower*/
	if(end_num < start_num)
	{
		printf("End number must be higher than start number");
		wait_for_user_input();
		return 0;
	}

	/*Calculate the even numbers*/
	while(start_num<=end_num)
	{
		if((start_num & 0x0001) == 0)
		{
			printf("%d\n",start_num);
			even++;
		}
		start_num++;
	}
	printf("The total number of even: %d\n", even);
	wait_for_user_input();

	return 0;
}


/*Function implementation*/
void wait_for_user_input(void)
{
	/*Code used to pause the program*/
	printf("\nPress enter key to exit this application");
	while(getchar() != '\n')
	{
		/*Read the input buffer and do nothing*/
	}
	getchar();
}
