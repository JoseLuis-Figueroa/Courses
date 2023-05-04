/*
 ****************************************************************
 * @file           : UART modular
 * @author         : Jose Luis Figueroa
 * @Date		   : 14 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Create a header for UART
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"

int main(void)
{
    /*initialize uart*/
    uart2_tx_init();

    while(1)
    {
        uart2_write('C');
    }
}