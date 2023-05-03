//**************************************************************//
//  Name    : Accelerometer                    
//  Author  : Jose Luis Figueroa                                
//  Date    : 31 March, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : 
//**************************************************************//
#include <Arduino.h>

//Pins
const uint8_t X_PIN = A0;
const uint8_t Y_PIN = A1;
const uint8_t Z_PIN = A2;
const uint8_t LED_PIN = 2;

//Volts per G-force
const float sensitivity = 0.33;

//Ideal conditions to turn on LED (G-Force)
const float ideal_x = -0.02;

void setup()
{
  Serial.begin(9600);
  analogReference(EXTERNAL);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  float x;

  //Read pins and convert to G
  x = (analogRead(X_PIN) - 512) * 3.3 / (sensitivity * 1023);

  if(x != ideal_x)
  { 
    digitalWrite(LED_PIN, HIGH);
  }else
  {
    digitalWrite(LED_PIN, LOW);
  }

  delay(200);

}