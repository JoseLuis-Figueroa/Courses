//**************************************************************//
//  Name    : Software Debouncing                             
//  Author  : Jose Luis Figueroa                                
//  Date    : 17 Feb, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Create a software debouncing to remove the ripple 
//          : signals                           
//**************************************************************//
//Pins
const uint8_t BTN_PIN = 22;

//Variables and constants
const uint8_t DEBOUNCE_DELAY = 50; //ms
uint8_t counter = 0;
uint8_t btn_state = HIGH;
uint8_t btn_prev = HIGH;
uint16_t last_debounce_time = 0;

void setup()
{
    pinMode(BTN_PIN, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop()
{
    uint8_t btn_read = digitalRead(BTN_PIN);

    //Review when the button changed states (Take current time)
    if(btn_read != btn_prev)
    {
        //Return ms the processor has been running since we first
        //reset or powered it on
        last_debounce_time = millis();
    }

    //Wait until 50ms to enter to the condition
    if(millis() > (last_debounce_time + DEBOUNCE_DELAY))
    {
        //Review if the button state really changes to avoid the
        //ripple signals
        if(btn_read != btn_state)
        {
            btn_state = btn_read;
            //Check if the button is pressed
            if(btn_state == LOW)
            {
                counter++;
                Serial.println(counter);
            }
        }

    }

    //Remember the previous state for next loop()
    btn_prev = btn_read;

}