/*
 ****************************************************************
 * @file           : #if and #endif
 * @author         : Jose Luis Figueroa
 * @Date		   : 20 Apr, 2022
 * @board		   : CPU (Standard C)
 * @brief          : They are used to disable a piece of code of
 * 				   : the compilation.
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

int main()
{
	/*If 0: Disable the code | if 1: enable the code */
#if 0
	printf("Circle and triangle areas\n");
#endif

	/*If 1: Enable first condition | if 0: Enable second condition*/
#if 1
	float radius = 0;
	printf("This is circle area calculation program\n");
	fflush(stdout);
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%f",&radius);
	printf("Area of circle = %f\n",(3.1415*radius*radius));
	fflush(stdout);

#else
	float base, height;
	printf("This is triangle area calculation program\n");
	fflush(stdout);
	printf("Enter base and height: ");
	fflush(stdout);
	scanf("%f%f", &base, &height);
	printf("Area of triangle = %f\n", (0.5*base*height));
#endif

	return 0;
}
