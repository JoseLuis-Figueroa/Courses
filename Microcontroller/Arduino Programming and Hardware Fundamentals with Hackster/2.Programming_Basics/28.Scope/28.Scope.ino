//Scope, it is to use local function on the loop or functions
void setup() {
  Serial.begin(9600);

}

void loop() {
  int a = 6;
  int b = 5;

  Serial.println(add(a,b));
  
  delay(500);
}

int add(int x, int y){
  Serial.print(x);
  Serial.print("+");
  Serial.println(y);
  return x + y;
}
