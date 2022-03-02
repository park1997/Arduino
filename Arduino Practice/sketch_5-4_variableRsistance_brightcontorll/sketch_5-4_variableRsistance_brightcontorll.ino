int pins_LED[] = {2,3,4,5};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<4;i++){
    pinMode(pins_LED[i],OUTPUT);
  }
  pinMode(A0,INPUT);  //가변저항 연결 핀 입력으로 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  int ADC_value = analogRead(A0); // ADC값
  int PWM_value = map(ADC_value,0,1023,0,255);  // PWM값

  Serial.print(String("ADC value : ")+ADC_value);
  Serial.println(String(" , PWM value : ")+PWM_value);
  for(int i=0;i<4;i++){ //LED밝기 조절
    analogWrite(pins_LED[i],PWM_value);
  }
  delay(1000);
}
