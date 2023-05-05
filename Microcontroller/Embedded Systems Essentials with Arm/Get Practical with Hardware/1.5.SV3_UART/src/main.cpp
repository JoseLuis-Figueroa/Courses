/***************************************************************** 
 * Name    : UART
 * Author  : Jose Luis Figueroa  
 * Date    : 12 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Sends messages since board to PC terminal.
******************************************************************/
#include <mbed.h>

//Serial config(TX, RX, frequency)
//Start bit, 8 bits of data and stop bit (Default configuration)
BufferedSerial pc(USBTX, USBRX, 9600);
int cycle=0;

int main() 
{
  while(1) 
  {
    printf("Hello World. This is loop %i \n\r", cycle);
    thread_sleep_for(500);
    cycle++;
  }
}