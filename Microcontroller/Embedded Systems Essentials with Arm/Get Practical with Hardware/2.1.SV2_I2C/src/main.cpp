/***************************************************************** 
 * Name    : I2C
 * Author  : Jose Luis Figueroa  
 * Date    : 14 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Reads temperature from DS1631 (I2C bus) and display 
 * on PC
******************************************************************/
#include <mbed.h>

// Object instances
I2C temp_sensor(I2C_SDA, I2C_SCL);  
BufferedSerial pc(USBTX, USBRX, 9600);

//Variables
const uint8_t temp_addr = 0x90; //I2C addres of DS1631
char commands[] = {0x51, 0xAA};
char read_temp[2];

int main() 
{
  while(1) 
  {
    //Write 0x51 to 0x90 to start temperature conversion
    temp_sensor.write(temp_addr, &commands[0], 1, false);
    thread_sleep_for(500);
    //Write 0xAA to 0x90 to read the last converted temperature
    temp_sensor.write(temp_addr, &commands[1], 1, false);
    //Read the temperature into the read_temperature array
    temp_sensor.read(temp_addr, read_temp, 2);
    //Convert temperature to Celsius
    float temp = (float((read_temp[0] << 8) | read_temp[1]) / 256);
    //Print temperature to the serial monitor
    printf("Temp = %d.%d\r\n", int(temp), int((temp-int(temp))*10));
  }
}