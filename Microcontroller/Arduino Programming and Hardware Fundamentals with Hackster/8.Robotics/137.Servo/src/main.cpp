//**************************************************************//
//  Name    : Servo Motor                       
//  Author  : Jose Luis Figueroa                                
//  Date    : 15 April, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Control a Servo motor                                         
//**************************************************************//
#include <Arduino.h>
#include <Servo.h>

//Pin assignment
const uint8_t SRV_PIN = 9;

//Instance
Servo servo;

void setup() 
{
  servo.attach(SRV_PIN);
}

void loop() 
{
  servo.write(90);
  delay(1000);

  servo.write(180);
  delay(1000);

  servo.write(0);
  delay(1000);

  for(uint8_t p=0; p<=180; p+=5)
  {
    servo.write(p);
    delay(50);
  }

}