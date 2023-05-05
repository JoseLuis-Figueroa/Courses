/***************************************************************** 
 * Name    : Thread control
 * Author  : Jose Luis Figueroa  
 * Date    : 19 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : One thread (Main) is controlling another one (Thread2)
******************************************************************/
#include <mbed.h>

//Timings
#define BLINKING_RATE 1000ms
#define TIME_RATE 10000ms

//Object instance and variable
DigitalOut led1(LED1);
volatile bool running = true;

//Thread instance
Thread thread2;

//Blink function toogles the led in a long running loop
void blink(DigitalOut *led1)
{
  while(running)
  {
    *led1 = !*led1;
    ThisThread::sleep_for(BLINKING_RATE);
  }
}


/***************************************************************** 
 * Main
******************************************************************/
int main() 
{
  //Start thread2 executing
  thread2.start(callback(blink, &led1));
  //This sets how long thread2 will be able to run
  ThisThread::sleep_for(TIME_RATE);
  running = false;
  //Wait for thread2 to terminate
  thread2.join();
}