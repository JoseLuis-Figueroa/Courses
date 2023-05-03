//**************************************************************//
//  Name    : Toggle_Button                             
//  Author  : Jose Luis Figueroa                                
//  Date    : 16 Feb, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Toggle a button and change the state of a Led                                  
//**************************************************************//
//Pins
const uint8_t BTN_PIN = 22;
const uint8_t LED_PIN = 2;
//Variable
uint8_t flag = 0;

void setup()
{
    //Set up the led
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    //Pull-up logic (Reverse logic with button)
    if(digitalRead(BTN_PIN) == LOW && flag == 0)
    {
        if(digitalRead(LED_PIN) == HIGH)
        {
            digitalWrite(LED_PIN, LOW);
            delay(200);
            flag = 1;
        }else
        {
            digitalWrite(LED_PIN, HIGH);
            delay(200);
            flag = 1;
        }
    }else if (digitalRead(BTN_PIN) == HIGH)
    {
        flag = 0;
    }
}