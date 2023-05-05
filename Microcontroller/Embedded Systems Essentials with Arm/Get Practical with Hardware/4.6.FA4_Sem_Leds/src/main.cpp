/***************************************************************** 
 * Name    : Semaphore with Leds
 * Author  : Jose Luis Figueroa  
 * Date    : 1 nov, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Semaphore=1; Leds flash in turn, thread numbers apper
 *         : in turn on the terminal, program cycles every 400ms.
 *         : Semaphore=2; leds flash 2 together, then one on its
 *         : own, thread numbers apper in turn on the terminal, 
 *         : program overall cycles every 400ms.
 *         : Semaphore=3; leds flashing is synchronised, thread
 *         : numbers apper in turn on the terminal, program overall
 *         : cycles every 600ms.
******************************************************************/
#include "mbed.h"
 
/***************************************************************** 
 * Declarations
******************************************************************/
//Object instances
DigitalOut T1_led (D7);    //Led indicator
DigitalOut T2_led (D8);    //Led indicator
DigitalOut T3_led (D9);    //Led indicator
        
//Function
void printer(void const *name);


/***************************************************************** 
 * Thread functions
******************************************************************/
Semaphore print_sem(3); 

Thread t2;         
void t2_task()
{
  while(1)
  {
    T2_led = 1;
    printer("Th 2");
    T2_led = 0;
    thread_sleep_for(200);
  }
}

Thread t3;
void t3_task()
{
  while(1)
  {
    T3_led = 1;
   printer("Th 3");
    T3_led = 0;
    thread_sleep_for(200);
  }
}

//Send a messabe via UART (Use semaphore)
void printer(void const *name) 
{
    print_sem.acquire();
    printf("%s\n\r", (const char*)name);
    thread_sleep_for(200);
    print_sem.release();
}


/***************************************************************** 
 * Main
******************************************************************/
int main (void) 
{         
    //Launch the threads   
    t2.start(t2_task);
    t3.start(t3_task);

    while(1)
    {
      T1_led=1;
      printer("Th 1");
      T1_led=0;
      thread_sleep_for(200);
    }
}