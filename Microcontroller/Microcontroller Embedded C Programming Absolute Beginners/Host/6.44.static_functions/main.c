/*
 ****************************************************************
 * @file           : Static with function
 * @author         : Jose Luis Figueroa
 * @Date		   : 25 feb, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Static keyworks indicates that the function
 * 				   : can be only used on the current file
 ****************************************************************
 */
#include <stdio.h>

/*Definition*/
void file_function(void);
static void change_system_clock(int system_clock);

int main()
{

	/*Call functions*/
	file_function();
	change_system_clock(500);

	return 0;
}

/*Static function
 * Only use the function on one file
 */
static void change_system_clock(int system_clock)
{
	printf("System clock changed %d\n", system_clock);

}
