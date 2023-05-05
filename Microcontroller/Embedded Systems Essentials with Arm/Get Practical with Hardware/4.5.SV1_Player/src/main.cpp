/***************************************************************** 
 * Name    : Audio Player 
 * Author  : Jose Luis Figueroa  
 * Date    : 27 oct, 2021 
 * Board   : Nucleo-F401RE
 * Version : 1.0  
 * Notes   : Select with the buttons one of 8 tunes which will be
 *         : displayed on LCD
******************************************************************/
#include <mbed.h>
#include "tunes.h"
#include "4bit_LCD.h"

/***************************************************************** 
 * Declarations
******************************************************************/
//Object instances
PwmOut speaker(D9);         //For piezo sounder
BusIn choose(D3, D4, D5);   //For select buttons
DigitalOut playing_led(D6); //Led indicator
DigitalOut ready_led(D7);   //Led indicator
AnalogIn volume(A0);        //For potentiometer
InterruptIn play(D2);       //For play button

//These flags indicate state of player
bool welcome = 1;   //Indicate welcome state
bool waiting = 0;   //Waiting for tune selection
bool primed = 0;    //Tune is selected but hasn't started yet
bool playing = 0;   //Tune is playing

//Functions
void lcd_cont(void);
void tune_select(void);
void play_tune(void);


/***************************************************************** 
 * Thread functions and interrupt
******************************************************************/
Mutex lcd_mutex;

//Displays welcome message on LCD
Thread thread1;   
void lcd_cont(void const *args)
{
  init_lcd();     //Initialise the LCD
  //Waiting for son
  while(1)
  {
    if(welcome)
    {
      lcd_mutex.lock();
      clr_lcd();    //Clear the LCD
      print_lcd("Choose song");
      write_cmd(0xc0);
      print_lcd("Then press play");
      lcd_mutex.unlock();
      thread_sleep_for(500);
      welcome = 0;
      ready_led = 1;
    }
  }
}

//Reads the select buttons and readies the song
Thread thread2;   
void tune_select(void const *args)
{
  while(1)
  {
    //Primed is set by interrupt
    if (primed)
    {
      //Read song selection and load song pointer
      switch(choose)
      {
        case 0x00: song_ptr=&Oranges; break;
        case 0x01: song_ptr=&Cielito; break;
        case 0x02: song_ptr=&Malaika; break;
        case 0x03: song_ptr=&Guten_Abend; break;
        case 0x04: song_ptr=&Yankee; break;
        case 0x05: song_ptr=&Rasa; break;
        case 0x06: song_ptr=&Matilda; break;
        case 0x07: song_ptr=&Alouetta; break;
      }
      lcd_mutex.lock();
      clr_lcd();
      print_lcd("Now playing");
      write_cmd(0xc0);
      print_lcd(song_ptr->name);  //display song name
      lcd_mutex.unlock();
      primed=ready_led=0;
      playing=playing_led=1;
    }
  }
}

//Play the chosen tune
Thread thread3;
void play_tune(void const *args)
{
  while(1)
  {
    if(playing)
    {
      //Resume PWM operation, stopped after last song 
      speaker.resume();
      for(int i=0; i<=(song_ptr->length); i++)
      {
        //Set PWM period
        speaker.period(1/(2*(*song_ptr).freq[i]));
        //Set duty cycle, hence volume control
        speaker=volume;
        //Hold for beat prd
        thread_sleep_for(200*(*song_ptr).beat[i]);
      }
      //indicate end of song
      playing_led=playing=false;
      welcome=1;
      speaker.suspend();
    }
  }
}

//Responds to press of play button, and sets primed
void ISR()
{
  //Only set primed if song not playing
  if(playing == 0)
  {
    primed = 1;
  }
}


/***************************************************************** 
 * Main
******************************************************************/
int main() 
{
  ready_led = 1;
  //Int. when play is pressed, ie on falling edge
  play.fall(&ISR);
  //Launch the threads
  thread1.start(callback(lcd_cont, &playing_led));
  thread2.start(callback(tune_select, &choose));
  thread3.start(callback(play_tune, &play));

  while(1) 
  {
    //Wait for interrupt
    __WFI();
  }
}