/*
 ****************************************************************
 * @file           : Swapping
 * @author         : Jose Luis Figueroa
 * @Date		   : 11 Apr, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Swap the elements between two arrays. The
 * 				   : arrays should be assigned with the size to
 * 				   : avoid problems
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>

/*Function definition*/
void array_display(uint32_t const *const ptr_array, uint32_t size);
void swap_arrays(uint32_t *array1, uint32_t *array2, uint32_t array1_size, uint32_t array2_size);
void wait_for_user_input(void);


int main(void)
{
	int array1_size, array2_size;

	/*User interface array 1*/
	printf("Array swapping program\n");
	printf("Enter number of elements of Array1: ");
	scanf("%d", &array1_size);
	uint32_t array1[array1_size];
	/*Enter elements of array 1*/
	for(uint16_t i=0; i<array1_size; i++)
	{
		printf("\nEnter element %d of array1: ",i+1);
		scanf("%d", &array1[i]);
	}

	/*User interface array 2*/
	printf("\nEnter number of elements of Array2: ");
	scanf("%d", &array2_size);
	uint32_t array2[array2_size];
	/*Enter elements of array 1*/
	for(uint16_t y=0; y<array2_size; y++)
	{
		printf("\nEnter element %d of array1: ",y+1);
		scanf("%d", &array2[y]);
	}

	/*Print elements of the arrays*/
	printf("Contents of array before swap\n");
	array_display(array1, array1_size);
	printf("\n");
	array_display(array2, array2_size);
	printf("\n");
	swap_arrays(array1, array2, array1_size, array2_size);
	printf("Contents of array after swap\n");
	array_display(array1, array1_size);
	printf("\n");
	array_display(array2, array2_size);

	wait_for_user_input();

	return 0;
}


/*Function implementation*/
void array_display(uint32_t const *const ptr_array, uint32_t size)
{
	for(uint16_t i=0; i<size; i++)
	{
		printf("%4d   ",ptr_array[i]);
	}
}

void swap_arrays(uint32_t *array1, uint32_t *array2, uint32_t array1_size, uint32_t array2_size)
{
	/*Check which size variable is bigger*/
	uint32_t len = array1_size < array2_size ? array1_size : array2_size;
	for(uint16_t i=0; i<len; i++)
	{
		uint32_t aux = array1[i];
		array1[i] = array2[i];
		array2[i] = aux;
	}

}

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
