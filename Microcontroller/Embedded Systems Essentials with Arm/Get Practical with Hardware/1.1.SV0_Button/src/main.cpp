/***************************************************************** 
 * Name    : Button
 * Author  : Jose Luis Figueroa  
 * Date    : 6 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : User button (Pin PC_13) and led (pin LED1)
******************************************************************/
#include <mbed.h>

// Debounce time in milliseconds
#define DEBOUNCE_TIME 350ms

int main() 
{
  // Initialise the digital pin LED1 as an output
  DigitalOut led(LED1);
  // Initialise the digital pin button (user_button) as an input
  DigitalIn button(PC_13);

  while(1) 
  {
    //Button has negative logic (Press = 0)
    if (button == 0)
    {
      led = !led;
    }
    //debounce time 
    ThisThread::sleep_for(DEBOUNCE_TIME);
  }
}