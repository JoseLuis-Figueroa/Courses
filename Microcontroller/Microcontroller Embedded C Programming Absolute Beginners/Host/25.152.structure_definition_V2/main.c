/*
 ****************************************************************
 * @file           : Structure definition
 * @author         : Jose Luis Figueroa
 * @Date		   : 25 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Create three structure variables and assign
 * 				   : values to all their members.
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Structure definition*/
struct car_model
{
	uint32_t car_number;
	uint32_t car_price;
	uint16_t car_max_speed;
	float car_weight;
};

/*Function prototype*/
void wait_for_user_input(void);

int main()
{
	/*Structure variables and initialization*/
	struct car_model car_kia = {2021, 1500, 220, 1330.0};
	struct car_model car_ford = {4031, 35000, 160, 1900.96};
	struct car_model car_honda = {.car_weight = 90.90,.car_price= 15000};

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

	printf("\nHonda Information\n");
	printf("Car price: %d\n",car_honda.car_price);
	printf("Weight of the car: %f\n",car_honda.car_weight);

	printf("\nSize of struct car_model in bytes is: %lld\n", sizeof(struct car_model));

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
