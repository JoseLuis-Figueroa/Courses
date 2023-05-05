/***************************************************************** 
 * Name    : Shift Register
 * Author  : Jose Luis Figueroa  
 * Date    : 8 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Send two data to a shifh register and showed on a
 *         : leds.
******************************************************************/
#include <mbed.h>

// Pins assignment
DigitalInOut cs(D10);
SPI master_port(D11, D12, D13); // MOSI, MISO, SCLK
char switch_word;               // Word to send

int main() 
{
  // Set up the SPI for 8 bits data, mode 0 operation
  master_port.format(8,0);
  // Clock frequency is 1MHz
  master_port.frequency(1000000);
  // Chip select idles high
  cs = 1;
  while(1) 
  {
    // Set up word to be transmitted
    switch_word = 0x00;
    // Select slave device and send data.
    cs = 0;
    master_port.write(switch_word);

    // Chip select idle
    cs = 1;
    thread_sleep_for(500);

    // Set up word to be transmitted
    switch_word = 0x0F;
    // Select slave device and send another data
    cs = 0;
    master_port.write(switch_word);
    thread_sleep_for(500);
  }
}