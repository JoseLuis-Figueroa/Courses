//**************************************************************//
//  Name    : Two motors                        
//  Author  : Jose Luis Figueroa                                
//  Date    : 13 April, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Control two motors                                         
//**************************************************************//
#include <Arduino.h>

//Pins assignments
const uint8_t PWM_1_PIN = 2;
const uint8_t DIR_1A_PIN = 22;
const uint8_t DIR_2A_PIN = 24;
const uint8_t PWM_2_PIN = 3;
const uint8_t DIR_3A_PIN = 26;
const uint8_t DIR_4A_PIN = 28;

//Variables & constants
const uint8_t max_speed = 255;
const uint8_t half_speed = 127;
const uint16_t delay_1s = 1000;

//Functions declaration
void drive_forward(uint8_t speed, uint16_t time);
void drive_left(uint8_t speed, uint16_t time);
void drive_right(uint8_t speed, uint16_t time);
void drive_backward(uint8_t speed, uint16_t time);
void stop(uint16_t time);

void setup()
{
  //Pins configuration
  pinMode(PWM_1_PIN, OUTPUT);
  pinMode(PWM_2_PIN, OUTPUT);
  pinMode(DIR_1A_PIN, OUTPUT);
  pinMode(DIR_2A_PIN, OUTPUT);
  pinMode(DIR_3A_PIN, OUTPUT);
  pinMode(DIR_4A_PIN, OUTPUT);
}

void loop() 
{
  //Call to functions
  drive_forward(max_speed, delay_1s);
  //Turn left at half speed
  drive_left(half_speed, delay_1s);
  //Turn right at half speed
  drive_right(half_speed, delay_1s);
  drive_backward(half_speed, delay_1s);
  stop(delay_1s);
}


//Functions definition
void drive_forward(uint8_t speed, uint16_t time)
{
  //Left wheel
  digitalWrite(DIR_1A_PIN, HIGH);
  digitalWrite(DIR_2A_PIN, LOW);
  analogWrite(PWM_1_PIN, speed);
  //Right wheel
  digitalWrite(DIR_3A_PIN, HIGH);
  digitalWrite(DIR_4A_PIN, LOW);
  analogWrite(PWM_2_PIN, speed);
  delay(time);
  //Stop spinning
  analogWrite(PWM_1_PIN, 0);
  analogWrite(PWM_2_PIN, 0);
}

void drive_left(uint8_t speed, uint16_t time)
{
  //Left wheel (Brake)
  digitalWrite(DIR_1A_PIN, LOW);
  digitalWrite(DIR_2A_PIN, LOW);
  analogWrite(PWM_1_PIN, 0);
  //Right wheel (Half speed)
  digitalWrite(DIR_3A_PIN, HIGH);
  digitalWrite(DIR_4A_PIN, LOW);
  analogWrite(PWM_2_PIN, speed);
  delay(time);
  //Stop spinning
  analogWrite(PWM_1_PIN, 0);
  analogWrite(PWM_2_PIN, 0);
}

void drive_right(uint8_t speed, uint16_t time)
{
  //Left wheel (Half speed)
  digitalWrite(DIR_1A_PIN, HIGH);
  digitalWrite(DIR_2A_PIN, LOW);
  analogWrite(PWM_1_PIN, speed);
  //Right wheel (Brake)
  digitalWrite(DIR_3A_PIN, LOW);
  digitalWrite(DIR_4A_PIN, LOW);
  analogWrite(PWM_2_PIN, 0);
  delay(time);
  //Stop spinning
  analogWrite(PWM_1_PIN, 0);
  analogWrite(PWM_2_PIN, 0);
}

void drive_backward(uint8_t speed, uint16_t time)
{
  //Left wheel (Half speed)
  digitalWrite(DIR_1A_PIN, LOW);
  digitalWrite(DIR_2A_PIN, HIGH);
  analogWrite(PWM_1_PIN, speed);
  //Right wheel (Half speed)
  digitalWrite(DIR_3A_PIN, LOW);
  digitalWrite(DIR_4A_PIN, HIGH);
  analogWrite(PWM_2_PIN, speed);
  delay(time);
  //Stop spinning
  analogWrite(PWM_1_PIN, 0);
  analogWrite(PWM_2_PIN, 0);
}

void stop(uint16_t time)
{
  //Left wheel (Stop)
  digitalWrite(DIR_1A_PIN, LOW);
  digitalWrite(DIR_2A_PIN, LOW);
  analogWrite(PWM_1_PIN, 0);
  //Right wheel (Stop)
  digitalWrite(DIR_3A_PIN, LOW);
  digitalWrite(DIR_4A_PIN, LOW);
  analogWrite(PWM_2_PIN, 0);
  delay(time);
}
