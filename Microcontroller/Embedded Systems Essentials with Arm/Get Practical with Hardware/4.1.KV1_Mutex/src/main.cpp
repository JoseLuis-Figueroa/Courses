/***************************************************************** 
 * Name    : Mutex
 * Author  : Jose Luis Figueroa  
 * Date    : 12 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Mutex allows access to a shared resource between two
 *         : threads in this case the UART port.
******************************************************************/
#include <mbed.h>

//Constant
#define TIME_RATE 1000ms

//Create Mutex named stdio_mutex
Mutex stdio_mutex;
//Thread instances
Thread t2;
Thread t3;


/***************************************************************** 
 * Thread functions
******************************************************************/
void notify(const char *name, int state)
{
  //Lock is used to avoid multiple uses of USB protocol
  stdio_mutex.lock();
  printf("%s: %d\n\r", name, state);
  //Unlock the UBS protocol
  stdio_mutex.unlock();
}

void test_thread(void const *args)
{
  while(true)
  {
    notify((const char *)args, 0);
    ThisThread::sleep_for(TIME_RATE);
    notify((const char *)args, 1);
    ThisThread::sleep_for(TIME_RATE);
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