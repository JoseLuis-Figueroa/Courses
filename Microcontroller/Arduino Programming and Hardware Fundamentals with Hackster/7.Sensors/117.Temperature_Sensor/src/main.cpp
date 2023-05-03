//**************************************************************//
//  Name    : Temperature sensor                           
//  Author  : Jose Luis Figueroa                                
//  Date    : 29 March, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Measure the temperature using LM35                              
//**************************************************************//
#include <Arduino.h>

//Pins
const uint8_t TMP_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float voltage;
  uint16_t temperature;

  //Read voltage and convert to temperature
  voltage = (analogRead(TMP_PIN) * 5.0) / 1023;
  temperature = 100.0 * voltage;

  //Print voltage and temperature
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" deg C: ");
  Serial.println(temperature);
  delay(200);
}