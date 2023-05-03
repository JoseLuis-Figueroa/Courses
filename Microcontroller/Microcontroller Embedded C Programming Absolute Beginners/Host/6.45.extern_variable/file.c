/*
 ****************************************************************
 * @file           : file.c
 * @author         : Jose Luis Figueroa
 * @Date		   : 25 feb, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Extern keyword indicates that a variable is
 * 				   : outside of the scope
 ****************************************************************
 */

/*Declaration. Extern keywork indicates that private_data is out
 * of this file.c
 */
extern int private_data;

void file_function(void)
{
	private_data = 500;
}
