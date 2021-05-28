#include <Wire.h>                        // i2C 통신을 위한 라이브러리

#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>


hd44780_I2Cexp lcd;   // lcd 객체 새성

unsigned int trigPin = 11; // trig
unsigned int echoPin = 12; // echo
#define button 2  // 버튼 연결 핀
int cur = 0;
int before = 0;
int state = 0;
int cnt = 0;



void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(button, INPUT);
  lcd.init(); // lcd 초기화
  lcd.backlight();
}


void loop(){
    int cur = digitalRead(button);
    // 디바운싱 해결
    if(cur != before){
      delay(5);
      cur = digitalRead(button);
    }
    
    if( cur == HIGH && before == LOW){
      state != state;
      Serial.println("바뀜");
      cnt+=1; // 버튼 클릭당 cnt가 1씩 증가
    }
    before = cur;
    Serial.print(cnt);
    // cnt가 짝수일때 홀수일때 나누어서 기능 실현
    if(cnt%2==0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PRESS BUTTON");
      lcd.setCursor(0,1);
      lcd.print("FOR DISTANCE");
      delay(200);
    }else{
      showDistance();
      Serial.print("HH!");
      
    }
   
    
}


// 버튼으로 제어하기위해 함수로 생성
void showDistance(){
    long distance;
    long timeDistance;
    digitalWrite(trigPin, LOW);// trig핀에서 초음파 내보냄 일단 low로 초기화함
    delayMicroseconds(2); //2 microsecond동안 잠깐 delay
    
    digitalWrite(trigPin, HIGH); // 초음파를 내보내기위해 HIGH 
    delayMicroseconds(10); // 10 microsecond동안 잠깐 delay
    digitalWrite(trigPin, LOW); // 이제 그만 내보내기 위해 LOW로 다시 바꿔줌

    if( digitalRead(echoPin) == LOW){
      // 초음파센서 갔다가 다시 돌아오기때문에 2로 나누어줌, 1cm 이동하는데 걸리는시간 29.41us
      distance = (float)pulseIn(echoPin, HIGH)/29/2;
    }else{
      pinMode(echoPin, OUTPUT);
      digitalWrite(echoPin, LOW);
      pinMode(echoPin, INPUT);
    }
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distance : ");
    lcd.setCursor(0,1);
    lcd.print(distance);
    lcd.print("cm");
    delay(500); // 0.5초마다 숫자 바뀌도록
}
