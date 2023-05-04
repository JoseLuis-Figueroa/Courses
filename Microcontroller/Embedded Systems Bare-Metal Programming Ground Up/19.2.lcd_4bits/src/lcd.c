/*
 ****************************************************************
 * @file           : lcd implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 10 oct, 2022
 * @board		   : Nucleo F401RE
 * @brief          : lcd.c implements all the lcd functions used
 *                 : to control the lcd
 ****************************************************************
 */
#include "lcd.h"
#include "systick.h"

/****************************************************************
*Static Function declaration
*****************************************************************/
static void lcd_data(char data);

/****************************************************************
*LCD 8 bits Functions
*****************************************************************/
void lcd_init()
{
    /*Initialize the LCD to work with 8 bits*/
    /*Initialize the GPIOs*/
    gpio_init(false); 
    /*Initialization sequence*/
    systick_delayms(30);
    lcd_command(0x30);
    systick_delayms(10);
    lcd_command(0x30);
    systick_delayms(1);
    lcd_command(0x30);
    /*Set 8 bits data mode, 2 lines, 5*8 font*/
    lcd_command(0x38);
    /*Move cursor right*/
    lcd_command(0x06);
    /*Clear screen and move cursor home*/
    lcd_command(0x01);
    /*Turn display, blink cursor*/
    lcd_command(0x0F);
}

void lcd_command(unsigned char command)
{
    /*Send commands to the LCD*/
    /*Enable writing to LCD(R/W=0) and enable instruction 
    command register(RS=0)*/
    GPIOB->ODR &=~RS; 
    GPIOB->ODR &=~RW;
    /*Enable the reception of data*/
    GPIOB->ODR |= EN;
    /*Send instruction command*/
    GPIOC->ODR = command;
    /*Disable the reception of data*/
    GPIOB->ODR &=~EN;
    systick_delayms(2);
}

void print_lcd(const char *string)
{
    /*Print the string on the lcd. Char pointer is receiving the 
    first address of the char array*/
    
    /*It will terminate when null-value is encountered. Compare 
    the value of pointer (no addrress)*/
    while(*string)
    {
        /*Send the value and increase the address of the pointer*/
        lcd_data(*string++);
    }
}

static void lcd_data(char data)
{
    /*Send the data to be displayed to the LCD*/
    /*Enable data command register(RS=1)*/
    GPIOB->ODR |= RS;
    /*Enable writing to LCD(R/W=0)*/
    GPIOB->ODR &=~RW;
    /*Enable the reception of data*/
    GPIOB->ODR |= EN;
    /*Send the data*/
    GPIOC->ODR = data;
    /*Disable the reception of data*/
    GPIOB->ODR &=~EN;
    systick_delayms(2);
}

/****************************************************************
*LCD 4 bits Function
*****************************************************************/
void lcd_init_4bits(void)
{
    /*Initialize the LCD to work with 8 bits*/
    /*Initialize the GPIOs*/
    gpio_init(true);
    /*Initialization sequence*/
    systick_delayms(30);
    lcd_nibble_write(0x30, 0);
    systick_delayms(5);
    lcd_nibble_write(0x30, 0);
    systick_delayms(1);
    lcd_nibble_write(0x30, 0);
    systick_delayms(1);
    //Set 4 bits data mode
    lcd_nibble_write(0x20, 0);
    systick_delayms(1);
    /*Set 4 bits data mode, 2 line, 5*7 font*/
    lcd_command_4bits(0x28);
    /*Move cursor right*/
    lcd_command_4bits(0x06);
    /*Clear screen and move cursor home*/
    lcd_command_4bits(0x01);
    /*Turn display, blink cursor*/
    lcd_command_4bits(0x0F);

}

void lcd_nibble_write(char data, unsigned char control)
{
    /*Configure the lcd mode and send the data by nibble*/
    /*Clear data bits*/
    GPIOC->ODR &=~ GPIO_ODR_OD4_OD7;
    if(control & RS)
    {
        /*Enable data command register(RS=1)*/
        GPIOB->ODR |= RS;
    }
    else
    {
        /*Enable instruction command register(RS=0)*/
        GPIOB->ODR &=~RS;
    }
    /*Enable the reception of data*/
    GPIOB->ODR |= EN;
    /*Send the 4 bits data to the LCD*/
    GPIOC->ODR = data & GPIO_ODR_OD4_OD7;
    /*Disable the reception of data*/
    GPIOB->ODR &=~EN;
}

void lcd_command_4bits(unsigned char command)
{
    /*Send commands to the LCD*/
    /*Write the upper nibble of the command (Upper 4 bits)*/
    lcd_nibble_write(command & 0xf0, 0);
    /*Write the lower nibble of the command (Lower 4 bits)*/
    lcd_nibble_write(command << 4, 0);
    systick_delayms(2);
}

void lcd_data_4bits(char data)
{
    /*Send the data to be displayed to the LCD*/
    /*Write the upper nibble of the data*/
    lcd_nibble_write(data & 0xf0, RS);
    /*Write the lower nibble of the data*/
    lcd_nibble_write(data << 4, RS);
    systick_delayms(2);
}

void print_lcd_4bits(const char *string)
{
    /*Print the string on the lcd. Char pointer is receiving the 
    first address of the char array*/
    
    /*It will terminate when null-value is encountered. Compare 
    the value of pointer (no addrress)*/
    while(*string)
    {
        /*Send the value and increase the address of the pointer*/
        lcd_data_4bits(*string++);
    }
}

/****************************************************************
*GPIO Function
*****************************************************************/
void gpio_init(bool mode_4bits)
{   
    /*Initialize the GPIOs to control the LCD*/
    /*Configure GPIOB*/
    /*Enable clock access to GPIOB*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    /*Set PB3, PB4, and PB5 as output pin*/
    /*PB3*/
    GPIOB->MODER |= GPIO_MODER_MODER3_0;
    GPIOB->MODER &=~GPIO_MODER_MODER3_1;
    /*PB4*/
    GPIOB->MODER |= GPIO_MODER_MODER4_0;
    GPIOB->MODER &=~GPIO_MODER_MODER4_1;
    /*PB5*/
    GPIOB->MODER |= GPIO_MODER_MODER5_0;
    GPIOB->MODER &=~GPIO_MODER_MODER5_1;
    /*Reset PB4 and PB5 pin (Off)*/
    GPIOB->ODR &=~RW;
    GPIOB->ODR &=~EN;
    /*Configure GPIOC*/
    /*Enable clock access to GPIOC*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    if(mode_4bits)
    {
        /*Set PC4 to PC7 as output pins*/
        GPIOC->MODER |= GPIO_MODER_MODER4_MODER7;
    }
    else
    {
        /*Set PC0 to PC7 as output pins*/
        GPIOC->MODER |= GPIO_MODER_MODER0_MODER7;
    }

}