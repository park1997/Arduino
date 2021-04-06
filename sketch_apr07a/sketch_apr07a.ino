
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  int n = 123;
  Serial.println(n,BIN); // 2진
  Serial.println(n,DEC); // 10진수
  Serial.println(n,HEX); // 16진수
  수
  float f = 3.1415927;
  Serial.println();
  Serial.println(f); //디폴트 값으로 소수점 이하 두자리 
  Serial.println(f,5); // 소수점 이하 다섯자리

  
}
