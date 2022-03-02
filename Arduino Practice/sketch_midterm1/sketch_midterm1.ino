Servo myServo
void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = analogRead(55); // 온도 센서 읽기
  float voltage = temp *5.0/1024.0;
  float tempc = voltage*100 // 온도 
  int bright = analogRead(56); // 조도센서 읽기
  int mapped = map(bright, 0, 1023, 50,10) // 반대로 매핑

  if(temp>30 && bright>30){
    for(int angle =0; angle<180){
      myServo.write(angle);
      delay(5)
    }
  }
}
