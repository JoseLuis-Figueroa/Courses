//**************************************************************//
//  Name    : Button Implementation                                   
//  Author  : Jose Luis Figueroa                                
//  Date    : 18 Feb, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Pin uses the internal pull-up resitor. Button uses
//          : reverse logic (GND = 1 & VDD = 0)                                    
//**************************************************************//
#include "Arduino.h"
#include "Button.h"

Button::Button(uint8_t pin)
{
    this->pin = pin;
    btn_state = HIGH;
    btn_prev = HIGH;
    state = LOW;
    last_debounce_time = 0;
    setup();
};

void Button::setup()
{
    pinMode(pin, INPUT_PULLUP);
}

byte Button::push()
{
    /* Only one push so that button works*/

    uint8_t btn_read = digitalRead(pin);

    //Review when the button changed states
    if(btn_read != btn_prev)
    {
        //Return the ms the processor has been running
        last_debounce_time = millis();
    }

    //Wait until 50ms to enter to the condition
    if(millis() > last_debounce_time + DEBOUNCE_DELAY)
    {
        //Review if the btn_read really changes
        if(btn_read != btn_state)
        {
            btn_state = btn_read;
            //Check if the button is push
            if(btn_state == LOW)
            {
                state = HIGH;
            }
            else
            {
                state = LOW;
            }
        }
        else
        {
            state = LOW;
        }
    }
    else
    {
        state = LOW;
    }
    //Remember the previous state for next loop()
    btn_prev = btn_read;

    return state;
}

byte Button::toggle()
{
    /*Change the state(High/Low) of the button with each push*/

    uint8_t btn_read = digitalRead(pin);

    //Review when the button changed states
    if(btn_read != btn_prev)
    {
        last_debounce_time = millis();
    }

    //Wait until 50ms to enter to the condition
    if (millis() > last_debounce_time + DEBOUNCE_DELAY)
    {
        //Review if the btn_read really changes
        if(btn_read != btn_state)
        {
            btn_state = btn_read;
            //Check if the button is pressed
            if(btn_state == LOW)
            {
                if(state == LOW)
                {
                    state = HIGH;
                }else
                {
                    state = LOW;
                }
            }
        }
    }
    //Remember the previous state for next loop()
    btn_prev = btn_read;

    return state;
}

byte Button::press()
{
    /*Button continues working with press*/

    uint8_t btn_read = digitalRead(pin);
    
    //Review when the button changed states
    if (btn_read != btn_prev)
    {
        last_debounce_time = millis();
    }

    //Wait until 50ms to enter to the condition
    if (millis() > last_debounce_time + DEBOUNCE_DELAY)
    {
        if(btn_read == LOW)
        {
            state = HIGH;
        }else
        {
            state = LOW;
        }
        
    }
    //Remember the previous state for next loop()
    btn_prev = btn_read;

    return state;
}

