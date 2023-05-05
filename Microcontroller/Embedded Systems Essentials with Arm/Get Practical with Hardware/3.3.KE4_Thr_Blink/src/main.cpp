/***************************************************************** 
 * Name    : Thread blink
 * Author  : Jose Luis Figueroa  
 * Date    : 20 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Led blinks 3 times each half second and off 2 seconds
******************************************************************/
#include <mbed.h>

//Timings
#define BLINKING_RATE 1000ms
#define TIME_RATE 10000ms

//Object instances
Thread led_sw_thread;
DigitalOut led1(LED1);

//Variable
volatile bool running = true;

//Function
void blink(DigitalOut *led)
{
  while (true)
  {
    if (running)
    {
      *led = 1;
      ThisThread::sleep_for(500ms);
      *led = 0;
      ThisThread::sleep_for(500ms);
    }
  }
}


/***************************************************************** 
 * Main
******************************************************************/
int main() 
{
  //Start led_sw_thread executing
  led_sw_thread.start(callback(blink, &led1));
  while(1) 
  {
    ThisThread::sleep_for(2500ms);
    running = false;
    ThisThread::sleep_for(2000ms);
    running = true;
  }
}