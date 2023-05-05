
/***************************************************************** 
 * Name    : Two threads (Leds)
 * Author  : Jose Luis Figueroa  
 * Date    : 19 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Create two threads (Main and thread2) to continue
 *         : switching two leds.
******************************************************************/
#include <mbed.h>

//Blinking rate in milliseconds
#define BLINKING_RATE1 1000ms
#define BLINKING_RATE2 500ms

//Object instances
DigitalOut led1(LED1);
DigitalOut led2(D9);

//Thread instance
Thread thread2;

//Thread function
void led2_thread()
{
  while (true)
  {
    led1 = !led1;
    ThisThread::sleep_for(BLINKING_RATE1);
  }
}


/***************************************************************** 
 * Main
******************************************************************/
int main() 
{

  //Start thread2 executing
  thread2.start(led2_thread);

  while(1) 
  {
    led2 = !led2;
    ThisThread::sleep_for(BLINKING_RATE2);
  }
}