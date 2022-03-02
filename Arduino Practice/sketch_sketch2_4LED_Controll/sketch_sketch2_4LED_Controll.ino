
int pins[] = {2,3,4,5}; //LED 연결핀
int state = 0; // 현재 켤 LED index

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for(int i =0;i<4;i++){
    pinMode(pins[i],OUTPUT); //출력 모드로 설정
    digitalWrite(pins[i],LOW); // 꺼진상태로 시작
    
  }
  
}

void loop() {
  for(int i=0;i<4;i++){
    if(i==state){ //하나의 LED 켬
      Serial.print("O ");
      digitalWrite(pins[i],HIGH);
    }else{
      Serial.print("X ");
      digitalWrite(pins[i],LOW);
    }
  }
  Serial.println();
  state = (state +1) % 4; // 켤 LED를 바꿈
  delay(1000); //1초 대기

  

}
