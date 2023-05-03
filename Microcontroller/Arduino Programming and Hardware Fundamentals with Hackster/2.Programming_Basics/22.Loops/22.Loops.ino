int i = 0;
int a = 0;
int z = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //While loop
  while(i < 3){
  Serial.println("While loop");
  i++; 
  }
  //For loop
  for (int x = 0; x < 3; x++){
    Serial.println("For loop");
  }
  //Do while loop
  do {
    Serial.println("Do While loop");
    z++;
  }while(z < 3);
  //Break function
  i = 0;
  while(i < 3){
  Serial.println("Break function");
  a++;
  if (a == 2){
    break;
  }
  i++; 
  }
   
}

void loop() {
  // put your main code here, to run repeatedly:

}
