//**************************************************************//
//  Name    : Light sensor                             
//  Author  : Jose Luis Figueroa                                
//  Date    : 28 March, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Use a photoresitor and show the data on the Serial
//          : Monitor                                    
//**************************************************************//
#include <Arduino.h>

//Pins
const uint8_t light_pin = A0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  uint16_t light_val = analogRead(light_pin);
  Serial.println(light_val);
  delay(200);
}