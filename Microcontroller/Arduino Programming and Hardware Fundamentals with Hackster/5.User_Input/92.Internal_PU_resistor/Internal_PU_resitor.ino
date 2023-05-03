//**************************************************************//
//  Name    : Internal_PU_resistor                             
//  Author  : Jose Luis Figueroa                                
//  Date    : 17 Feb, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Use internal pull up resistor to control a button                               
//**************************************************************//
//Pins
const uint8_t BTN_PIN = 22;
const uint8_t LED_PIN = 2;

//Variable
int btn_prev;

void setup()
{
    //Configure pins
    pinMode(BTN_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);

    //Set initial Led state
    digitalWrite(LED_PIN, LOW);
}

void loop()
{
    int btn_state;

    //Read button state
    btn_state = digitalRead(BTN_PIN);

    //Flash LED on rising edge (let go of button)
    if(btn_prev == LOW && btn_state == HIGH)
    {
        digitalWrite(LED_PIN, HIGH);
        delay(500);
        digitalWrite(LED_PIN, LOW);
    }

    //Remember button state for next iteration
    btn_prev = btn_state;
}