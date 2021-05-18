int adc = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(115200);
  pinMode(adc,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial2.available()){  // 전달된 값을 읽음
    char data = Serial2.read(); //  읽은 값을 data에 저장
    if(data == '1'){  // 버튼이 눌렸을때
      int reading = analogRead(adc); // 아날로그값을 읽어옴
      reading = map(0,4095,0,1023); // MCU값이 4023까지 나와, 0~1023까지의 값으로 mapping
      Serial.println(reading);  // Serial모니터에 출력
      if(reading>=300){ // 조도 센서값이 300이상일때
        Serial2.write(1); // Serial1에 1 전송
      }else{
        Serial2.write(0); // Serial1에 0 전송
      } 
    } 
  }  
}
