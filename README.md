# Arduino
 
# 🛫 결과

## 하드웨어 구성

![스크린샷 2022-03-01 오후 8 41 54 (1)](https://user-images.githubusercontent.com/73048180/156300527-0daed5a8-8589-4093-a6de-e65efb1a5b2a.png)

블루투스 통신을 통한 충돌 알림 및 명령어기반 장애물 탐지 거리 제어 

![Untitled (2)](https://user-images.githubusercontent.com/73048180/156300563-d0934c3f-1220-40e9-b780-b6111539a27c.png)

회로 구성

- 택트 스위치를 통해 시스템을 ON(**거리감지모드 활성화**), OFF(**거리감지모드 비 활성화**)
- ON일 경우 **자동차**와 **장애물**과의 거리를 LCD에 표시.
- 장애물과의 거리에 따라 LED가 점등되는 색 바뀜.
    - 장애물과 **매우 가깝다** : **빨간색** LED 점등
    - 장애물과 **가깝다** : **노란색** LED 점듬
    - 장애물과의 **거리가 멀다** : **초록색** LED 점등
- LED는 운전자의 시야를 가릴 수 있기 때문에 조도센서를 이용하여 차 내부 빛 밝기에 따라 LED의 밝기가 조절된다.
- **블루투스 통신**으로, 점등되는 LED 거리의 물리적인 기준값을 바꾸어 사용자가 커스터마이징 할 수 있다.
- 차와 장애물과의 충돌이 일어난 **시점(날짜, 시간)**을 저장하고 **블루투스 통신**을 통하여 핸드폰으로 **알림을 전송**한다.

# 🔍 센서 및 모듈

- 초음파 센서
- 조도 센서
- LCD 패널
- 블루투스 모듈(HC-06)
- LED

# ✍️  서론

- 프로젝트 배경
    - 좁은 길을 운전할 때 불안한 마음을 가지게 된다.
    - 운전이 미숙하다면 본인 차의 크기와 부피를 가늠하기 어렵다.
    - 문콕이나 긁힘과 같은 사고가 나 몰래 일어나는 경우가 많다.
- 문제정의
    - 기존 차량들은 소리를 통해 장애물과 거리를 알려주지만 물리적인 거리를 제공해주진 않는다.
    - 교통사고가 아닌이상 차의 손상은 언제어디서 일어났는지 알기가 어려워 충돌시간을 기록할 필요가 있다.
- 프로젝트 목표
    - 아두이노를 활용한 자동차 긁힘 방지를 위해 물체 간 거리 탐지 및 경고 알림 휴대폰 전송 시스템 개발

# 🔍 시스템 구성

![Untitled (1)](https://user-images.githubusercontent.com/73048180/156300604-8397cd45-3fba-4278-9087-f2696fe8bcae.png)

# 👨🏻‍💻담당 업무

- 아두이노 회로 구성
    - 플로팅 현상을 해결하기위한 풀다운 저항 채택
    - 직관적인 상황(Press : HIGH)을 위해 풀다운 저항 사용
- 아두이노 프로그래밍 개발
    - 조도센서의 sensing 값을 역매핑, PWM 을 통한 밝기제어
    - 코드의 함수화를 통한 원활한 디버깅 환경 조성
    - 스위치의 바운싱 현상을 해결하기위한 로직 구현
    - LCD 객체 생성 및 결과 시각화
    - 블루투스 기반 비 동기식 통신 구현
        - 블루투스 통신을 통한 명령어기반 시스템 제어
        - 블루투스 통신 기반 충돌 감지 모니터링

# 💡 느낀 점

- 회로상에서의 한계(바운싱 현상)를 프로그래밍 코드로 해결 할 수 있는 법을 배우게 됨
- IoT를 활용하게 하드웨어를 유연하게 컨트롤할 수 있게 되어 유지 및 보수가 간편해짐을 알게 됨.
- 센싱된 data를 수집, 전처리 분석을 통해 서비스화를 할 수 있는 역량 강화

## 🛠 한계점 및 미래연구

### 초음파 센서의 정확성

- 초음파센서를 이용하여 읽은 값이 0일 경우 “충돌 했다" 라고 판단하고 이 프로젝트를 진행 하였으나, 초음파센서는 거리가 0인 상태를 잘 잡아내지 못하였다.
    
    ⇒ 본인은 거리가 5cm 미만일시 “충돌했다"라고 가정하고 이 프로젝트를 진행하게 되었다.
    

### 조도 센서 불량

- 조도 센서를 통해 얻은 값을 역 매핑하여 LED의 밝기를 제어 했으나, 조도 센서의 불량으로 현재 조도값을 잘 읽어내지 못하는 경우가 많았다.
    
    ⇒ 극단적인 조도 센싱결과는 LED 밝기 차이를 보여주었기 때문에 품질 좋은 조도센서를 이용해야만 한다.
    

## Code

```arduino
#include <Wire.h>                        
#include <SoftwareSerial.h> // 블루투스
 
#include <hd44780.h>  // lcd
#include <hd44780ioClass/hd44780_I2Cexp.h>  //lcd
 
#include <core_build_options.h>
#include <swRTC.h> // 시간모듈
 
swRTC rtc;  //클래스 개체 선언
 
hd44780_I2Cexp lcd;   // lcd 객체 생성
 
unsigned int trigPin = 11; // trig
unsigned int echoPin = 12; // echo
 
#define button 2  // 버튼 연결 핀
 
int red_led = 10; // 빨간색 led 핀 번호
int yellow_led = 4; // 노란색 led 핀번호
int green_led = 13; // 초록색 led 핀번호
 
// 디바운싱을 위한 변수
int cur = 0;  // current
int before = 0;
int state = 0;
int cnt = 0; // count
 
long distance;  // lcd에 표시될 길이
long timeDistance;
 
String input = "";  //input 초기화
String get_string(String input);
 
 
int d_red = 10; // 빨간불이 켜질 조건(거리가 10 미만일떄)
int d_yellow = 50; // 노란불이 켜질 조건( 거리가 50 미만일때)
 
boolean key1 = true;
boolean key2 = true;
boolean key3 = true;
 
void setup(){
 Serial.begin(9600);
 Serial1.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(button, INPUT);
 lcd.init(); // lcd 초기화
 lcd.backlight();
 
 pinMode(yellow_led, OUTPUT);
 pinMode(red_led,OUTPUT);
 pinMode(green_led,OUTPUT);
 digitalWrite(red_led, LOW);
 digitalWrite(green_led, LOW);
 
 rtc.stopRTC();            //정지
 rtc.setTime(02, 15, 30);  //시, 분, 초
 rtc.setDate(12, 6, 2021); //일, 월, 년
 rtc.startRTC();           //시작
}
void loop(){
   input = get_string(input);
   if(input == "reset"){
     d_yellow = 50;  // 노란불이 꺼지는 거리값 50cm로 재 초기화
     d_red = 10; // 빨간불이 꺼지는 거리값 10cm로 재 초기화
   }else if( input.substring(0,1) == "y"){ // 명령어의 첫번쨰 글자가 y일 경우
     // 명령어가 y로 시작하면서 바뀌는 수치값이 d_red보다 클 경우!(노란불점등 거리가 빨간불 점등 거리보다 짦을 순 없기떄문)
     if(input.substring(1).toInt() > d_red){
       d_yellow = input.substring(1).toInt();  // 명령어의 숫자만큼의 거리값으로 변환함
       key1 = true;
     }else if(key1 && key2){ // yellow의 거리값이 red보다 작아질경우(말이 안되는 상황)
       Serial1.print(d_red);
       Serial1.write("보다 크게 입력하셔야 합니다.\n");
       key1 = false;
     }
     
     
   }else if(input.substring(0,1) =="r" ){  // 명령어의 첫번쨰 글자가 r일 경우
     // 명령어가 r로 시작하면서 바뀌는 수치값이 d_yellow보다 작을 경우만!( 빨간불 점등거리가 노란불 점등거리보다 클 수 없다.)
     if(input.substring(1).toInt() < d_yellow){
       d_red = input.substring(1).toInt(); // 명령어의 숫자값으로 빨간불이 점등될 거리값 초기화
       key2 = true;
     }else if (key1 && key2){  // red의 거리값이 yellow의 거리값보다 커질경우 ( 말이 안되는 경우)
       Serial1.print(d_yellow);
       Serial1.write("보다 작게 입력하셔야 합니다.\n");
       key2 = false;
     }
   }
 
   int cur = digitalRead(button);  // 버튼의 상태 검사
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
     time(); // 현재의 시간 출력
     Serial.write("   충돌하였습니다\n"); // 충돌메세지 전달
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
 int cds = analogRead(A1); // 현재의 조도값을 읽어옴
 int bright = map(cds, 0, 1023, 255, 0); // 어두워지면 LED도 어두워지게 역매핑
//  Serial.println(cds);
 
 if (distance < d_red){
    // 거리가 d_red 미만일시 빨간불 표시하는데 현재 밝기에 고려하여 빛 발광
   analogWrite(red_led, bright); // 현재 조도값에 반비례하여 밝기 조정
   digitalWrite(green_led, LOW);
   digitalWrite(yellow_led,LOW);
 }else if(distance < d_yellow){
   // // 거리가 d_red 초과 d_yellow 이상일시 노란불 표시, 현재 밝기에 고려하여 빛 발광
   analogWrite(yellow_led, bright);// 현재 조도값에 반비례하여 밝기 조정
   digitalWrite(green_led, LOW);
   digitalWrite(red_led, LOW);    
 }else{
   // 거리가 d_yellow 이상일시 초록불 표시, 현재 밝기에 고려하여 빛 발광
   digitalWrite(red_led, LOW);
   analogWrite(green_led, bright);// 현재 조도값에 반비례하여 밝기 조정
   digitalWrite(yellow_led, LOW);
 }
 delay(100);
}
 
String get_string(String input){
 String inputString = "";             // 아무것도 입력하지 않았을 때 빈 문자열
 while(Serial1.available()) {      // 블루투스 통신에 데이터가 입력되면(스마트폰 -> 아두이노)
   delay(3);                         // 데이터 수신이 잘 이루어지기 위해 3ms 기다림
   if (Serial1.available() >0) {   // 수신된 데이터가 있으면
     char c = Serial1.read();      // 수신된 데이터 1개를 받아 c로 저장(이후에는 그다음걸 받아 c로 저장
     inputString += c;                // 수신된 데이터를 c와 붙임.
   }
 }
 if(inputString.length() == 0) return input;    // 문자열 길이가 0이면(데이터를 입력받지 않았다면) 기존의 값을 반환  
 else return inputString;             // 데이터를 입력받았다면 해당 문자열을 출력
}
 
// 현재 시간 출력함수
void time(){
 Serial1.print(rtc.getYear(), DEC);  // 연도
 Serial1.print("/");
 Serial1.print(rtc.getMonth(), DEC); // 월
 Serial1.print("/");
 Serial1.print(rtc.getDay(), DEC); // 일
 Serial1.print("\t");
 
 Serial1.print(rtc.getHours(), DEC); // 시
 Serial1.print(":");
 Serial1.print(rtc.getMinutes(), DEC); // 분
 Serial1.print(":");
 Serial1.print(rtc.getSeconds(), DEC); // 초
}
```
