//String function
void setup() {
  Serial.begin(9600);
  String string = "Hello World";

  Serial.println(string);
  //Print the position of the number
  Serial.println(string.charAt(7));
  //Concatenate the string
  string.concat("lings");
  Serial.println(string);
  //Convert the string to upper case
  string.toUpperCase();
  Serial.println(string);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
