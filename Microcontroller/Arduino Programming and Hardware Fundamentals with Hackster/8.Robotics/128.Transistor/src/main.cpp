//**************************************************************//
//  Name    : Transistors as switches                                 
//  Author  : Jose Luis Figueroa                                
//  Date    : 12 April, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Use a transistor as swithc(Pin 22 connected to Base)                                         
//**************************************************************//
#include <Arduino.h>
#include <Led.h>

const uint8_t LED_PIN = 22;

//Instance 
Led led(LED_PIN);

void setup()
{
  
}

void loop() 
{
  led.on();
  delay(500);
  led.off();
  delay(500);
}