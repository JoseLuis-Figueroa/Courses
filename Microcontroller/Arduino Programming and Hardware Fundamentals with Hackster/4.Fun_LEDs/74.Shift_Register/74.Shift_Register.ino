//**************************************************************//
//  Name    : shiftOutCode                                      
//  Author  : Jose Luis Figueroa                                
//  Date    : 10 Feb, 2021 
//  Board   : Arduino uno
//  Version : 1.0                                               
//  Notes   : Code for using a 74HC595 Shift Register           
//          : Code was implemented on Tinkercad                  
//**************************************************************//
const int data_pin = 2;
const int clock_pin = 3;
const int latch_pin = 4;

void setup() {
  // Pins configuration
  pinMode(data_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(latch_pin, OUTPUT);
  
}

void loop() {
  byte x = B10000000;
  
  shiftDisplay(B11010001);
  delay(3000);

  //LEDs on one at a time
  for(int i=0; i<8; i++){
    shiftDisplay(x);
    x = x >> 1;
    delay(300);
  }

   shiftDisplay(B00000000);
   delay(1000);
  
}

//Function
void shiftDisplay(byte data){
  //Indicate that it is about to send its data
  digitalWrite(latch_pin, LOW);
  //Shifts out a byte of data one bit at a time. 
  //shiftOut(dataPin, clockPin, bitOrder, value)(Syntax)
  shiftOut(data_pin, clock_pin, LSBFIRST, data);
  //Indicate that it is sending its data
  digitalWrite(latch_pin, HIGH);
}
