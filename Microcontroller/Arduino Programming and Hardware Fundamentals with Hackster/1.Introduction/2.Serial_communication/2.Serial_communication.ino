void setup() {
  // put your setup code here, to run once.
  //Serial communication can be used to monitor variable and stuff like that to debug the code
  Serial.begin(9600);
  Serial.println("Starting");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("A ");
  delay(1000);
  Serial.println("B");
  delay(1000);
}
