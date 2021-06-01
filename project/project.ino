#include <Wire.h>                        
#include <SoftwareSerial.h> // 블루투스

#include <hd44780.h>  // lcd
#include <hd44780ioClass/hd44780_I2Cexp.h>  //lcd




hd44780_I2Cexp lcd;   // lcd 객체 생성

unsigned int trigPin = 11; // trig
unsigned int echoPin = 12; // echo

#define button 2  // 버튼 연결 핀

int red_led = 4;
int green_led = 13;

int cur = 0;
int before = 0;
int state = 0;
int cnt = 0;

long distance;
long timeDistance;



void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(button, INPUT);
  lcd.init(); // lcd 초기화
  lcd.backlight();
  
  pinMode(red_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  digitalWrite(red_led, LOW);
  digitalWrite(green_led, LOW);


  
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
//    Serial.print(cnt);
    // cnt가 짝수일때 홀수일때 나누어서 기능 실현
    if(cnt%2==0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PRESS BUTTON");
      lcd.setCursor(0,1);
      lcd.print("FOR DISTANCE");
      delay(200);
      digitalWrite(red_led, LOW);
      digitalWrite(green_led, LOW);
    }else{
      showDistance(); // 거리를 보여주는 메소드
      showLight();  // 빛을 보여주는 메소드
//      Serial.print("HH!");
      
    }
   
    
}


// 버튼으로 제어하기위해 함수로 생성
void showDistance(){
    
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
    if( distance <= 3){
      Serial.write("   충돌하였습니다\n");
//      time();  // 현재 시간 출력
      Serial1.write("   충돌하였습니다\n");
    }
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distance : ");
    lcd.setCursor(0,1);
    lcd.print(distance);
    lcd.print("cm");
    delay(500); // 0.5초마다 숫자 바뀌도록
}

void showLight(){
  /*
   * 100 밝음
   * 400 평소 형광등
   * 800 어두움
   */
  int cds = analogRead(A1);
  int bright = map(cds, 0, 1023, 255, 0); // 어두워지면 LED도 어두워지게 역매핑
//  Serial.println(cds);

  if (distance < 10){
     // 거리가 10미만일시 빨간불 표시하는데 현재 밝기에 고려하여 빛 발광
    analogWrite(red_led, bright);
    digitalWrite(green_led, LOW);
  }else{
    // 거리가 10 이상일시 초록불 표시, 현재 밝기에 고려하여 빛 발광
    digitalWrite(red_led, LOW);
    analogWrite(green_led, bright);
  }
  delay(100);
}

//void time(){
//  t = rtc.getTime();
//
//  Serial.print(t.year);
//  Serial.print("-");
//  Serial.print(t.mon);
//  Serial.print("-");
//  Serial.print(t.date);
//  Serial.print("\t");
// 
//  Serial.print(t.hour);
//  Serial.print(":");
//  Serial.print(t.min);
//  Serial.print(":");
//  Serial.println(t.sec);
//}
