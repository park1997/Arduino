#include <Wire.h>                        
#include <SoftwareSerial.h> // 블루투스

#include <hd44780.h>  // lcd
#include <hd44780ioClass/hd44780_I2Cexp.h>  //lcd




hd44780_I2Cexp lcd;   // lcd 객체 생성

unsigned int trigPin = 11; // trig
unsigned int echoPin = 12; // echo

#define button 2  // 버튼 연결 핀

int red_led = 10;
int yellow_led = 4;
int green_led = 13;

int cur = 0;
int before = 0;
int state = 0;
int cnt = 0;

long distance;
long timeDistance;

String input = "";
String get_string(String input);


int d_red = 10;
int d_yellow = 50;

boolean key1 = true;
boolean key2 = true;

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


  
}


void loop(){
    input = get_string(input);
    if(input == "reset"){
      d_yellow = 50;
      d_red = 10;
    }else if( input.substring(0,1) == "y"){
      // 명령어가 y로 시작하면서 바뀌는 수치값이 d_red보다 클 경우!(노란불점등 거리가 빨간불 점등 거리보다 짦을 순 없기떄문)
      if(input.substring(1).toInt() > d_red){
        d_yellow = input.substring(1).toInt();
        key1 = true;
      }else if(key1 && key2){
        Serial1.print(d_red);
        Serial1.write("보다 크게 입력하셔야 합니다.\n");
        key1 = false;
      }
      
      
    }else if(input.substring(0,1) =="r" ){
      // 명령어가 r로 시작하면서 바뀌는 수치값이 d_yellow보다 작을 경우만!( 빨간불 점등거리가 노란불 점등거리보다 클 수 없다.)
      if(input.substring(1).toInt() < d_yellow){
        d_red = input.substring(1).toInt();
        key2 = true;
      }else if (key1 && key2){
        Serial1.print(d_yellow);
        Serial1.write("보다 작게 입력하셔야 합니다.\n");
        key2 = false;
      }
      
      
    }
  
  
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

  if (distance < d_red){
     // 거리가 d_red 미만일시 빨간불 표시하는데 현재 밝기에 고려하여 빛 발광
    analogWrite(red_led, bright);
    digitalWrite(green_led, LOW);
    digitalWrite(yellow_led,LOW);
  }else if(distance < d_yellow){
    // // 거리가 d_red 초과 d_yellow 이상일시 노란불 표시, 현재 밝기에 고려하여 빛 발광
    analogWrite(yellow_led, bright);
    digitalWrite(green_led, LOW);
    digitalWrite(red_led, LOW);    
  }else{
    // 거리가 d_yellow 이상일시 초록불 표시, 현재 밝기에 고려하여 빛 발광
    digitalWrite(red_led, LOW);
    analogWrite(green_led, bright);
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
