/***************************************************************** 
 * Name    : Semaphore
 * Author  : Jose Luis Figueroa  
 * Date    : 25 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Semaphore allows access to several shared resources
 *         : threads in this case the UART port.
******************************************************************/
#include <mbed.h>

//Constant
#define TIME_RATE 1000ms

//Semaphore and Threads instances
Semaphore one_slot(1);
Thread t2;
Thread t3;


/***************************************************************** 
 * Thread functions
******************************************************************/
void test_thread(void const *name)
{
  while(true)
  {
    //Wait until semaphore resource becomes available
    one_slot.acquire();
    printf("%s\n\r", (const char *)name);
    ThisThread::sleep_for(TIME_RATE);
    //Release a semaphore resource 
    one_slot.release();
  }
}


/***************************************************************** 
 * Main
******************************************************************/
int main() 
{
  //Start threads executing
  t2.start(callback(test_thread, (void *)"Th 2"));
  t3.start(callback(test_thread, (void *)"Th 3"));
  test_thread((void *)"Th 1");
}