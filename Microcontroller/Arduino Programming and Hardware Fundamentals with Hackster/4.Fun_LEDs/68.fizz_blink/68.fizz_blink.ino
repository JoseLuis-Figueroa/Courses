const int pin = 22;

void setup() {
  //Set the pin 22 as output
  pinMode(pin, OUTPUT);
  //Set serial communication
  Serial.begin(9600); 
}

void loop() {
  //LED blinks with odd numbers
  for(int i=0; i<30; i++){
    if (i%3==0){
      digitalWrite(pin, HIGH);
      delay(500);
      digitalWrite(pin, LOW);
      delay(500);
    }else{
      Serial.println(i);
    }
    delay(1000);
  }

}
