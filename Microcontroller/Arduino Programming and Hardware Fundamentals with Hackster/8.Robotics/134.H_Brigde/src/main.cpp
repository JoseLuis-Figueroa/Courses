//**************************************************************//
//  Name    : H bridge                        
//  Author  : Jose Luis Figueroa                                
//  Date    : 13 April, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : H bridge is used to change the direction of DC motor                                         
//**************************************************************//
#include <Arduino.h>

//Pins assignments
const uint8_t PWM_PIN = 2;
const uint8_t DIR_1A_PIN = 22;
const uint8_t DIR_2B_PIN = 24; 

void setup()
{
  //Pins configuration
  pinMode(PWM_PIN, OUTPUT);
  pinMode(DIR_1A_PIN, OUTPUT);
  pinMode(DIR_2B_PIN, OUTPUT);
}

void loop()
{
  //One direction at half speed
  digitalWrite(DIR_1A_PIN, HIGH);
  digitalWrite(DIR_2B_PIN, LOW);
  analogWrite(PWM_PIN, 127);
  delay(1000);

  //Stop spinning
  analogWrite(PWM_PIN, 0);
  delay(1000);

  //Other direction at full speed
  digitalWrite(DIR_1A_PIN, LOW);
  digitalWrite(DIR_2B_PIN, HIGH);
  analogWrite(PWM_PIN, 255);
  delay(1000);

  //Brake
  digitalWrite(DIR_1A_PIN, LOW);
  digitalWrite(DIR_2B_PIN, LOW);
  analogWrite(PWM_PIN, 0);
  delay(1000);

}