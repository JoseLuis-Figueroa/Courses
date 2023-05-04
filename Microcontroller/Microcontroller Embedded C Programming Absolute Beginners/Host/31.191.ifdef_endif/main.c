/*
 ****************************************************************
 * @file           : #ifdef and #endif
 * @author         : Jose Luis Figueroa
 * @Date		   : 20 Apr, 2022
 * @board		   : CPU (Standard C)
 * @brief          : They are used to disable a piece of code of
 * 				   : the compilation. Use undef to disable a
 * 				   : condition.
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Define the conditions to enable them*/
#define AREA_TRI
#define AREA_CIR

/*Disable the define condition*/
#undef AREA_CIR

int main()
{

	/*Enter If AREA_CIR is not defined*/
#ifndef AREA_CIR
	float radius = 0;
	printf("This is circle area calculation program\n");
	fflush(stdout);
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%f",&radius);
	printf("Area of circle = %f\n",(3.1415*radius*radius));
	fflush(stdout);
#endif

	/*Enter If AREA_TRI is defined*/
#ifdef AREA_TRI
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
