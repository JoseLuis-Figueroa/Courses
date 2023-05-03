//**************************************************************//
//  Name    : Bulglar Alarm                    
//  Author  : Jose Luis Figueroa                                
//  Date    : 9 April, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : 
//          :                            
//**************************************************************//
#include <Arduino.h>
#include <avr8-stub.h>
#include <app_api.h>
#include <Led.h>

//Pins
const uint8_t GRN_PIN = 53;
const uint8_t YLW_PIN = 52;
const uint8_t RED_PIN = 51;
const uint8_t ECH_PIN = 22;
const uint8_t TRG_PIN = 24;
const uint8_t BZR_PIN = 7;

//Global Variables
const uint8_t TRIG_DELAY = 15;

//Instances
Led led_grn(GRN_PIN);
Led led_ylw(YLW_PIN);
Led led_red(RED_PIN);

void setup() {
  //Ultrasonic pins
  pinMode(ECH_PIN, INPUT);
  pinMode(TRG_PIN, OUTPUT);
  //Buzzer Pin
  pinMode(BZR_PIN, OUTPUT);
  //Initialize the avr-debugger
  debug_init();
}

void loop(){
  uint64_t duration;
  uint32_t distance;

  //Send out a pulse (Trigger) to start the measurement
  digitalWrite(TRG_PIN, LOW);
  delayMicroseconds(10);
  digitalWrite(TRG_PIN, HIGH);
  delayMicroseconds(TRIG_DELAY);
  digitalWrite(TRG_PIN, LOW);
  //Measure time of pulse on ECHO pin
  duration = pulseIn(ECH_PIN, HIGH);
  //Convert time to distance
  distance = duration / 58.8;
  
  if(distance > 40.0)
  {
    //Led On
    led_grn.on();
     //Off
    led_ylw.off();
    led_red.off();
    noTone(BZR_PIN);
  }
  else if(distance > 30 && distance <= 40)
  {
    //Off
    led_red.off();
    led_grn.off();
    noTone(BZR_PIN);
    //Led flash
    led_ylw.flash(100);
  }
  else if(distance > 20 && distance <= 30)
  {
    //Off
    led_grn.off();
    led_red.off();
    noTone(BZR_PIN);
    //Led on
    led_ylw.on();
  }
  else if(distance > 10 && distance <= 20)
  {
    //Off
    led_ylw.off();
    led_grn.off();
    noTone(BZR_PIN);
    //Led on
    led_red.on();
  }
  else if(distance <=10)
  {
    //Off
    led_ylw.off();
    led_grn.off();
    //On
    tone(BZR_PIN, 450);
    led_red.on();
  }
}