void setup() {
  Serial.begin(9600);

  Serial.println(sum_digits(30));
  Serial.println(sum_digits(123));
  Serial.println(sum_digits(32767));
}

void loop() {
  // put your main code here, to run repeatedly:

}

int sum_digits(int x){
  //Local variable
  int sum = 0;

  // Find how many times 10000 goes into our number and add that
  // to our sum. Multiply the number of times 10000 goes into our
  // number by 10000 and subtract that from our number.
  sum += x/10000;
  x -= (x/10000)*10000;

  //Repeat the same thing for 1000
  sum += x/1000;
  x -= (x/1000)*1000;

  //Repeat the same thing for 100
  sum += x/100;
  x -= (x/100)*100;

  //Repeat the same thing for 10
  sum += x/10;
  x -= (x/10)*10;

  //Variable should be the value of the ones digits
  sum += x;

  return sum;
}
