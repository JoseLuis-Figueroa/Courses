//**************************************************************//
//  Name    : Analog Voltage                       
//  Author  : Jose Luis Figueroa                                
//  Date    : 20 Feb, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Read the analog voltage (ADC0)                                      
//**************************************************************//
//Pin
const uint8_t ADC0_PIN = A0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int val = analogRead(ADC0_PIN);
    float voltage = val * 5.0 / 1023;
    Serial.println(voltage);
    delay(100);
}