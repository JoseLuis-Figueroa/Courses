/***************************************************************** 
 * Name    : Temperature sensor with LCD
 * Author  : Jose Luis Figueroa  
 * Date    : 15 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Read the temperature of the DS1631 and display it on
 *         : a LCD and on the PC.
******************************************************************/
#include <mbed.h>

//Pins Assignment 
#define ENABLE 0x08   //Will be ORed in to data value to strobe E 
#define COMMAND 0x00  //used to clear RS line to 0
#define DATA 0x04     //used to set RS line to 1
#define MOSI D11 
#define MISO D12
#define SCLK D13
#define CS D10

//Object instances
I2C temp_sensor(I2C_SDA, I2C_SCL);  
BufferedSerial pc(USBTX, USBRX, 9600);
SPI ser_port(MOSI, MISO, SCLK); // Initialise SPI, using default settings
DigitalOut cs(CS);

//Variables
const uint8_t temp_addr = 0x90; //I2C addres of DS1631
char commands[] = {0x51, 0xAA, 0xA1};
char read_temp[2];
char lcd_result[9];

//Function Prototypes
void clr_lcd(void);
void init_lcd(void);
void print_lcd(const char *string);
void shift_out(int data);
void write_cmd(int cmd);
void write_data(char c); 
void write_4bit(int data);


/***************************************************************** 
 * Main
******************************************************************/
int main() 
{
  init_lcd();
  clr_lcd();
  print_lcd("Temperature is");
  while (1) 
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

    //Convert float value in temp to character string in lcd_result
    sprintf(lcd_result, "%d.%d", int(temp), int((temp-int(temp))*10));    
    write_cmd(0xc0);  // Set cursor to start of second line
    wait_us(40);
    //Write 5 characters from string to LCD
    for(int i=0; i<4; i++)
    {
      write_data(lcd_result[i]);
    }
    print_lcd(" degrees Celsius");
  }
}       


/***************************************************************** 
 * Functions
******************************************************************/
void init_lcd(void) 
{
  thread_sleep_for (40);
  shift_out(0x30);    //function set 8-bit
  wait_us(37);
  write_cmd(0x20);    //function set
  wait_us(37);
  write_cmd(0x20);    //function set
  wait_us(37);
  write_cmd(0x0C);    //display ON/OFF
  wait_us(37);
  write_cmd(0x01);    //display clear
  wait_us(1520);
  write_cmd(0x06);    //entry-mode set
  wait_us(37);
  write_cmd(0x28);    //function set
  wait_us(37);
}

void write_4bit(int data, int mode) 
{
  int hi_n;
  int lo_n;
  //form the two 4-bit nibbles that will be sent
  hi_n = (data & 0xF0);           
  lo_n = ((data << 4) &0xF0);
  //send each word twice, strobing the Enable line
  shift_out(hi_n | ENABLE | mode); 
  wait_us(1);
  shift_out(hi_n & ~ENABLE);
  shift_out(lo_n | ENABLE | mode);
  wait_us(1);
  shift_out(lo_n & ~ENABLE);
}

void shift_out(int data) 
{
  //Invokes SPI
  cs = 0;
  ser_port.write(data);  
  cs = 1;
}

void write_cmd(int cmd) 
{
  //Write configuration commands
  write_4bit(cmd, COMMAND);  
}

void write_data(char c) 
{
  //Write data
  write_4bit(c, DATA);    //1 for data mode
}

void clr_lcd(void) 
{
  write_cmd(0x01);    
  wait_us(1520);
}

void print_lcd(const char *string) 
{
  //Loop will terminate when null-value(char) is encountered
  while(*string)
  {
    //Set char(one caracter) and increase the pointer
    //(next value of the string)
    write_data(*string++);
    wait_us(40);
  }
}
