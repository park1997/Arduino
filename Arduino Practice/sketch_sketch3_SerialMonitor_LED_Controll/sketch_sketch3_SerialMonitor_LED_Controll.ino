int pins[] = {2,3,4,5}; // LED 연결 핀
int state = -1; // 현재 켤 LED 인덱스
                // 처음부터 뭐 켜져있으면 안되니까 초기값을 -1로 설정

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // 시리얼 통신 초기화
  for(int i =0;i<4;i++){
    pinMode(pins[i],OUTPUT); //출력모드로 설정
    digitalWrite(pins[i],LOW); // 꺼진상태로 시작
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){ //입력 확인
    char data = Serial.read(); //데이터 읽기
    Serial.println(String("You entered \'")+data+"\'"); //입력 문자 표시

    if(data>='1' && data<='4'){ //유효한 입력인 경우
      state = data - '0'-1; // LED index로 변환
      Serial.print("LED ");
      Serial.print(state+1);
      Serial.println(" is ON ... ");
          
    }else{ // 잘못된 입력인경우
      Serial.println(" * Invalid LED number ...");
      state=-1;
      
    }
    // 현재 state에 맞는 LED만 켜주고 나머지는 꺼
    for(int i=0; i<4;i++){
      if(i==state){ //하나의 LED만 켬
        Serial.print("O ");
        digitalWrite(pins[i],HIGH);
      }else{ // 나머지는 끔
        Serial.print("X ");
        digitalWrite(pins[i],LOW);
      }
    }
    Serial.println();
//    delay(1000);
// 시리얼 모니터에서 line ending 없음으로 설정해주어야 한다!

  }
}
