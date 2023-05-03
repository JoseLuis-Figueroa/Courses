//**************************************************************//
//  Name    : Night Light                            
//  Author  : Jose Luis Figueroa                                
//  Date    : 28 March, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Turn led on with some intensity according to the 
//          : photoresistor                                   
//**************************************************************//
#include <Arduino.h>

//Pins 
const uint8_t light_pin = A0;
const uint8_t light_led = 2;

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  //Get a value of the photoresitor (0-1023)
  uint16_t light_val = analogRead(light_pin);

  //Conditions to turn led on according to the light of the 
  //photoresitor 
  if(light_val >= 765)
  {
    analogWrite(light_led, 0);
  }
  else if(light_val >= 510 && light_val < 765)
  {
    analogWrite(light_led, 129);
  }
  else if(light_val >= 255 and light_val < 510)
  {
    analogWrite(light_led, 192);
  }
  else
  {
    analogWrite(light_led, 255);
  }
  Serial.println(light_val);
  delay(200);

}