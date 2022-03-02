int[] LED ={2,3};
int button = 13;
boolean previous_state = false;
boolean LED_state = false;
int data=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  for(int i=0; i<2; i++){
    pinMode(LED[i],OUTPUT) // pinmode를 output모드로 설정
    digitalWrite(LED[i],0)  // 모든 LED를 끈 상태로 세팅
  }
  pinMode(button,INPUT) // 버튼핀을 input모드로 설정
  
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean state = digitalRead(button);  // 버튼의 눌림 여부 판단

  if(state){
    if(!previous_state){
      Serial1.write('1'); // 버튼이 눌렸을 경우 MCU에 1 전송
      Serial.println("On"); // Serial모니터에 출력
      LED_state = !LED_state;// LED상태 반전을위한 not 처리
      digitalWrite(LED[0],LED_state); // LED 상태 반영
    }
    previous_state = true;  // 버튼이 한번 눌렸으므로 아중 if문안으로 못들어오게 previous_state값 true로 초기화
    delay(20);  // 20m쉼
  }else{
    previous_state=false; // 평소 버튼이 안눌렸을때는 flase로 처리
  }
  
  if(Serial1.available()){  //MCU에서 신호를 보냈을떄
    data = Serial1read(); // MCU에서 보낸 신호를 읽음
    digitalWrite(LED[1],data);  // 보낸 신호를 읽어서 2번 LED상태 변경
  }

  

}
