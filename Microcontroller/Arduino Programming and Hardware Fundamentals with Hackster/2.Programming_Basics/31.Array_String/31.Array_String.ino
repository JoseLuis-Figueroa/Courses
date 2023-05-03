//Array s
const int len = 10;
int array[len];
int array2 [len] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//Text array contains 6 elements as the compiler adds additional ASCII 0 on the end
char text [6] = {"Hello"};

void setup() {
  Serial.begin(9600);
  // Fill the array
  for(int i=0; i<len; i++){
    array[i] = i * 5;
  }
}

void loop() {
  //Print the content of array
  for(int i=0; i<len; i++){
    Serial.print(array[i]);
    Serial.print(" ");
  }
  Serial.println();
  
  //Print the content of array 2
  for(int i=0; i<len; i++){
    Serial.print(array2[i]);
    Serial.print(" ");
  }
  Serial.println();

  //Print the content of text array
  for(int i=0; i<6; i++){
    Serial.print(text[i]);
  }
  Serial.println();
  //Second way to print text array
  Serial.println(text);
  Serial.println();
  
  delay(1000);
}
