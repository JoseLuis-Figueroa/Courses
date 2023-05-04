/*
 ****************************************************************
 * @file           : LCD (1602A) using 8 bits
 * @author         : Jose Luis Figueroa
 * @Date		   : 29 sep, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Configure a LCD to use 8 bits (8 pins).
 *                 : Pinout: PC0 to PC7 = D0 to D7, PB3 = RS,    
 *                 : PB4 = R/W, and PB5 = EN 
 ****************************************************************
 */
#include "systick.h"
#include "lcd.h"

/*Variables*/
char message[] = {"Chewie & Cookie"};

/****************************************************************
*Main
*****************************************************************/
int main(void)
{
    /*Initialize the LCD*/
    lcd_init();

    while(1)
    {
        /*Print the char array variable*/
        print_lcd(message);
        /*Move the course to the second line*/
        lcd_command(0xc0);
        /*Print the string*/
        print_lcd("Nathy & Pepe");
        
        systick_delayms(500);
        lcd_command(0x01);
    }
}

