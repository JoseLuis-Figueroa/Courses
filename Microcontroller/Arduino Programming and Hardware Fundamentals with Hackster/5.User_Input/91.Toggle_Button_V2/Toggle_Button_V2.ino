//**************************************************************//
//  Name    : Toggle_Button_V2                             
//  Author  : Jose Luis Figueroa                                
//  Date    : 17 Feb, 2021 
//  Board   : Arduino
//  Version : 1.0                                               
//  Notes   : Toggle a button and change the state of a Led                                  
//**************************************************************//
const uint8_t BTN_PIN = 22;
const uint8_t LED_PIN = 2;
 
// We need to remember the previous button state between loops
uint8_t btn_prev = HIGH;
 
// Remember the LED state between loops
uint8_t led_state = LOW;
 
void setup() 
{  
  // Set up pins
  pinMode(BTN_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  // Set LED to default off
  digitalWrite(LED_PIN, led_state);
}

void loop()
{
  uint8_t btn_state;
  
  // Read current button state
  btn_state = digitalRead(BTN_PIN);
  
  // If the button was previously HIGH and now LOW, it's been pressed
  if ( (btn_prev == HIGH) && (btn_state == LOW) ) {
    
    // Toggle the LED
    if ( led_state == LOW ) {
      led_state = HIGH;
    } else {
      led_state = LOW;
    }
    digitalWrite(LED_PIN, led_state);
  }
  
  // Remember the previous button state for the next loop iteration
  btn_prev = btn_state;
}