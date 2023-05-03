//**************************************************************//
//  Name    : Play a song                             
//  Author  : Jose Luis Figueroa                                
//  Date    : 24 March, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Play twinkle twinkle little star song                                      
//**************************************************************//
#include <Arduino.h>

//Pins
const uint8_t SPEAKER_PIN = 9;

//Variables (song parameters)
const uint8_t song_length = 14;
uint16_t song_freqs[] = {262, 262, 392, 392, 440, 440, 392, 349,
349, 329, 329, 294, 294, 262};
uint8_t song_beat[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2};
uint16_t song_tempo = 300; 

void setup() {
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  //Play each note
  for(uint8_t i=0; i<song_length; i++)
  {
    uint8_t duration = song_beat[i] * song_tempo;
    if(song_freqs[i]==0)
    {
      delay(duration);
    }else 
    {
      tone(SPEAKER_PIN, song_freqs[i], duration);
      delay(duration);
    }
  }
  delay(song_tempo/10);
  delay(1000);
}