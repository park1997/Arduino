int vResistor = A0; //A0핀에 가변저항 연결
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  piMode(vResistor,INPUT);
}기

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(vResistor));  //가변저항값을 읽어 출력
  delay(1000);  // 1초 대
}
