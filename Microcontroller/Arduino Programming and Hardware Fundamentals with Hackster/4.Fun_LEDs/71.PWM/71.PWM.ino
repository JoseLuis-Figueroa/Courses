const int pin_2 = 2;
const int pin_3 = 3;
const int pin_4 = 4;

void setup() {
  // Pins configuration
  pinMode(pin_2, OUTPUT);
  pinMode(pin_3, OUTPUT);
  pinMode(pin_4, OUTPUT);
}

void loop() {
  // Variables
  int brightness_1;
  int brightness_2;
  int brightness_3;

  // Increases LED brightnesses at different times
  for (int i=0; i<395; i++){
    //Store brightness levels
    brightness_1 = i;
    brightness_2 = i - 70;
    brightness_3 = i - 140;
    
    //Limit brightness between 0 to 255
    if (brightness_1 < 0){
      brightness_1 = 0;
    }else if (brightness_2 < 0){
      brightness_2 = 0;  
    }else if (brightness_3 < 0){
      brightness_3 = 0;
    }else if (brightness_1 > 255){
      brightness_1 = 255;
    }else if (brightness_2 > 255){
      brightness_2 = 255;  
    }else if (brightness_3 > 255){
      brightness_3 = 255;
    }

    //Set LED brightness levels (Duty cycle)
    analogWrite(pin_2, brightness_1);
    analogWrite(pin_3, brightness_2);
    analogWrite(pin_4, brightness_3); 
    
    delay(10);
  }

}
