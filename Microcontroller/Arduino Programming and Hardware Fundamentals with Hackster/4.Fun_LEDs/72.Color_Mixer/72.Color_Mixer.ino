//**************************************************************//
//  Name    : RGB LED                                  
//  Author  : Jose Luis Figueroa                                
//  Date    : 11 Feb, 2021 
//  Board   : Arduino uno
//  Version : 1.0                                               
//  Notes   : Code was implemented on Tinkercad                                                  
//**************************************************************//
//Pins
const int green_pin = 9;
const int blue_pin = 10;
const int red_pin = 11;
//Variable
int wait = 1500;

void setup() {
  //Pins configuration
  pinMode(blue_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(red_pin, OUTPUT);
}

void loop() {
  //LED shines blue
  colors(0, 0, 255);
  delay(wait);

  //LED shines green
  colors(0, 255, 0);
  delay(wait);

  //LED shines red
  colors(255, 0, 0);
  delay(wait);

  //LED shines violet
  colors(75, 0, 255);
  delay(wait);

  //LED shines oragen
  colors(255, 75, 0);
  delay(wait);

  
}

void colors(byte brightness_red, byte brightness_green, byte brightness_blue){
  analogWrite(red_pin, brightness_red);
  analogWrite(blue_pin, brightness_blue);
  analogWrite(green_pin, brightness_green);
}
