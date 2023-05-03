//**************************************************************//
//  Name    : UART                       
//  Author  : Jose Luis Figueroa                                
//  Date    : 23 April, 2021 
//  Board   : Arduino Mega
//  Version : 1.0                                               
//  Notes   : Send the message "Hi" between two Arduino megas
//          : using TX and Rx in one board, and pin 2 and 3 in 
//          : the another board.                                      
//**************************************************************//
#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial soft(2, 3);

void setup() {
  //UART configuration
  soft.begin(9600);
}

void loop() {
  //Send 'Hi' message
  soft.println("Hi");
  delay(1000);
}