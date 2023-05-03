//**************************************************************//
//  Name    : DC motor                                   
//  Author  : Jose Luis Figueroa                                
//  Date    : 13 April, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Turn the motor on and off (each second)                                          
//**************************************************************//
#include <Arduino.h>

//Pins assignments
const uint8_t MTR_PIN = 22;

void setup() 
{
  pinMode(MTR_PIN, OUTPUT);
}

void loop() 
{
  digitalWrite(MTR_PIN, HIGH);
  delay(1000);
  digitalWrite(MTR_PIN, LOW);
  delay(1000);
}