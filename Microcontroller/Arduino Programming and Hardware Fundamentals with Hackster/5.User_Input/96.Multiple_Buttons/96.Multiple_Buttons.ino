//**************************************************************//
//  Name    : Multiple Buttons                             
//  Author  : Jose Luis Figueroa                                
//  Date    : 18 Feb, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Use multiple buttons                        
//**************************************************************//
//Pins
const uint8_t BTN1_PIN = 22;
const uint8_t BTN2_PIN = 24;

//Variables and constants
const uint8_t DEBOUNCE_DELAY = 50;
uint8_t btn1_state = HIGH;
uint8_t btn2_state = HIGH;
uint8_t btn1_prev = HIGH;
uint8_t btn2_prev = HIGH;
uint8_t last_debounce_time1 = 0;
uint8_t last_debounce_time2 = 0;
uint16_t counter = 0;


void setup()
{
    Serial.begin(9600);
    pinMode(BTN1_PIN, INPUT_PULLUP);
    pinMode(BTN2_PIN, INPUT_PULLUP);
}

void loop()
{
    uint8_t btn1_read = digitalRead(BTN1_PIN);
    uint8_t btn2_read = digitalRead(BTN2_PIN);

    //Increase counter
    if (btn1_read != btn1_prev)
    {
        last_debounce_time1 = millis();
    }

    if (millis() > last_debounce_time1 + DEBOUNCE_DELAY)
    {
        if (btn1_read != btn1_state)
        {
            btn1_state = btn1_read;
            if (btn1_state == LOW)
            {
                counter++;
                Serial.println(counter);
            }
        }
    }

    btn1_prev = btn1_read;

    //Decreace counter
    if(btn2_read != btn2_prev)
    {
        last_debounce_time2 = millis();
    }

    if(millis() > last_debounce_time2 + DEBOUNCE_DELAY)
    {
        if(btn2_read != btn2_state)
        {
            btn2_state = btn2_read;
            if(btn2_read == LOW)
            {
                counter--;
                Serial.println(counter);
            }
        }
    }

    btn2_prev = btn2_read;

}
