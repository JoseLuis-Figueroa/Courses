/***************************************************************** 
 * Name    : LCD in 4 bits mode (Header)
 * Author  : Jose Luis Figueroa  
 * Date    : 28 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Header file for a simple set of functions to write to
 *         : 2x16 LCD
******************************************************************/
#ifndef FOUR_BIT_LCD_H
#define FOUR_BIT_LCD_H

#include "mbed.h"

#define ENABLE 0x08         //Ored in to data value to strobe E bit
#define COMMAND_MODE 0x00   //RS line to 0, for command transfer
#define DATA_MODE 0x04      //RS line to 1, for data transfer

//Function prototype 
void clr_lcd(void);
void init_lcd(void);
void print_lcd(const char *string);
void shift_out(int data);
void write_cmd(int cmd);
void write_data(char c); 
void write_4bit(int data);
#endif
