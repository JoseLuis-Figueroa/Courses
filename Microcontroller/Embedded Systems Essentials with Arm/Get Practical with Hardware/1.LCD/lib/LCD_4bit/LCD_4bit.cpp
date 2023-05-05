//**************************************************************//
//  Name    : LCD 4 bit Implementation                                   
//  Author  : Jose Luis Figueroa                                
//  Date    : 5 nov, 2021 
//  Board   : Nucleo-F401RE
//  Version : 1.0                                               
//  Notes   : LCD library                                          
//**************************************************************//
#include <mbed.h>
#include "LCD_4bit.h"

/***************************************************************** 
 * Constructor
******************************************************************/
LCD_4bit::LCD_4bit(PinName CS, PinName MOSI, PinName MISO, PinName SCLK)
{
    this->CS = CS;
    this->MOSI = MOSI;
    this->MISO = MISO;
    this->SCLK = SCLK;
}

/***************************************************************** 
 * Functions
******************************************************************/
void LCD_4bit::clr_lcd(void)
{
    write_cmd(0x01);    
    wait_us(1520);
}

void LCD_4bit::init_lcd(void)
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

void LCD_4bit::print_lcd(const char *string)
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

void LCD_4bit::shift_out(int data)
{
    //Invokes SPI
    SPI ser_port(MOSI, MISO, SCLK);
    DigitalOut cs(CS);
    cs = 0;
    ser_port.write(data);  
    cs = 1;

}

void LCD_4bit::write_4bit(int data, int mode)
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

void LCD_4bit::write_cmd(int cmd)
{
    //Write configuration commands
    write_4bit(cmd, COMMAND_MODE);  
}

void LCD_4bit::write_data(char c)
{
    //Write data
    write_4bit(c, DATA_MODE);    //1 for data mode
}