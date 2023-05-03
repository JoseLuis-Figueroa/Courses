//Serial Input
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(200);
}

void loop() {
  String string = "";
  long int integer;

  //Wait until you write something
  while(string.equals("")){
    string = Serial.readString();
  }

  //Convert the string to integer
  integer = string.toInt();
  Serial.println(integer*2);
}
