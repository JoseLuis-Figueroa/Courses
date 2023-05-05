/***************************************************************** 
 * Name    : LCD in 4 bits mode (cpp)
 * Author  : Jose Luis Figueroa  
 * Date    : 29 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : cpp file where all the function are implemented
******************************************************************/
#include "4bit_LCD.h"

/***************************************************************** 
 * Declarations
******************************************************************/
//Pins assignments
#define CS D10
#define MOSI D11
#define MISO D12
#define SCLK D13

//Object instance
DigitalOut cs(CS);
SPI ser_port(MOSI, MISO, SCLK);

/***************************************************************** 
 * LCD functions
******************************************************************/
void init_lcd(void) 
{
  thread_sleep_for (40);
  shift_out(0x30);    //function set 8-bit
  wait_us(37);
  write_cmd(0x20);    //function set
  wait_us(37);
  write_cmd(0x20);    //function set
  wait_us(37);
  write_cmd(0x0C);    //display ON/OFF
  wait_us(37);
  write_cmd(0x01);    //display clear
  wait_us(1520);
  write_cmd(0x06);    //entry-mode set
  wait_us(37);
  write_cmd(0x28);    //function set
  wait_us(37);
}

void write_4bit(int data, int mode) 
{
  int hi_n;
  int lo_n;
  //form the two 4-bit nibbles that will be sent
  hi_n = (data & 0xF0);           
  lo_n = ((data << 4) &0xF0);
  //send each word twice, strobing the Enable line
  shift_out(hi_n | ENABLE | mode); 
  wait_us(1);
  shift_out(hi_n & ~ENABLE);
  shift_out(lo_n | ENABLE | mode);
  wait_us(1);
  shift_out(lo_n & ~ENABLE);
}

void shift_out(int data) 
{
  //Invokes SPI
  cs = 0;
  ser_port.write(data);  
  cs = 1;
}

void write_cmd(int cmd) 
{
  //Write configuration commands
  write_4bit(cmd, COMMAND_MODE);  
}

void write_data(char c) 
{
  //Write data
  write_4bit(c, DATA_MODE);    //1 for data mode
}

void clr_lcd(void) 
{
  write_cmd(0x01);    
  wait_us(1520);
}

void print_lcd(const char *string) 
{
  //Loop will terminate when null-value(char) is encountered
  while(*string)
  {
    //Set char(one caracter) and increase the pointer
    //(next value of the string)
    write_data(*string++);
    wait_us(40);
  }
}
