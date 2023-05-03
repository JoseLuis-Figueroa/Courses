//**************************************************************//
//  Name    : Button                             
//  Author  : Jose Luis Figueroa                                
//  Date    : 16 Feb, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Button example                                     
//**************************************************************//
//Pins
uint8_t BTN_PIN = 22;
uint8_t LED_PIN = 2;


void setup()
{   
    //Set up button pin as input. It is not necessary as Arduino 
    //set up all the pins as input by defaul.
    pinMode(BTN_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    //Pull-up logic (Reverse logic with button)
    if(digitalRead(BTN_PIN) == LOW)
    {
        digitalWrite(LED_PIN, HIGH);
    }else 
    {
        digitalWrite(LED_PIN, LOW);
    }

}