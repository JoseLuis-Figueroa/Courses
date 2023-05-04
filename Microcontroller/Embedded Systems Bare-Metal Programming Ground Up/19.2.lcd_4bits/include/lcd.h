/*
 ****************************************************************
 * @file           : lcd header
 * @author         : Jose Luis Figueroa
 * @Date		   : 10 oct, 2022
 * @board		   : Nucleo F401RE
 * @brief          : lcd header contains all the prototipe 
 *                 : functions used to control the lcd
 ****************************************************************
 */
#ifndef LCD_H_
#define LCD_H_

#include <stdbool.h>
#include "stm32f4xx.h"

/****************************************************************
*Bit definitions
*****************************************************************/
#define RS  GPIO_ODR_OD3                        //PB3
#define RW  GPIO_ODR_OD4                        //PB4
#define EN  GPIO_ODR_OD5                        //PB5
#define GPIO_ODR_OD4_OD7            (0xF0)      
#define GPIO_MODER_MODER0_MODER7    (0x5555)    //output mode
#define GPIO_MODER_MODER4_MODER7    (0x5500)

/****************************************************************
*Function declaration
*****************************************************************/
void gpio_init(bool mode_4bits);
void lcd_init();
void lcd_command(unsigned char command);
void print_lcd(const char *string);

void lcd_init_4bits(void);
void lcd_nibble_write(char data, unsigned char control);
void lcd_command_4bits(unsigned char command);
void lcd_data_4bits(char data);
void print_lcd_4bits(const char *string);

#endif /*LCD_H_*/