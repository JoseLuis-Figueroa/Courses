//**************************************************************//
//  Name    : Speed Controller                                   
//  Author  : Jose Luis Figueroa                                
//  Date    : 13 April, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Potentiometer controls the speed of the DC motor                                         
//**************************************************************//
#include <Arduino.h>

//Pins assignments
const uint8_t PTR_PIN = 2;
const uint8_t MTR_PIN = 4;

void setup() 
{
  pinMode(MTR_PIN, OUTPUT);
}

void loop() {
  //Read the potentiometer and change 10 bits to 8 bits
  uint16_t pot_val = analogRead(PTR_PIN);
  uint8_t value = map(pot_val, 0, 1023, 0 , 255);
  delay(30);

  //Use PWM to change the speed according to the pot (ADC)
  analogWrite(MTR_PIN, value);

}