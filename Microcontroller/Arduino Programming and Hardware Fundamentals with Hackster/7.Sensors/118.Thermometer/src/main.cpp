//**************************************************************//
//  Name    : Thermometer                          
//  Author  : Jose Luis Figueroa                                
//  Date    : 29 March, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Create a digital thermometer using LM35 and LCD                              
//**************************************************************//
#include <Arduino.h>
#include <LiquidCrystal.h>

//Pins
const uint8_t TMP_PIN = A0;
const uint8_t RS_PIN = 22;
const uint8_t E_PIN = 24;
const uint8_t D0_PIN = 2;
const uint8_t D1_PIN = 3;
const uint8_t D2_PIN = 4;
const uint8_t D3_PIN = 5;

//Instance object
LiquidCrystal lcd(RS_PIN, E_PIN, D0_PIN, D1_PIN, D2_PIN, D3_PIN);

void setup()
{
  Serial.begin(9600);
  //Activate 16 columns and 2 rows
  lcd.begin(16, 2);
  lcd.clear();
}

void loop()
{
  float voltage;
  uint16_t temperature;

  //Calculate the temperature
  voltage = (analogRead(TMP_PIN) * 5.0) / 1023;
  temperature = voltage * 100.0;
  //Print in the LCD
  lcd.setCursor(0, 0);
  lcd.print("Thermometer");
  lcd.setCursor(0, 1);
  lcd.print("Temperature:");
  lcd.setCursor(12, 1);
  lcd.print(temperature);
  lcd.print("C");
  Serial.println(temperature);
  delay(300);
}