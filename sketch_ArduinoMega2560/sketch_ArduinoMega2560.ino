int[] LED ={2,3};
int button = 13;
boolean previous_state = false;
int data=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  for(int i=0; i<2; i++){
    pinMode(LED[i],OUTPUT)
    digitalWrite(LED[i],0)
  }
  pinMode(button,INPUT)
  
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean state = digitalRead(button);  // 버튼의 눌림 여부 판단
  
  if(state){
    Serial1.write('1'); // 버튼이 눌렸을 경우 MCU에 1 전송
    Serial.println("On"); // Serial모니터에 출력
    previous_state != previous_state; // 이전상태 반전
    digitalWrite(LED[0],previous_state);  // 1번 LED 상태(on,off) 반전
    delay(20);
  }else{
    previous_state = false; // 버튼이 안눌렸을때는 false로 초기화 이는 버튼이 한번 눌렸을때 한번만 인식되게함
  }

  if(Serial1.available()){  //MCU에서 신호를 보냈을떄
    data = Serial1read(); // MCU에서 보낸 신호를 읽음
    digitalWrite(LED[1],data);  // 보낸 신호를 읽어서 2번 LED상태 변경
  }

  
}
