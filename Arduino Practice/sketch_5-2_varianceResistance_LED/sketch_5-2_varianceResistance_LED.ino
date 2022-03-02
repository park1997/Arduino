int vResistor = A0; //A0핀에 가변저항 연결
int[] pins_LED = {2,3,4,5};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(vResistor,INPUT);
  for(int i=0;i<4;i++){
    digitalWrite(pins_LED[i],LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc = analogRead(vResistor);  //가변저항값읽기
  int count_led = (adc>>8)+1; //LED개수 결정
//  int count_led = map(adc,0,1023,0,3);
  for(int i=0;i<4;i++){
    if(i<count_led){
      digitalWrite(pins_LED[i],HIGH);
    }else{
      digitalWrite(pins_LED[i],LOW);
    }
  // ADC값과 LED개수 출력
  Serial.println(String("ADC : ")+adc+" , LED count : "+count_led);
  delay(1000);
  }
  
}
