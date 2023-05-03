void setup() {
  Serial.begin(9600);
  Serial.setTimeout(500);
}

void loop() {
  String name1 = "";
  String last_name = "";
  
  //Ask for the name and wait until write something
  Serial.println("Enter your first name");
  while(name1.equals("")){
    name1 = Serial.readString();
  }
  
  //Ask for the last name and wait until write something
  Serial.println("Enter your last name");
  while(last_name.equals("")){
    last_name = Serial.readString();
  }

  //Trim all whitespaces around each name
  name1.trim();
  last_name.trim();

  //Concatenate first and last name with a space in between
  name1.concat(" ");
  name1.concat(last_name);
  
  Serial.print("Hello, ");
  Serial.println(name1);
  Serial.println();
}
