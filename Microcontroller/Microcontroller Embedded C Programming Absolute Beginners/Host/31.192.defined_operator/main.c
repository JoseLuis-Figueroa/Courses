/*
 ****************************************************************
 * @file           : defined operator
 * @author         : Jose Luis Figueroa
 * @Date		   : 20 Apr, 2022
 * @board		   : CPU (Standard C)
 * @brief          : They are used to disable a piece of code of
 * 				   : the compilation. Use error and warning
 * 				   : conditions to send them on compilation.
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Define the conditions to enable them. Comment one of both of
 * them to review error and warning */
#define AREA_TRI
#define AREA_CIR

/*Send error on compilation when the conditions are not defined*/
#if !defined(AREA_TRI) && !defined(AREA_CIR)
	#error "No macros defined"
#endif

/*Send a warning when one condition is not defined*/
#if !defined(AREA_TRI) || !defined(AREA_CIR)
	#warning "One macro was not defined"
#endif

int main()
{
	/*Print a message when both condition are defined*/
#if defined(AREA_TRI) && defined(AREA_CIR)
	printf("This is the area calculation of circle and triangle\n");
#endif

	/*Enter If AREA_CIR is defined*/
#ifdef AREA_CIR
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
