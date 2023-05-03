//**************************************************************//
//  Name    : Voltage Divider                       
//  Author  : Jose Luis Figueroa                                
//  Date    : 20 Feb, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Create a Voltmeter. Press button and measure Voltage                      
//**************************************************************//
#include "Button.h"

//Pins
const uint8_t adc0_pin = A0;
const uint8_t BTN_PIN = 22;

//Instance
Button button(BTN_PIN);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    if (button.push() == HIGH)
    {
    int val = analogRead(adc0_pin);
    float voltage = val * 5.0 / 1023;
    Serial.println(voltage);
    }
}