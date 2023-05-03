//**************************************************************//
//  Name    : Buzzers and tones                             
//  Author  : Jose Luis Figueroa                                
//  Date    : 23 March, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   :                                      
//**************************************************************//
#include <Arduino.h>

//Pins
const uint8_t SPEAKER_PIN = 9;

void setup() {
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  //Set the tone
  tone(SPEAKER_PIN, 440, 500);
  delay(1000);
}