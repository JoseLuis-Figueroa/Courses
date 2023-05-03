//Random function
void setup() {
  //randomSeed changes the random number according to the analogRead.
  //analogRead returns an integer between 0 to 1023. 
  randomSeed(analogRead(A0));
  Serial.begin(9600);

  for(int i = 0; i < 5; i++){
    Serial.print(random(1, 101));
    Serial.print(" ");
  }
  Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly:

}
