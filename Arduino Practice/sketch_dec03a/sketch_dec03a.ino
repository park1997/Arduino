#include <Wire.h>                     // i2C 통신을 위한 라이브러리
#include <LiquidCrystal_I2C.h>        // LCD 2004 I2C용 라이브러리
LiquidCrystal_I2C lcd(0x27,20,4);     // 접근주소: 0x3F or 0x27
 
void setup()
{
  lcd.init();                      // LCD 초기화
  lcd.backlight();                // 백라이트 켜기
  
  lcd.setCursor(0, 0);          // 첫번째 줄 문자열 출력
  lcd.print("Hello, world!");
 
  lcd.setCursor(0, 1);         // 두번째 줄 문자열 출력
  lcd.print("I'm Eduino");
 
  lcd.setCursor(0, 2);         // 세번째 줄 문자열 출력
  lcd.print("Nice to meet you");
  
  lcd.setCursor(0, 3);         // 네번째 줄 문자열 출력
  lcd.print("Have a good day");
}
 
void loop()
{ 
  for(int i=0; i<4; i++){   // 오른쪽으로 4칸 움직이기
    lcd.scrollDisplayRight();
    delay(500);
  }
  for(int j=0; j<4; j++){   // 왼쪽으로 4칸 움직이기
    lcd.scrollDisplayLeft();
    delay(500);
  
  }
}
