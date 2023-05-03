/*
 ****************************************************************
 * @file           : Scanf exercise 2
 * @author         : Jose Luis Figueroa
 * @Date		   : 2 mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          :
 ****************************************************************
 */
#include<stdio.h>

int main()
{
	double charge, charge_e;
	double electrons;

	printf("Enter the charge: ");
	fflush(stdout);
	scanf("%lf",&charge);

	printf("\nEnter the charge of an electron: ");
	fflush(stdout);
	scanf("%le",&charge_e);


	electrons = (charge / charge_e) * -1;
	printf("\nTotal number of electrons: %le", electrons);
	printf("\nTotal number of electrons: %lf", electrons);

	return 0;
}
