/***************************************************************** 
 * Name    : Queues
 * Author  : Jose Luis Figueroa  
 * Date    : 25 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Pass data between threads using queues and memory pool
******************************************************************/
#include <mbed.h>

//Constant
#define TIME_RATE 1000ms

//Structure
typedef struct 
{
  float voltage;    //AD result of measured voltage
  float current;    //AD result of measured current
  uint32_t counter; //A counter value
} message_t;  //It is structure with three variables


/***************************************************************** 
 * Thread functions
******************************************************************/
//Create a Memory pool
MemoryPool<message_t, 16> mpool;
//Create queue with same capacity as Memory pool
Queue<message_t, 16> queue;

Thread thread;
void send_thread(void)
{
  uint32_t i = 0;
  while (true)
  {
    //Simulate data update, example: reading an ADC
    i++;
    //Allocate a memory block from the memory pool
    message_t *message = mpool.alloc();
    message->voltage = (i * 0.1) * 33;
    message->current = (i * 0.1) * 11;
    message->counter = i;
    //Put a message at end of queue
    queue.put(message);
    ThisThread::sleep_for(TIME_RATE);
  }
}


/***************************************************************** 
 * Main
******************************************************************/
int main() 
{
  thread.start(callback(send_thread));
  while (true)
  {
    //Get or wait for a message from the queue
    osEvent evt = queue.get();
    if(evt.status == osEventMessage)
    {
      message_t *message = (message_t *)evt.value.p;
      //%f doesn't work on PlatformIO
      printf("\nVoltage: %d V\n\r", message->voltage);
      printf("Current: %d A\n\r", message->current);
      printf("Number of cycles: %u\n\r", message->counter);
      mpool.free(message);
    }
  }
}