//**************************************************************//
//  Name    : Push_count                             
//  Author  : Jose Luis Figueroa                                
//  Date    : 17 Feb, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Push button a counter is increamented                              
//**************************************************************//
//Pins
const uint8_t BTN_PIN = 22;

//Variable
uint16_t counter = 0;
uint8_t btn_prev;

void setup()
{
    //Set the serial comunication
    Serial.begin(9600);
    //Set the pull up resistor
    pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop()
{
    //Actual button state
    uint8_t btn_state;
    
    //Read button state
    btn_state = analogRead(BTN_PIN);

    //Button immediately works after pushing
    if(btn_state == LOW && btn_prev == HIGH)
    {
        counter++;
        Serial.println(counter);
    }

    btn_prev = btn_state;
}