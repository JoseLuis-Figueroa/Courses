//**************************************************************//
//  Name    : Light Gauge                       
//  Author  : Jose Luis Figueroa                                
//  Date    : 15 April, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Use a photoresistor to control servo according to
//          : light                                        
//**************************************************************//
#include <Arduino.h>
#include <Servo.h>

//Pins assignment
const uint8_t PHO_PIN = A0;
const uint8_t SRV_PIN = 9;

//Constants and variables
const uint8_t wait_20ms = 20;
const int32_t max_val_srv = 180;
const int32_t max_val_pho = 1023;

//Instance 
Servo servo;

void setup() 
{
  servo.attach(SRV_PIN);
}

void loop() 
{
  //Get a value of the photoresitor (0-1023)
  uint16_t light = analogRead(PHO_PIN);
  //Charge the value to servo acording to light (0-180)
  int32_t value = map(light, 0, max_val_pho, 0, max_val_srv);
  servo.write(value);
  delay(wait_20ms);
}