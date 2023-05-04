/*
 ****************************************************************
 * @file           : Function like macro
 * @author         : Jose Luis Figueroa
 * @Date		   : 20 Apr, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Implementing an object and function like
 * 				   : macro.
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Object like macro*/
#define PI_VALUE 3.1415f
/*Function like macro*/
#define AREA_CIRCLE(x)	((PI_VALUE)*(x)*(x));

int main(void)
{
	float area_circle;

	area_circle = AREA_CIRCLE(1+1);
	printf("Area = %f\n", area_circle);

	return 0;
}
