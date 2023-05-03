/*
 ****************************************************************
 * @file           : Function
 * @author         : Jose Luis Figueroa
 * @Date		   : 25 feb, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Implement some diferente math function using
 *                 : modular file
 ****************************************************************
 */

#include <stdio.h>
#include "math.h"

int main()
{
    printf("Sum: %d\n", sum(20,15));
    printf("Subtraction: %d\n", subtraction(50, 35));
    printf("Multiplication: %lld\n", multiplication(5,15));
    printf("Division: %.2f", division(10,5));

    return 0;
}
