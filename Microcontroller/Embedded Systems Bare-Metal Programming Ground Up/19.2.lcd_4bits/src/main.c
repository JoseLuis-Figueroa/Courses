/*
 ****************************************************************
 * @file           : LCD (1602A) using 4 bits
 * @author         : Jose Luis Figueroa
 * @Date		   : 6 oct, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Configure a LCD to use 4 bits (4 pins).
 *                 : Pinout: PC4 to PC7 = D4 to D7, PB3 = RS,    
 *                 : PB4 = R/W, and PB5 = EN 
 ****************************************************************
 */
#include <stdbool.h>
#include "lcd.h"
#include "systick.h"

int main(void)
{
    /*Initialize the LCD*/
    lcd_init_4bits();

    while(1)
    {
        print_lcd_4bits("Hello");
        /*Move the course to the second line*/
        lcd_command_4bits(0xc0);
        /*Print the string*/
        print_lcd_4bits("Nathy & Pepe");
        systick_delayms(500);
        lcd_command_4bits(0x01);
    }
}