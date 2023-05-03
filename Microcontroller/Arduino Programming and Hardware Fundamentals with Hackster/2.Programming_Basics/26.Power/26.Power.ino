int result = 1;
int answer;

void setup() {
  // This code will calculate the power 
  Serial.begin(9600);
  
  answer = power(0, 2);
  Serial.println(answer);
  
  answer = power(0, 2);
  Serial.println(answer);
  
  answer = power(2, 14);
  Serial.println(answer);
}

void loop() {
  // put your main code here, to run repeatedly:

}

int power(int x, int y){
  //Special case when x = 0
  if (x == 0){
    return 1;
  }
  //Use the for to perform the equiation x raise to the power of y
  for(int i = 0; i < y; i++){
    result *= x;
    //result = result * x;
  }
  return result;
}
