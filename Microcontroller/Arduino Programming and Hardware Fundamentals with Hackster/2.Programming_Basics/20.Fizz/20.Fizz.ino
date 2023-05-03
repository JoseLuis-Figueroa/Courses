int counter = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (counter%3 == 0){
    Serial.println("Fizz"); 
  }else {
    Serial.println(counter); 
  }
  counter++;
  delay(1000);
}
