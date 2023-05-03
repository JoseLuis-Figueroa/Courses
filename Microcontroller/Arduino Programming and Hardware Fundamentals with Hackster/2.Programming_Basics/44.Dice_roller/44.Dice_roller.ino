void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop() {
  String side = "";
  int sides;
  
  Serial.println("Enter the number of sides on the die");
  //Wait until you write something
  while(side.equals("")){
    side = Serial.readString();
  }

  //Convert input string into a number
  sides = side.toInt();

  if (sides > 0){
    Serial.print("You rolled: ");
    Serial.println(random(1, sides));  
  }else{
    Serial.println("Enter a positive number");
  }
  
}
