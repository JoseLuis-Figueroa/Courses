/*
 ****************************************************************
 * @file           : While
 * @author         : Jose Luis Figueroa
 * @Date		   : 15 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Implement a while loop
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Function prototype*/
void wait_for_user_input(void);


int main ()
{
	uint8_t num=1;
	while (num<=10)
	{
		printf("%d\n",num++);
	}

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
