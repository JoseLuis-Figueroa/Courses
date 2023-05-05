/***************************************************************** 
 * Name    : Semaphore and Mutex
 * Author  : Jose Luis Figueroa  
 * Date    : 2 nov, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Printer is protected by a semaphore and any two 
 *         : threads can be executing printer() at any one time. 
 *         : resource1() is protected by a mutex and the interrupt
 *         : input disable thread t2.
******************************************************************/
#include "mbed.h"

/***************************************************************** 
 * Declarations
******************************************************************/
//Object instances
DigitalOut T2_led (D7);    //Led indicator
DigitalOut T3_led (D8);    //Led indicator
DigitalOut Res1_act (D9);  //Led indicator
InterruptIn button (D2);

//Variable
bool t2_en=1;

//Functions
void printer(void const *name);
void resource1 (void);

/***************************************************************** 
 * Thread functions and interrupt
******************************************************************/
Mutex Res_mutex; 
Semaphore print_sem(2); 

//Turn on LED and send "Th 2" when t2_en=1
Thread t2;         //Thread 2
void t2_task()
{
  while(1){
    if(t2_en)
    {
      T2_led = 1;
      resource1();
      printer("Th 2");
      T2_led = 0;
      thread_sleep_for(200);
    }
  }
}

//Turn on LED and send "Th 3" 
Thread t3;         //Thread 3
void t3_task()
{
  while(1)
  {
    T3_led = 1;
    printer("Th 3");
    resource1();
    T3_led = 0;
    thread_sleep_for(200);
  }
}

//Produce 400ms and it is protected by a mutex
void resource1 (void)
{
  Res_mutex.lock();
  int j;                      
  Res1_act=1;
  for (j=0;j<1000;j++) 
  {
    wait_us(200);
  }
  Res1_act=0;
  thread_sleep_for(200);
  Res_mutex.unlock();              
}

//Send a message via UART and it is protected by semaphore
void printer(void const *name) 
{
  print_sem.acquire();
  printf("%s\n\r", (const char*)name);
  thread_sleep_for(200);
  print_sem.release();
}

//External interrupt
void ISR()
{
  if(button==0)
  {
    t2_en=!t2_en;
  }
}

/***************************************************************** 
 * Main
******************************************************************/
int main (void) 
{            
  //Launch the threads and interrupt
  t2.start(t2_task);
  t3.start(t3_task);
  button.fall(&ISR);  
  
  while(1)
  {
    printer("Th 1");
    thread_sleep_for(200);
  }
}