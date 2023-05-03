//**************************************************************//
//  Name    : Controlling_LEDs                             
//  Author  : Jose Luis Figueroa                                
//  Date    : 7 April, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   :                                  
//**************************************************************//
#include <Arduino.h>
#include <avr8-stub.h>
#include <app_api.h>

//Pins
const int led_green = 22;
const int led_red = 24;
const int led_yellow = 26;

void setup() {
  // Set the pins as output
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  debug_init();
}

void loop() {
  // Make LED green blink one
  digitalWrite(led_green, HIGH);
  delay(1000);
  digitalWrite(led_green, LOW);
  delay(1000);

  // Make LED red blink twice
  for (int i=0; i<2; i++){
     digitalWrite(led_red, HIGH);
    delay(1000);
    digitalWrite(led_red, LOW);
    delay(1000);
  }

  // Make LED yellow blink 3 times
    for (int i=0; i<3; i++){
     digitalWrite(led_yellow, HIGH);
    delay(1000);
    digitalWrite(led_yellow, LOW);
    delay(1000);
  }
}