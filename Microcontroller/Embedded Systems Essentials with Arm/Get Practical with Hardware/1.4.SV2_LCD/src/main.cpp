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

//Pins Assignment 
#define ENABLE 0x08   //Will be ORed in to data value to strobe E 
#define COMMAND 0x00  //used to clear RS line to 0
#define DATA 0x04     //used to set RS line to 1

//Object instances
DigitalOut cs(D10);
SPI ser_port(D11, D12, D13); // Initialise SPI, using default settings

//Function Prototypes
void clr_lcd(void);
void init_lcd(void);
void print_lcd(const char *string);
void shift_out(int data);
void write_cmd(int cmd);
void write_data(char c); 
void write_4bit(int data);


/***************************************************************** 
 * Main
******************************************************************/
int main() 
{
  cs=1;
  init_lcd();  //initialise the LCD
  clr_lcd();   //Clear the LCD
  print_lcd("  Hello Nathaly");
  write_cmd(0xc0);   //set cursor to second line
  wait_us(40);
  print_lcd("  and Chiwie!");
  //idle in permanent loop
  while (1) 
  {        
    thread_sleep_for (100);
  }
}       


/***************************************************************** 
 * Functions
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
  write_4bit(cmd, COMMAND);  
}

void write_data(char c) 
{
  //Write data
  write_4bit(c, DATA);    //1 for data mode
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
