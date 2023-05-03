//**************************************************************//
//  Name    : Button header                                   
//  Author  : Jose Luis Figueroa                                
//  Date    : 15 Feb, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Button library                                        
//**************************************************************//
#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

class Button
{
private:
    uint8_t pin;
    uint8_t btn_state;
    uint8_t btn_prev;
    uint8_t state;
    uint32_t last_debounce_time;
    const uint8_t DEBOUNCE_DELAY = 50;
public:
    Button(uint8_t pin);
    void setup();
    byte push();
    byte toggle();
    byte press();
};

#endif