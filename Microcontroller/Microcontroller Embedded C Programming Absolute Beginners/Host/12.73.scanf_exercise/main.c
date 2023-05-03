/*
 ****************************************************************
 * @file           : Scanf exercise
 * @author         : Jose Luis Figueroa
 * @Date		   : 2 mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Get char values and get the ASCII codes
 ****************************************************************
 */
#include<stdio.h>

int main()
{
	char val1, val2, val3, val4, val5, val6;

	printf("Enter 6 characters of your choice: ");
	/*Use to write on the console*/
	fflush(stdout);
	scanf("%c %c %c %c %c %c",&val1,&val2,&val3,&val4,&val5,&val6);

	/*Use %u (unsigned) to print integer values*/
	printf("\nASCII codes: %u %u %u %u %u %u", val1,val2,val3,val4,val5,val6);

	return 0;
}

