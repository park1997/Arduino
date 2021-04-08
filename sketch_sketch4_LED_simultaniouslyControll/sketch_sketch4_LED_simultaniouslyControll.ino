int pins[] = {2,3,4,5}; // LED연결핀
int state= 16; // 현재 켤 LED 인덱스 
boolean process_it = false; // 데이터 입력 종료
String buffer = ""; // 수신 데이터 버퍼


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // 시리얼 통신 초기화
  for(int i=0;i<4;i++){
    pinMode(pins[i],OUTPUT); //출력 모드로 설정
    digitalWrite(pins[i],LOW); // 꺼진 상태로 시작
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()){ //개행문자 '\n' 을 만날 때까지 읽음
    char data = Serial.read();
    
    if(data=='\n'){
      process_it = true; // 문자열 종료
      break;    
    }else{
      buffer+=data;
    }
  }

  if(process_it){
    Serial.println(String("You entered \'")+buffer+"\'"); //입력 문자열 표시
    state = buffer.toInt(); //정수로 변환

   if(state<0 || state>15){ //범위를 벗어난 숫자
    Serial.println(" * Invalid number ... ");
    state=16;
   }

   for(int i=0;i<4;i++){
    boolean on_off = state & (0x1 << i); // LED점멸 비트 추출
    if(on_off){
      Serial.print("O ");
      digitalWrite(pins[i],HIGH);
      
    }else{ //LED 끔
      Serial.print("X ");
      digitalWrite(pins[i],LOW);   
    }
   }
   Serial.println();
   buffer = "";
   process_it = false;
  
  }  
}
