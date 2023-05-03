//**************************************************************//
//  Name    : Ultrasonic Distance Sensor                       
//  Author  : Jose Luis Figueroa                                
//  Date    : 30 March, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Measure the distance and print it on the Serial
//          : Monitor                            
//**************************************************************//
#include <Arduino.h>

//Pins
const uint8_t TRIG_PIN = 2;
const uint8_t ECHO_PIN = 3;

//Variables
const uint8_t trig_delay = 15;

void setup() {
  Serial.begin(9600);
  //I/O configuration
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  uint64_t duration;
  uint32_t distance;

  //Send out a pulse (trigger) to start the measurement
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(trig_delay);
  digitalWrite(TRIG_PIN, LOW);

  //Measure time of pulse on ECHO pin
  duration = pulseIn(ECHO_PIN, HIGH);

  //Convert time to distance
  distance = duration / 58.8;
  Serial.print(distance);
  Serial.println("cm");

  //Wait at least 60ms between measurements(Measurement cycle)
  delay(100);

}