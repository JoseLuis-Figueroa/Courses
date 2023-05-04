/*
 ****************************************************************
 * @file           : For Loop
 * @author         : Jose Luis Figueroa
 * @Date		   : 15 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Create a pyramid with numbers
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>


/*Function prototype*/
void wait_for_user_input(void);


int main()
{
	int32_t height;

	printf("Enter height of pyramid: \n");
	scanf("%d",&height);

	if(height > 0)
	{
		for(uint32_t i=0; i<=height; i++)
		{
			for(uint32_t j=i; j>0; j--)
			{
				printf("%d ",j);
			}
				printf("\n");
		}
	}
	else
	{
		printf("Negative numbers are invalid\n");
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
