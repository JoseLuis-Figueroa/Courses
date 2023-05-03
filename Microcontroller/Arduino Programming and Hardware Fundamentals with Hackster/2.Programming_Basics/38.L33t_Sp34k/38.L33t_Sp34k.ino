void setup() {
  Serial.begin(9600);
  String input = "Eating trees is great!";
  input.replace("e", "3");
  input.replace("E", "3");
  input.replace("a", "4");
  input.replace("A", "4");
  input.replace("i", "1");
  input.replace("I", "1");
  Serial.print(input);
}

void loop() {
  // put your main code here, to run repeatedly:

}
