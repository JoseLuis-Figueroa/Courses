//**************************************************************//
//  Name    : LCD                                  
//  Author  : Jose Luis Figueroa                                
//  Date    : 28 Feb, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   :                                       
//**************************************************************//
#include <Arduino.h>
#include <LiquidCrystal.h>

//Instance object (RS, E , D4, D5, D6, D7)
LiquidCrystal lcd(22, 24, 2, 3, 4 ,5);

void setup()
{
    //Indicates (number of characters per row, number of rows)
    lcd.begin(16, 2);
    lcd.clear();
    lcd.print("Hello, World!");
}

void loop()
{
    //Get seconds
    int counter = millis() / 1000;
    //(character position x, row number)
    lcd.setCursor(0, 1);
    lcd.print(counter);
}