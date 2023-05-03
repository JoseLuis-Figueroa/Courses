//**************************************************************//
//  Name    : Sprite                                  
//  Author  : Jose Luis Figueroa                                
//  Date    : 28 Feb, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Use the buttons to move a caracter on the LCD                                       
//**************************************************************//
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Button.h"

//Pins
const uint8_t BTN_LEFT_PIN = 50;
const uint8_t BTN_RIGHT_PIN = 51;
const uint8_t RS_PIN = 22;
const uint8_t E_PIN = 24;
const uint8_t D0_PIN = 2;
const uint8_t D1_PIN = 3;
const uint8_t D2_PIN = 4;
const uint8_t D3_PIN = 5;

//Constants & variables
const uint8_t lcd_width = 16;
uint8_t lcd_position = 1;

//Instance object (RS, E , D0, D1, D2, D4)
LiquidCrystal lcd(RS_PIN, E_PIN, D0_PIN, D1_PIN, D2_PIN, D3_PIN);
Button button_left(BTN_LEFT_PIN);
Button button_right(BTN_RIGHT_PIN);

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup()
{
    lcd.createChar(0, smiley);
    lcd.begin(16, 2);
    lcd.write(byte(0));
}

void loop()
{
    //Enter if the button left is pushed and LCD char is on the first 
    //position or forward
    if(button_left.push() == HIGH && lcd_position > 1)
    {
        lcd.scrollDisplayLeft();
        lcd_position--;
    }

    //Enter if the button right is pushed and LCD char is on the last 
    //position or backwards
    if(button_right.push() == HIGH && lcd_position < 16)
    {
        lcd.scrollDisplayRight();
        lcd_position++;
    }
}
