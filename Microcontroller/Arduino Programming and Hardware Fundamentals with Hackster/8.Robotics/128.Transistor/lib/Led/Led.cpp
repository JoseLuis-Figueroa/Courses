//**************************************************************//
//  Name    : Led Implementation                                   
//  Author  : Jose Luis Figueroa                                
//  Date    : 15 Feb, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Led library                                          
//**************************************************************//
#include "Arduino.h"
#include "Led.h"

Led::Led(uint8_t pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
};

void Led::on()
{
    digitalWrite(pin, HIGH);
}

void Led::off()
{
    digitalWrite(pin, LOW);
}

//Flash the Led
void Led::flash(uint16_t ms_)
{   /* Flash the Led
    ms_: number of miliseconds
    */
    digitalWrite(pin, HIGH);
    delay(ms_);
    digitalWrite(pin, LOW);
    delay(ms_);
}


void Led::brightness(uint32_t bits_values_, uint16_t value_)
{
    /* Change the brightness of Led
    bits_value_: Maximum number represented by the bits 
    {255(8 bits)|511(9 bits)|1023(10 bits)|etc}
    value_: value sent to Led
    */

    //bits_ chooses between 255 (8 bits) or higher
    if(bits_values_ == 255)
    {
        analogWrite(pin, value_);
    }else
    {
        //map() adjust the bits number to 8 bits(255)
        uint16_t brightness = map(value_, 0, bits_values_, 0, 255);
        analogWrite(pin, brightness);
    }
}


