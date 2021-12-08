int GasPin = A1;   // 가스센서 입력을 위한 아날로그 핀
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 20, 4);
int Analog_Input = A0;
int lpg, co, smoke;


void setup() {
 
  pinMode(GasPin ,INPUT);   // 아날로그 핀 A0를 입력모드로 설정
  Serial.begin(9600);
  lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
  lcd.backlight();
  Serial.println("start");
 
}
 
 
void loop() {
 
  Serial.println(analogRead(GasPin));   // 가스센서로부터 아날로그 데이터를 받아와 시리얼 모니터로 출력함

  String gas = "Gas : " + String(analogRead(GasPin)); 


  lcd.init();                      // LCD 초기화
  lcd.backlight();                // 백라이트 켜기
  
  lcd.setCursor(0, 0);          // 첫번째 줄 문자열 출력
  lcd.print(gas);
 
  lcd.setCursor(0, 1);         // 두번째 줄 문자열 출력
  lcd.print("I'm Eduino");
 
  lcd.setCursor(0, 2);         // 세번째 줄 문자열 출력
  lcd.print("Nice to meet you");
  
  lcd.setCursor(0, 3);         // 네번째 줄 문자열 출력
  lcd.print("Have a good day");



  delay(1000);  // 1s 대기
 
} 
