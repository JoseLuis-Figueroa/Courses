/***************************************************************** 
 * Name    : Interrupts and timers using RTOS
 * Author  : Jose Luis Figueroa  
 * Date    : 25 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Control two leds using ticker and timeout interrupts,
 *         : and a thread to read analog input and use pwm on 
 *         : another led.
******************************************************************/
#include <mbed.h>

/***************************************************************** 
 * Declarations
******************************************************************/
//Pin assignments 
#define LED2 D8
#define LED3 D9
#define AIN A0
//Constants
#define ticker_time 2000ms
#define timeout_time 1500ms

//Object instances
DigitalOut led1(LED1);
DigitalOut led2(LED2);
PwmOut led_var(LED3);
AnalogIn pot1(AIN);


/***************************************************************** 
 * Thread functions
******************************************************************/
//Each 2.0s change the state of led2
Ticker tickerflipper;
void ticker_demo()
{
  led2 = !led2;
}

//Count 1.5s and finish
Timeout timeoutflipper;
void timeout_demo()
{
  led1 = !led1;
}

//Adjust the brightness of the LED
Thread thread1;
void adjust_brightness(void const *args)
{
  float v;
  while(1)
  {
    v = pot1.read();
    led_var = 1-v;
    thread_sleep_for(500);
  }
}


/***************************************************************** 
 * Main
******************************************************************/
int main() 
{
   /*
    Lauch ticker and timeout with addresses of functions to be 
    to be attached and interval
  */
  led1 = led2 =1;
  tickerflipper.attach(&ticker_demo, ticker_time);
  timeoutflipper.attach(&timeout_demo, timeout_time);
  thread1.start(callback(adjust_brightness, &pot1));
  //Spin in loop, ticker will interrupt periodically
  while(1) 
  {
    __WFI();
  }
}