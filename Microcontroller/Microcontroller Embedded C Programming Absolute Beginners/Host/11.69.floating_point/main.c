/*
 ****************************************************************
 * @file           : Floating point
 * @author         : Jose Luis Figueroa
 * @Date		   : 2 mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Implements single floating point (float) and
 *                 : double floating point (double)
 ****************************************************************
 */
#include<stdio.h>

int main(void)
{
	/*float has 6 decimal of precision*/
	float number = 45.78976834578;
	printf("Number: %f\n", number);

	/*Scientific notation*/
	float number_2 = 45.78976834578;
	printf("Number: %e\n", number_2);

	/*double*/
	double number_d = 45.78976834578;
	printf("Number %0.14lf\n", number_d);

	/*double is needed for the following value*/
	double charge = -1.6021762e-19;
	printf("Charge: %0.28lf\n",charge);
	printf("Charge: %0.8e\n",charge);

	return 0;
}
