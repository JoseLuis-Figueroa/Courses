/***************************************************************** 
 * Name    : Thread Lab
 * Author  : Jose Luis Figueroa  
 * Date    : 20 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Perform 4 tasks: Read temperature (High priority), 
 *         : LCD counter, LED brightness and blink an LED.
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
#define AIN A0
#define LED1 D8
#define LED2 D9

//Protocols instances
I2C temp_sensor(I2C_SDA, I2C_SCL);  
BufferedSerial pc(USBTX, USBRX, 9600);
SPI ser_port(MOSI, MISO, SCLK); 
//Peripherals instances
PwmOut led_var(LED1);
DigitalOut led(LED2);
AnalogIn pot1(AIN);
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
 * Threads
******************************************************************/
//Read temperature and display on LCD (High priority task)
//Mutex is used to protect the access to a shared resource(LCD).
Mutex lcd_mutex;
Thread thread3;
void temp_thread(void const *args)
{
  while(1)
  {
    //Wait until the thread finishes
    lcd_mutex.lock();
    //Write 0xAA to sensor to read the last converted temp
    temp_sensor.write(temp_addr, &commands[1], 1, false);
    //Read the temperature into the read_temperature array
    temp_sensor.read(temp_addr, read_temp, 2);
    //Convert temp to Celsius. Shift MS byte right by 8 bits, OR in
    //ls byte, then divide all by 256, with float result
    float temp = (float((read_temp[0] << 8) | read_temp[1]) / 256);
    //Convert float to character string
    sprintf(lcd_result, "%d.%d", int(temp), int((temp-int(temp))*10));    
    write_cmd(0x80);  // Set cursor to start of first line
    wait_us(40);
    //Write 5 characters from string to LCD
    for(int i=0; i<4; i++)
    {
      write_data(lcd_result[i]);
    }
    print_lcd(" degrees Celsius");
    //Write 0x51 to 0x90 to start temperature conversion
    temp_sensor.write(temp_addr, &commands[0], 1, false);
    //Finish the thread
    lcd_mutex.unlock();
    thread_sleep_for(1000);
  }
}

//Blink led
Thread thread1;
void led1_thread(void const *args)
{
  //led = 0;
  while(true)
  {
    led = !led;
    thread_sleep_for(500);
  }
}

//Display a counter on the LCD
Thread thread2;
void count_thread(void const *args)
{
  char k = 0;
  while(1)
  {
    write_cmd(0xc0);
    wait_us(40);
    print_lcd("Count is ");
    //OR with 0x30 to produce the ASCII code for k
    write_data(k|0x30);
    k++;
    if (k>9)
    {
      k = 0;
    }
    thread_sleep_for(1000);
  }
}

//Set the analog input value to the PWM
Thread thread4;
void breadboardled_thread(void const *args)
{
  while(1)
  {
    led_var = pot1;
  }
}


/***************************************************************** 
 * Main
******************************************************************/
int main() 
{
  init_lcd(); //Initialise the LCD display
  clr_lcd();  //Clear the LCD

  thread1.start(callback(led1_thread, &led));
  thread2.start(callback(count_thread, &ser_port));
  thread3.start(callback(temp_thread, &temp_sensor));
  thread4.start(callback(breadboardled_thread, &pot1));

  while(true) 
  {
    //Wait for timer interrupt
    __WFI();
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
