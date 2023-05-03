#include <Adafruit_NeoPixel.h>

const int data_pin = 6;
const int num_pixels = 5;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(num_pixels, data_pin, NEO_RGB + NEO_KHZ800);

void setup() {
  //Initialize NeoPixels
  pixels.begin();

  //Set LED colors
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.setPixelColor(1, pixels.Color(255, 127, 0));
  pixels.setPixelColor(2, pixels.Color(0, 255, 0));
  pixels.setPixelColor(3, pixels.Color(255, 0, 0));
  pixels.setPixelColor(4, pixels.Color(127, 0, 255));

  //Write data out to NeoPixels
  pixels.show();
  delay(1000);
}

void loop() {
  uint16_t i, j;
  for(j=0; j<256; j++){
    for(i=0; i<pixels.numPixels(); i++){
      pixels.setPixelColor(i, Wheel((i*256/pixels.numPixels())));
    }
    pixels.show();
    delay(20);
  }
}

uint32_t Wheel(byte WheelPos){
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85){
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos *3);
  }
  if(WheelPos < 170){
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos *3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos *3, 0);
}
