int a = 8;
int b = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if ((a != 5) && (b > 3)){
    Serial.println("Statement 1");
  }
  if ((a != 5) || (b > 3)){
    Serial.println("Statement 2");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
