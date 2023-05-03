//**************************************************************//
//  Name    : Digital_Theremin                     
//  Author  : Jose Luis Figueroa                                
//  Date    : 30 March, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Measure the distance between 0 to 50cm and buzzer
//          : plays a frequency according to the distance 
//          : (0 to 500Hz)
//**************************************************************//
#include <Arduino.h>

//Pins 
const uint8_t TRIG_PIN = 2;
const uint8_t ECHO_PIN = 3;
const uint8_t BZR_PIN = 5;

//Variables
const uint8_t trig_delay = 15;

void setup() 
{
  Serial.begin(9600);
  //I/O configuration
  pinMode(BZR_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() 
{
  uint64_t duration;
  uint16_t frequency;

   //Send out a pulse (trigger) to start the measurement
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(trig_delay);
  digitalWrite(TRIG_PIN, LOW);

  //Measure time of pulse on ECHO pin
  duration = pulseIn(ECHO_PIN, HIGH);

  //Convert time to distance. But frequency will be changed according
  //to distance
  frequency = duration / 58.8;
  
  //Measure distance between 0 to 50cm
  if(frequency <= 50)
  { //Multiply frequency by 10 to get audible frequencies
    tone(BZR_PIN, frequency*10, 300);
  }

  delay(100);

}