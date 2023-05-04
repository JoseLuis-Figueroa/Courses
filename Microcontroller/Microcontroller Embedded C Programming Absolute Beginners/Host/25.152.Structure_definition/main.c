/*
 ****************************************************************
 * @file           : Structure definition
 * @author         : Jose Luis Figueroa
 * @Date		   : 25 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Create two structure variables and assign
 * 				   : values to all their members.
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Structure definition*/
struct car_model
{
	unsigned int car_number;
	uint32_t car_price;
	uint16_t car_max_speed;
	float car_weight;
};

/*Function Prototype*/
void wait_for_user_input(void);

int main ()
{
	/*Structure variables*/
	struct car_model car_kia, car_ford;

	/*Initialize variables*/
	car_kia.car_number = 2021;
	car_kia.car_price = 15000;
	car_kia.car_max_speed = 220;
	car_kia.car_weight = 1330.0;

	car_ford.car_number = 4031;
	car_ford.car_price = 35000;
	car_ford.car_max_speed = 160;
	car_ford.car_weight = 1900.96;

	/*Print all the info*/
	printf("Kia Information\n");
	printf("Number of car: %d\n",car_kia.car_number);
	printf("Car price: %d\n",car_kia.car_price);
	printf("Maximum speed of the car: %d\n",car_kia.car_max_speed);
	printf("Weight of the car: %.2f\n", car_kia.car_weight);

	printf("\nFord Information\n");
	printf("Number of car: %d\n",car_ford.car_number);
	printf("Car price: %d\n",car_ford.car_price);
	printf("Maximum speed of the car: %d\n",car_ford.car_max_speed);
	printf("Weight of the car: %.2f\n", car_ford.car_weight);

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
