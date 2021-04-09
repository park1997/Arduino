int pins_LED[] = {2,3}; //LED연결핀

// 버튼 연결핀 (15 : 풀다운 저항 , 16 : 풀업저항)
int pins_button[] = {15,16};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<2;i++){
    pinMode(pins_button[i],INPUT); // 버튼 연결 핀을 입력으로설정 
    pinMode(pins_LED[i],OUTPUT); // LED연결핀을 출력으로 설정
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<2;i++){
    boolean state = digitalRead(pins_button[i]); //버튼상태 읽기
    digitalWrite(pins_LED[i],state); //LED출력
    Serial.print(state);
    Serial.print(" ");
  }
  Serial.println();
  delay(1000);
}
