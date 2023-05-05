//**************************************************************//
//  Name    : LCD header                                   
//  Author  : Jose Luis Figueroa                                
//  Date    : 5 Nov, 2021 
//  Board   : Nucleo F401RE
//  Version : 1.0                                               
//  Notes   : LCD library                                          
//**************************************************************//
#ifndef FOUR_BIT_LCD_H
#define FOUR_BIT_LCD_H

#include "mbed.h"

/***************************************************************** 
 * Declarations
******************************************************************/
#define ENABLE 0x08         //Ored in to data value to strobe E bit
#define COMMAND_MODE 0x00   //RS line to 0, for command transfer
#define DATA_MODE 0x04      //RS line to 1, for data transfer

/***************************************************************** 
 * LCD_4bit class
******************************************************************/
class LCD_4bit
{
private:
    PinName CS;
    PinName MOSI;
    PinName MISO;
    PinName SCLK;
public:
    //Constructor
    LCD_4bit(PinName CS, PinName MOSI, PinName MISO, PinName SCLK);
    //Functions
    void clr_lcd(void);
    void init_lcd(void);
    void print_lcd(const char *string);
    void shift_out(int data);
    void write_cmd(int cmd);
    void write_data(char c); 
    void write_4bit(int data, int mode);
};

#endif