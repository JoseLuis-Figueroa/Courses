/***************************************************************** 
 * Name    : LCD
 * Author  : Jose Luis Figueroa  
 * Date    : 10 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Sends character strings to LCD. LCD is operated in 
 *         : 4-bit mode
******************************************************************/
#include <mbed.h>
#include "LCD_4bit.h"

//Pins assignments
#define CS D10
#define MOSI D11
#define MISO D12
#define SCLK D13

LCD_4bit LCD(CS, MOSI, MISO, SCLK);

int main() 
{
  LCD.init_lcd();
  LCD.clr_lcd();
  LCD.print_lcd("  Hello Chiwie");
  LCD.write_cmd(0xc0);
  wait_us(40);
  LCD.print_lcd("  and Cookie!");
  while(1) 
  {
    
    thread_sleep_for(100);
  }
}