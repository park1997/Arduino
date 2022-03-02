int buttons[] = {14,15,16,17};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<4;i++){ //버튼 연결핀을 입정력으로 설
    pinMode(buttons[i],INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<4;i++){
    Serial.print(digitalRead(buttons[i])); //버튼 상태 출력
    Serial.print(" ");
  }
  Serial.println(); 
  delay(1000);
}
