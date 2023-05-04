/*
 ****************************************************************
 * @file           : Switch
 * @author         : Jose Luis Figueroa
 * @Date		   : 11 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Calculate the area of different figures.
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Function prototype*/
void wait_for_user_input();


int main()
{
	/*Variable*/
	int8_t figure;
	float area = 0, radius, base, height, base_b;


	/*User interface*/
	printf("Area Calculation Program\n");
	printf("Circle		--> c\n");
	printf("Triangle	--> t\n");
	printf("Rectangle 	--> r\n");
	printf("Square		--> s\n");
	printf("Trapezoid	--> z\n");

	printf("\nEnter the code here: ");
	scanf("%c",&figure);


	/*Conditions to calculate the area*/
	switch(figure)
	{
	case 'c':
		printf("\nCircle area calculation");
		printf("\nEnter the radius: ");
		if(scanf("%f",&radius) == 0)
		{
			printf("\nInvalid value! Exiting...");
			wait_for_user_input();
			return 0;
		}
		area = 3.1416 * radius * radius;
		break;
	case 't':
		printf("\nTriangle area calculation");
		printf("\nEnter the base: ");
		if(scanf("%f",&base) == 0)
		{
			printf("\nInvalid value! Exiting...");
			wait_for_user_input();
			return 0;
		}
		printf("Enter the height: ");
		if(scanf("%f",&height) == 0)
		{
			printf("\nInvalid value! Exiting...");
			wait_for_user_input();
			return 0;
		}
		area = (base * height) / 2;
		break;
	case 'r':
		printf("\nRectangle area calculation");
		printf("\nEnter the base: ");
		if(scanf("%f",&base) == 0)
		{
			printf("\nInvalid value! Exiting...");
			wait_for_user_input();
			return 0;
		}
		printf("Enter the height: ");
		if(scanf("%f",&height) == 0)
		{
			printf("\nInvalid value! Exiting...");
			wait_for_user_input();
			return 0;
		}
		area = base * height;
		break;
	case 's':
		printf("\nSquare area calculation");
		printf("\nEnter the base: ");
		if(scanf("%f",&base) == 0)
		{
			printf("\nInvalid value! Exiting...");
			wait_for_user_input();
			return 0;
		}
		area = base * base;
		break;
	case 'z':
		printf("\nTrapezoid area calculation");
		printf("\nEnter the base a: ");
		if(scanf("%f",&base) == 0)
		{
			printf("\nInvalid value! Existing...");
			wait_for_user_input();
			return 0;
		}
		printf("Enter the base B: ");
		if(scanf("%f",&base_b) == 0)
		{
			printf("\nInvalid value! Existing...");
			wait_for_user_input();
			return 0;
		}
		printf("Enter the height: ");
		if(scanf("%f",&height) == 0)
		{
			printf("\nInvalid value! Existing...");
			wait_for_user_input();
			return 0;
		}
		area = ((base + base_b) / 2) * height;
		break;
	default:
		printf("\nInvalid code!");
	}

	/*Review for negative values*/
	if((base < 0) || (base_b < 0) || (height < 0) || (radius < 0))
	{
		printf("\nInvalid negative number");
	}
	else
	{
		printf("\nThe Area is: %f\n",area);
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
