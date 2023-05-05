/***************************************************************** 
 * Name    : Leds
 * Author  : Jose Luis Figueroa  
 * Date    : 6 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Led1 (Pin LED1) and led2 (pin D10)
******************************************************************/
#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE 1000ms

int main()
{
  // Initialise the digital pin LED1 and D10 as an output
  DigitalOut led1(LED1); // Embedded led
  DigitalOut led2(D10);  // Connected led

  while (true)
  {
    led1 = !led1;
    ThisThread::sleep_for(BLINKING_RATE);
    led1 = !led1;
    led2 = !led2;
    ThisThread::sleep_for(BLINKING_RATE);
  }
}