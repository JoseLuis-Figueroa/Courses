//**************************************************************//
//  Name    : Led header                                   
//  Author  : Jose Luis Figueroa                                
//  Date    : 15 Feb, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Led library                                          
//**************************************************************//
#ifndef LED_H
#define LED_H

#include "Arduino.h"

class Led
{
private:
    //uint8_t => byte
    uint8_t pin;
public:
    Led(uint8_t pin);
    void on();
    void off();
    void flash(uint16_t ms);
    void brightness(uint32_t bits_value, uint16_t value);
};

#endif
