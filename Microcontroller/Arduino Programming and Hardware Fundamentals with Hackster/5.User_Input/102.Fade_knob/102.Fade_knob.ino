//**************************************************************//
//  Name    : Fade knob                       
//  Author  : Jose Luis Figueroa                                
//  Date    : 22 Feb, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Use a potentiometer to adjust the brightness of an 
//          : LED                      
//**************************************************************//
//Pins
const uint8_t ADC0_PIN = A0;
const uint8_t LED_PIN = 2;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    //Read the ADC0
    int val = analogRead(ADC0_PIN);
    //Adjust the ADC digital values (10 bits) to digital output 
    //values (8 bits)
    int brightness = map(val, 0, 1023, 0, 255);

    analogWrite(LED_PIN, brightness);

}