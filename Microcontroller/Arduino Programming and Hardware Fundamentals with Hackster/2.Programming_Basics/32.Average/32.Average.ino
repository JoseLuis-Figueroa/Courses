//calculate the average of the numbers contained on the array
const int len = 5;
int a[len] = {0, 2, -4, 12, -52};

void setup() {
  Serial.begin(9600);
  float average;
  float summation;
  for(int i=0; i<len; i++){
    summation += a[i]; 
  }
    
  average = summation/len;
  Serial.println(average, 4);  
}

void loop() {
  // put your main code here, to run repeatedly:

}
