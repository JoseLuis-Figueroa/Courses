//**************************************************************//
//  Name    : JukeBox                             
//  Author  : Jose Luis Figueroa                                
//  Date    : 24 March, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Simulate a jukebox with two songs using a buzzer.  
//          : Button (Pin 52) selects song and button (pin 53)  
//          : plays it. LCD shows the name of the song.                                      
//**************************************************************//
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Button.h>

//Pins
const uint8_t SKR_PIN = 9;
const uint8_t BTN_SONG_PIN = 52;
const uint8_t BTN_PLAY_PIN = 53;
const uint8_t RS_PIN = 22;
const uint8_t E_PIN = 24;
const uint8_t D0_PIN = 2;
const uint8_t D1_PIN = 3;
const uint8_t D2_PIN = 4;
const uint8_t D3_PIN = 5;

//Variable 
bool clean_flag_song1 = false;
bool clean_flag_song2 = false;
//twinkle twinkle little star song 
const uint8_t song_length_1 = 14;
uint16_t song_freqs_1[] = {262, 262, 392, 392, 440, 440, 392, 349,
349, 329, 329, 294, 294, 262};
uint8_t song_beat_1[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2};
uint16_t song_tempo_1 = 300; 
//Happy birthday
const uint8_t song_length_2 = 14;
uint16_t song_freqs_2[] = {131, 147, 165, 175, 196, 220, 247, 262, 
294, 330, 349, 392, 440, 494};
uint8_t song_beat_2[] = {2, 1, 4, 4, 4, 4, 4, 2, 1, 4, 4, 4, 4, 4};
uint16_t song_tempo_2 = 150;

//Instance object (RS, E, D0, D1, D2, D3)
LiquidCrystal lcd(RS_PIN, E_PIN, D0_PIN, D1_PIN, D2_PIN, D3_PIN);
Button button_song(BTN_SONG_PIN);
Button button_play(BTN_PLAY_PIN);

void setup() {
  pinMode(SKR_PIN, OUTPUT);
  //LCD configuration
  lcd.begin(16, 2);
  lcd.print("Jukebox");
  delay(3000);
}

void loop() {
  
  //Select the message song
  lcd.setCursor(0, 1);
  if(button_song.toggle() == HIGH && clean_flag_song1 == false)
  {
    lcd.clear();
    lcd.print("Twinkle star");
    clean_flag_song1 = true;
    clean_flag_song2 = false;
  }else if(button_song.toggle() == LOW && clean_flag_song2 == false)
  {
    lcd.clear();
    lcd.print("Happy Birthday");
    clean_flag_song1 = false;
    clean_flag_song2 = true;
  }

  if(button_song.toggle()==HIGH && button_play.push()==HIGH)
  {
    for(uint8_t i=0; i<song_length_1; i++)
    {
      uint8_t duration1 = song_beat_1[i] + song_tempo_1;
      if(song_freqs_1[i] == 0)
      {
        delay(duration1);
      }else
      {
        tone(SKR_PIN, song_freqs_1[i], duration1);
        delay(duration1);
      }
    }
    delay(song_tempo_1/10);
    delay(2000);
  }else if(button_song.toggle()==LOW && button_play.push()==HIGH)
  {
    for(uint8_t i=0; i<song_length_2; i++)
    {
      uint8_t duration2 = song_beat_2[i] + song_tempo_2;
      if(song_freqs_2[i] == 0)
      {
        delay(duration2);
      }else
      {
        tone(SKR_PIN, song_freqs_2[i], duration2);
        delay(duration2);
      }
    }
    delay(song_tempo_2/10);
    delay(2000);
  }

}