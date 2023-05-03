int i;
int e;

void setup() {
  Serial.begin(9600);
  hi();
}

void loop() {
  //Return 1 if the number is even or 0 if the number is odd
  e = even(i);
  Serial.print(i);
  Serial.print(": ");
  if (e == 1){
    Serial.println("even");
  }else{
    Serial.println("odd");
  }
  i++;
  delay(1000);
}

//Functions
int even(int number){
  if (number % 2 ==0){
    return 1;
  }else{
    return 0;
  }
}

void hi(){
  Serial.println("Hi");
}
