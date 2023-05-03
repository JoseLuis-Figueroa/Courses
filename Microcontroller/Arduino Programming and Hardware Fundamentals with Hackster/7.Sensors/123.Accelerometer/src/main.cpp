//**************************************************************//
//  Name    : Accelerometer                    
//  Author  : Jose Luis Figueroa                                
//  Date    : 31 March, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Measure the x, y and z position
//**************************************************************//
#include <Arduino.h>

//Pins
const uint8_t X_PIN = A0;
const uint8_t Y_PIN = A1;
const uint8_t Z_PIN = A2;

//Volts per G-force
const float sensitivity = 0.33;

void setup()
{
  Serial.begin(9600);
  analogReference(EXTERNAL);
}

void loop()
{
  float x, y, z;

  //Read pins and convert to G
  x = (analogRead(X_PIN) - 512) * 3.3 / (sensitivity * 1023);
  y = (analogRead(Y_PIN) - 512) * 3.3 / (sensitivity * 1023);
  z = (analogRead(Z_PIN) - 512) * 3.3 / (sensitivity * 1023);

  //Display acceleration 
  Serial.print("x:");
  Serial.print(x);
  Serial.print("   y:");
  Serial.print(y);
  Serial.print("   z:");
  Serial.println(z);

  delay(200);

}