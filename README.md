# Arduino
 
# ๐ซ ๊ฒฐ๊ณผ

## ํ๋์จ์ด ๊ตฌ์ฑ

![แแณแแณแแตแซแแฃแบ 2022-03-01 แแฉแแฎ 8 41 54 (1)](https://user-images.githubusercontent.com/73048180/156300527-0daed5a8-8589-4093-a6de-e65efb1a5b2a.png)

๋ธ๋ฃจํฌ์ค ํต์ ์ ํตํ ์ถฉ๋ ์๋ฆผ ๋ฐ ๋ช๋ น์ด๊ธฐ๋ฐ ์ฅ์ ๋ฌผ ํ์ง ๊ฑฐ๋ฆฌ ์ ์ด 

![Untitled (2)](https://user-images.githubusercontent.com/73048180/156300563-d0934c3f-1220-40e9-b780-b6111539a27c.png)

ํ๋ก ๊ตฌ์ฑ

- ํํธ ์ค์์น๋ฅผ ํตํด ์์คํ์ ON(**๊ฑฐ๋ฆฌ๊ฐ์ง๋ชจ๋ ํ์ฑํ**), OFF(**๊ฑฐ๋ฆฌ๊ฐ์ง๋ชจ๋ ๋น ํ์ฑํ**)
- ON์ผ ๊ฒฝ์ฐ **์๋์ฐจ**์ **์ฅ์ ๋ฌผ**๊ณผ์ ๊ฑฐ๋ฆฌ๋ฅผ LCD์ ํ์.
- ์ฅ์ ๋ฌผ๊ณผ์ ๊ฑฐ๋ฆฌ์ ๋ฐ๋ผ LED๊ฐ ์ ๋ฑ๋๋ ์ ๋ฐ๋.
    - ์ฅ์ ๋ฌผ๊ณผ **๋งค์ฐ ๊ฐ๊น๋ค** : **๋นจ๊ฐ์** LED ์ ๋ฑ
    - ์ฅ์ ๋ฌผ๊ณผ **๊ฐ๊น๋ค** : **๋ธ๋์** LED ์ ๋ฌ
    - ์ฅ์ ๋ฌผ๊ณผ์ **๊ฑฐ๋ฆฌ๊ฐ ๋ฉ๋ค** : **์ด๋ก์** LED ์ ๋ฑ
- LED๋ ์ด์ ์์ ์์ผ๋ฅผ ๊ฐ๋ฆด ์ ์๊ธฐ ๋๋ฌธ์ ์กฐ๋์ผ์๋ฅผ ์ด์ฉํ์ฌ ์ฐจ ๋ด๋ถ ๋น ๋ฐ๊ธฐ์ ๋ฐ๋ผ LED์ ๋ฐ๊ธฐ๊ฐ ์กฐ์ ๋๋ค.
- **๋ธ๋ฃจํฌ์ค ํต์ **์ผ๋ก, ์ ๋ฑ๋๋ LED ๊ฑฐ๋ฆฌ์ ๋ฌผ๋ฆฌ์ ์ธ ๊ธฐ์ค๊ฐ์ ๋ฐ๊พธ์ด ์ฌ์ฉ์๊ฐ ์ปค์คํฐ๋ง์ด์ง ํ  ์ ์๋ค.
- ์ฐจ์ ์ฅ์ ๋ฌผ๊ณผ์ ์ถฉ๋์ด ์ผ์ด๋ **์์ (๋ ์ง, ์๊ฐ)**์ ์ ์ฅํ๊ณ  **๋ธ๋ฃจํฌ์ค ํต์ **์ ํตํ์ฌ ํธ๋ํฐ์ผ๋ก **์๋ฆผ์ ์ ์ก**ํ๋ค.

# ๐ย ์ผ์ ๋ฐ ๋ชจ๋

- ์ด์ํ ์ผ์
- ์กฐ๋ ์ผ์
- LCD ํจ๋
- ๋ธ๋ฃจํฌ์ค ๋ชจ๋(HC-06)
- LED

# โ๏ธ  ์๋ก 

- ํ๋ก์ ํธ ๋ฐฐ๊ฒฝ
    - ์ข์ ๊ธธ์ ์ด์ ํ  ๋ ๋ถ์ํ ๋ง์์ ๊ฐ์ง๊ฒ ๋๋ค.
    - ์ด์ ์ด ๋ฏธ์ํ๋ค๋ฉด ๋ณธ์ธ ์ฐจ์ ํฌ๊ธฐ์ ๋ถํผ๋ฅผ ๊ฐ๋ ํ๊ธฐ ์ด๋ ต๋ค.
    - ๋ฌธ์ฝ์ด๋ ๊ธํ๊ณผ ๊ฐ์ ์ฌ๊ณ ๊ฐ ๋ ๋ชฐ๋ ์ผ์ด๋๋ ๊ฒฝ์ฐ๊ฐ ๋ง๋ค.
- ๋ฌธ์ ์ ์
    - ๊ธฐ์กด ์ฐจ๋๋ค์ ์๋ฆฌ๋ฅผ ํตํด ์ฅ์ ๋ฌผ๊ณผ ๊ฑฐ๋ฆฌ๋ฅผ ์๋ ค์ฃผ์ง๋ง ๋ฌผ๋ฆฌ์ ์ธ ๊ฑฐ๋ฆฌ๋ฅผ ์ ๊ณตํด์ฃผ์ง ์๋๋ค.
    - ๊ตํต์ฌ๊ณ ๊ฐ ์๋์ด์ ์ฐจ์ ์์์ ์ธ์ ์ด๋์ ์ผ์ด๋ฌ๋์ง ์๊ธฐ๊ฐ ์ด๋ ค์ ์ถฉ๋์๊ฐ์ ๊ธฐ๋กํ  ํ์๊ฐ ์๋ค.
- ํ๋ก์ ํธ ๋ชฉํ
    - ์๋์ด๋ธ๋ฅผ ํ์ฉํ ์๋์ฐจ ๊ธํ ๋ฐฉ์ง๋ฅผ ์ํด ๋ฌผ์ฒด ๊ฐ ๊ฑฐ๋ฆฌ ํ์ง ๋ฐ ๊ฒฝ๊ณ  ์๋ฆผ ํด๋ํฐ ์ ์ก ์์คํ ๊ฐ๋ฐ

# ๐ ์์คํ ๊ตฌ์ฑ

![Untitled (1)](https://user-images.githubusercontent.com/73048180/156300604-8397cd45-3fba-4278-9087-f2696fe8bcae.png)

# ๐จ๐ปโ๐ป๋ด๋น ์๋ฌด

- ์๋์ด๋ธ ํ๋ก ๊ตฌ์ฑ
    - ํ๋กํ ํ์์ ํด๊ฒฐํ๊ธฐ์ํ ํ๋ค์ด ์ ํญ ์ฑํ
    - ์ง๊ด์ ์ธ ์ํฉ(Press : HIGH)์ ์ํด ํ๋ค์ด ์ ํญ ์ฌ์ฉ
- ์๋์ด๋ธ ํ๋ก๊ทธ๋๋ฐ ๊ฐ๋ฐ
    - ์กฐ๋์ผ์์ sensing ๊ฐ์ ์ญ๋งคํ, PWM ์ ํตํ ๋ฐ๊ธฐ์ ์ด
    - ์ฝ๋์ ํจ์ํ๋ฅผ ํตํ ์ํํ ๋๋ฒ๊น ํ๊ฒฝ ์กฐ์ฑ
    - ์ค์์น์ ๋ฐ์ด์ฑ ํ์์ ํด๊ฒฐํ๊ธฐ์ํ ๋ก์ง ๊ตฌํ
    - LCD ๊ฐ์ฒด ์์ฑ ๋ฐ ๊ฒฐ๊ณผ ์๊ฐํ
    - ๋ธ๋ฃจํฌ์ค ๊ธฐ๋ฐ ๋น ๋๊ธฐ์ ํต์  ๊ตฌํ
        - ๋ธ๋ฃจํฌ์ค ํต์ ์ ํตํ ๋ช๋ น์ด๊ธฐ๋ฐ ์์คํ ์ ์ด
        - ๋ธ๋ฃจํฌ์ค ํต์  ๊ธฐ๋ฐ ์ถฉ๋ ๊ฐ์ง ๋ชจ๋ํฐ๋ง

# ๐กย ๋๋ ์ 

- ํ๋ก์์์์ ํ๊ณ(๋ฐ์ด์ฑ ํ์)๋ฅผ ํ๋ก๊ทธ๋๋ฐ ์ฝ๋๋ก ํด๊ฒฐ ํ  ์ ์๋ ๋ฒ์ ๋ฐฐ์ฐ๊ฒ ๋จ
- IoT๋ฅผ ํ์ฉํ๊ฒ ํ๋์จ์ด๋ฅผ ์ ์ฐํ๊ฒ ์ปจํธ๋กคํ  ์ ์๊ฒ ๋์ด ์ ์ง ๋ฐ ๋ณด์๊ฐ ๊ฐํธํด์ง์ ์๊ฒ ๋จ.
- ์ผ์ฑ๋ data๋ฅผ ์์ง, ์ ์ฒ๋ฆฌ ๋ถ์์ ํตํด ์๋น์คํ๋ฅผ ํ  ์ ์๋ ์ญ๋ ๊ฐํ

## ๐ ย ํ๊ณ์  ๋ฐ ๋ฏธ๋์ฐ๊ตฌ

### ์ด์ํ ์ผ์์ ์ ํ์ฑ

- ์ด์ํ์ผ์๋ฅผ ์ด์ฉํ์ฌ ์ฝ์ ๊ฐ์ด 0์ผ ๊ฒฝ์ฐ โ์ถฉ๋ ํ๋ค" ๋ผ๊ณ  ํ๋จํ๊ณ  ์ด ํ๋ก์ ํธ๋ฅผ ์งํ ํ์์ผ๋, ์ด์ํ์ผ์๋ ๊ฑฐ๋ฆฌ๊ฐ 0์ธ ์ํ๋ฅผ ์ ์ก์๋ด์ง ๋ชปํ์๋ค.
    
    โ ๋ณธ์ธ์ ๊ฑฐ๋ฆฌ๊ฐ 5cm ๋ฏธ๋ง์ผ์ โ์ถฉ๋ํ๋ค"๋ผ๊ณ  ๊ฐ์ ํ๊ณ  ์ด ํ๋ก์ ํธ๋ฅผ ์งํํ๊ฒ ๋์๋ค.
    

### ์กฐ๋ ์ผ์ ๋ถ๋

- ์กฐ๋ ์ผ์๋ฅผ ํตํด ์ป์ ๊ฐ์ ์ญ ๋งคํํ์ฌ LED์ ๋ฐ๊ธฐ๋ฅผ ์ ์ด ํ์ผ๋, ์กฐ๋ ์ผ์์ ๋ถ๋์ผ๋ก ํ์ฌ ์กฐ๋๊ฐ์ ์ ์ฝ์ด๋ด์ง ๋ชปํ๋ ๊ฒฝ์ฐ๊ฐ ๋ง์๋ค.
    
    โ ๊ทน๋จ์ ์ธ ์กฐ๋ ์ผ์ฑ๊ฒฐ๊ณผ๋ LED ๋ฐ๊ธฐ ์ฐจ์ด๋ฅผ ๋ณด์ฌ์ฃผ์๊ธฐ ๋๋ฌธ์ ํ์ง ์ข์ ์กฐ๋์ผ์๋ฅผ ์ด์ฉํด์ผ๋ง ํ๋ค.
    

## Code

```arduino
#include <Wire.h>                        
#include <SoftwareSerial.h> // ๋ธ๋ฃจํฌ์ค
 
#include <hd44780.h>  // lcd
#include <hd44780ioClass/hd44780_I2Cexp.h>  //lcd
 
#include <core_build_options.h>
#include <swRTC.h> // ์๊ฐ๋ชจ๋
 
swRTC rtc;  //ํด๋์ค ๊ฐ์ฒด ์ ์ธ
 
hd44780_I2Cexp lcd;   // lcd ๊ฐ์ฒด ์์ฑ
 
unsigned int trigPin = 11; // trig
unsigned int echoPin = 12; // echo
 
#define button 2  // ๋ฒํผ ์ฐ๊ฒฐ ํ
 
int red_led = 10; // ๋นจ๊ฐ์ led ํ ๋ฒํธ
int yellow_led = 4; // ๋ธ๋์ led ํ๋ฒํธ
int green_led = 13; // ์ด๋ก์ led ํ๋ฒํธ
 
// ๋๋ฐ์ด์ฑ์ ์ํ ๋ณ์
int cur = 0;  // current
int before = 0;
int state = 0;
int cnt = 0; // count
 
long distance;  // lcd์ ํ์๋  ๊ธธ์ด
long timeDistance;
 
String input = "";  //input ์ด๊ธฐํ
String get_string(String input);
 
 
int d_red = 10; // ๋นจ๊ฐ๋ถ์ด ์ผ์ง ์กฐ๊ฑด(๊ฑฐ๋ฆฌ๊ฐ 10 ๋ฏธ๋ง์ผ๋)
int d_yellow = 50; // ๋ธ๋๋ถ์ด ์ผ์ง ์กฐ๊ฑด( ๊ฑฐ๋ฆฌ๊ฐ 50 ๋ฏธ๋ง์ผ๋)
 
boolean key1 = true;
boolean key2 = true;
boolean key3 = true;
 
void setup(){
 Serial.begin(9600);
 Serial1.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(button, INPUT);
 lcd.init(); // lcd ์ด๊ธฐํ
 lcd.backlight();
 
 pinMode(yellow_led, OUTPUT);
 pinMode(red_led,OUTPUT);
 pinMode(green_led,OUTPUT);
 digitalWrite(red_led, LOW);
 digitalWrite(green_led, LOW);
 
 rtc.stopRTC();            //์ ์ง
 rtc.setTime(02, 15, 30);  //์, ๋ถ, ์ด
 rtc.setDate(12, 6, 2021); //์ผ, ์, ๋
 rtc.startRTC();           //์์
}
void loop(){
   input = get_string(input);
   if(input == "reset"){
     d_yellow = 50;  // ๋ธ๋๋ถ์ด ๊บผ์ง๋ ๊ฑฐ๋ฆฌ๊ฐ 50cm๋ก ์ฌ ์ด๊ธฐํ
     d_red = 10; // ๋นจ๊ฐ๋ถ์ด ๊บผ์ง๋ ๊ฑฐ๋ฆฌ๊ฐ 10cm๋ก ์ฌ ์ด๊ธฐํ
   }else if( input.substring(0,1) == "y"){ // ๋ช๋ น์ด์ ์ฒซ๋ฒ์จฐ ๊ธ์๊ฐ y์ผ ๊ฒฝ์ฐ
     // ๋ช๋ น์ด๊ฐ y๋ก ์์ํ๋ฉด์ ๋ฐ๋๋ ์์น๊ฐ์ด d_red๋ณด๋ค ํด ๊ฒฝ์ฐ!(๋ธ๋๋ถ์ ๋ฑ ๊ฑฐ๋ฆฌ๊ฐ ๋นจ๊ฐ๋ถ ์ ๋ฑ ๊ฑฐ๋ฆฌ๋ณด๋ค ์งฆ์ ์ ์๊ธฐ๋๋ฌธ)
     if(input.substring(1).toInt() > d_red){
       d_yellow = input.substring(1).toInt();  // ๋ช๋ น์ด์ ์ซ์๋งํผ์ ๊ฑฐ๋ฆฌ๊ฐ์ผ๋ก ๋ณํํจ
       key1 = true;
     }else if(key1 && key2){ // yellow์ ๊ฑฐ๋ฆฌ๊ฐ์ด red๋ณด๋ค ์์์ง๊ฒฝ์ฐ(๋ง์ด ์๋๋ ์ํฉ)
       Serial1.print(d_red);
       Serial1.write("๋ณด๋ค ํฌ๊ฒ ์๋ ฅํ์์ผ ํฉ๋๋ค.\n");
       key1 = false;
     }
     
     
   }else if(input.substring(0,1) =="r" ){  // ๋ช๋ น์ด์ ์ฒซ๋ฒ์จฐ ๊ธ์๊ฐ r์ผ ๊ฒฝ์ฐ
     // ๋ช๋ น์ด๊ฐ r๋ก ์์ํ๋ฉด์ ๋ฐ๋๋ ์์น๊ฐ์ด d_yellow๋ณด๋ค ์์ ๊ฒฝ์ฐ๋ง!( ๋นจ๊ฐ๋ถ ์ ๋ฑ๊ฑฐ๋ฆฌ๊ฐ ๋ธ๋๋ถ ์ ๋ฑ๊ฑฐ๋ฆฌ๋ณด๋ค ํด ์ ์๋ค.)
     if(input.substring(1).toInt() < d_yellow){
       d_red = input.substring(1).toInt(); // ๋ช๋ น์ด์ ์ซ์๊ฐ์ผ๋ก ๋นจ๊ฐ๋ถ์ด ์ ๋ฑ๋  ๊ฑฐ๋ฆฌ๊ฐ ์ด๊ธฐํ
       key2 = true;
     }else if (key1 && key2){  // red์ ๊ฑฐ๋ฆฌ๊ฐ์ด yellow์ ๊ฑฐ๋ฆฌ๊ฐ๋ณด๋ค ์ปค์ง๊ฒฝ์ฐ ( ๋ง์ด ์๋๋ ๊ฒฝ์ฐ)
       Serial1.print(d_yellow);
       Serial1.write("๋ณด๋ค ์๊ฒ ์๋ ฅํ์์ผ ํฉ๋๋ค.\n");
       key2 = false;
     }
   }
 
   int cur = digitalRead(button);  // ๋ฒํผ์ ์ํ ๊ฒ์ฌ
   // ๋๋ฐ์ด์ฑ ํด๊ฒฐ
   if(cur != before){
     delay(5);
     cur = digitalRead(button);
   }
   
   if( cur == HIGH && before == LOW){
     state != state;
     Serial.println("๋ฐ๋");
     cnt+=1; // ๋ฒํผ ํด๋ฆญ๋น cnt๊ฐ 1์ฉ ์ฆ๊ฐ
   }
   before = cur;
//    Serial.print(cnt);
   // cnt๊ฐ ์ง์์ผ๋ ํ์์ผ๋ ๋๋์ด์ ๊ธฐ๋ฅ ์คํ
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
     showDistance(); // ๊ฑฐ๋ฆฌ๋ฅผ ๋ณด์ฌ์ฃผ๋ ๋ฉ์๋
     showLight();  // ๋น์ ๋ณด์ฌ์ฃผ๋ ๋ฉ์๋
   }
}
 
 
// ๋ฒํผ์ผ๋ก ์ ์ดํ๊ธฐ์ํด ํจ์๋ก ์์ฑ
void showDistance(){
   
   digitalWrite(trigPin, LOW);// trigํ์์ ์ด์ํ ๋ด๋ณด๋ ์ผ๋จ low๋ก ์ด๊ธฐํํจ
   delayMicroseconds(2); //2 microsecond๋์ ์ ๊น delay
   
   digitalWrite(trigPin, HIGH); // ์ด์ํ๋ฅผ ๋ด๋ณด๋ด๊ธฐ์ํด HIGH
   delayMicroseconds(10); // 10 microsecond๋์ ์ ๊น delay
   digitalWrite(trigPin, LOW); // ์ด์  ๊ทธ๋ง ๋ด๋ณด๋ด๊ธฐ ์ํด LOW๋ก ๋ค์ ๋ฐ๊ฟ์ค
 
   if( digitalRead(echoPin) == LOW){
     // ์ด์ํ์ผ์ ๊ฐ๋ค๊ฐ ๋ค์ ๋์์ค๊ธฐ๋๋ฌธ์ 2๋ก ๋๋์ด์ค, 1cm ์ด๋ํ๋๋ฐ ๊ฑธ๋ฆฌ๋์๊ฐ 29.41us
     distance = (float)pulseIn(echoPin, HIGH)/29/2;
   }else{
     pinMode(echoPin, OUTPUT);
     digitalWrite(echoPin, LOW);
     pinMode(echoPin, INPUT);
   }
   if( distance <= 3){
     time(); // ํ์ฌ์ ์๊ฐ ์ถ๋ ฅ
     Serial.write("   ์ถฉ๋ํ์์ต๋๋ค\n"); // ์ถฉ๋๋ฉ์ธ์ง ์ ๋ฌ
     Serial1.write("   ์ถฉ๋ํ์์ต๋๋ค\n");
   }
   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Distance : ");
   lcd.setCursor(0,1);
   lcd.print(distance);
   lcd.print("cm");
   delay(500); // 0.5์ด๋ง๋ค ์ซ์ ๋ฐ๋๋๋ก
}
 
void showLight(){
 /*
  * 100 ๋ฐ์
  * 400 ํ์ ํ๊ด๋ฑ
  * 800 ์ด๋์
  */
 int cds = analogRead(A1); // ํ์ฌ์ ์กฐ๋๊ฐ์ ์ฝ์ด์ด
 int bright = map(cds, 0, 1023, 255, 0); // ์ด๋์์ง๋ฉด LED๋ ์ด๋์์ง๊ฒ ์ญ๋งคํ
//  Serial.println(cds);
 
 if (distance < d_red){
    // ๊ฑฐ๋ฆฌ๊ฐ d_red ๋ฏธ๋ง์ผ์ ๋นจ๊ฐ๋ถ ํ์ํ๋๋ฐ ํ์ฌ ๋ฐ๊ธฐ์ ๊ณ ๋ คํ์ฌ ๋น ๋ฐ๊ด
   analogWrite(red_led, bright); // ํ์ฌ ์กฐ๋๊ฐ์ ๋ฐ๋น๋กํ์ฌ ๋ฐ๊ธฐ ์กฐ์ 
   digitalWrite(green_led, LOW);
   digitalWrite(yellow_led,LOW);
 }else if(distance < d_yellow){
   // // ๊ฑฐ๋ฆฌ๊ฐ d_red ์ด๊ณผ d_yellow ์ด์์ผ์ ๋ธ๋๋ถ ํ์, ํ์ฌ ๋ฐ๊ธฐ์ ๊ณ ๋ คํ์ฌ ๋น ๋ฐ๊ด
   analogWrite(yellow_led, bright);// ํ์ฌ ์กฐ๋๊ฐ์ ๋ฐ๋น๋กํ์ฌ ๋ฐ๊ธฐ ์กฐ์ 
   digitalWrite(green_led, LOW);
   digitalWrite(red_led, LOW);    
 }else{
   // ๊ฑฐ๋ฆฌ๊ฐ d_yellow ์ด์์ผ์ ์ด๋ก๋ถ ํ์, ํ์ฌ ๋ฐ๊ธฐ์ ๊ณ ๋ คํ์ฌ ๋น ๋ฐ๊ด
   digitalWrite(red_led, LOW);
   analogWrite(green_led, bright);// ํ์ฌ ์กฐ๋๊ฐ์ ๋ฐ๋น๋กํ์ฌ ๋ฐ๊ธฐ ์กฐ์ 
   digitalWrite(yellow_led, LOW);
 }
 delay(100);
}
 
String get_string(String input){
 String inputString = "";             // ์๋ฌด๊ฒ๋ ์๋ ฅํ์ง ์์์ ๋ ๋น ๋ฌธ์์ด
 while(Serial1.available()) {      // ๋ธ๋ฃจํฌ์ค ํต์ ์ ๋ฐ์ดํฐ๊ฐ ์๋ ฅ๋๋ฉด(์ค๋งํธํฐ -> ์๋์ด๋ธ)
   delay(3);                         // ๋ฐ์ดํฐ ์์ ์ด ์ ์ด๋ฃจ์ด์ง๊ธฐ ์ํด 3ms ๊ธฐ๋ค๋ฆผ
   if (Serial1.available() >0) {   // ์์ ๋ ๋ฐ์ดํฐ๊ฐ ์์ผ๋ฉด
     char c = Serial1.read();      // ์์ ๋ ๋ฐ์ดํฐ 1๊ฐ๋ฅผ ๋ฐ์ c๋ก ์ ์ฅ(์ดํ์๋ ๊ทธ๋ค์๊ฑธ ๋ฐ์ c๋ก ์ ์ฅ
     inputString += c;                // ์์ ๋ ๋ฐ์ดํฐ๋ฅผ c์ ๋ถ์.
   }
 }
 if(inputString.length() == 0) return input;    // ๋ฌธ์์ด ๊ธธ์ด๊ฐ 0์ด๋ฉด(๋ฐ์ดํฐ๋ฅผ ์๋ ฅ๋ฐ์ง ์์๋ค๋ฉด) ๊ธฐ์กด์ ๊ฐ์ ๋ฐํ  
 else return inputString;             // ๋ฐ์ดํฐ๋ฅผ ์๋ ฅ๋ฐ์๋ค๋ฉด ํด๋น ๋ฌธ์์ด์ ์ถ๋ ฅ
}
 
// ํ์ฌ ์๊ฐ ์ถ๋ ฅํจ์
void time(){
 Serial1.print(rtc.getYear(), DEC);  // ์ฐ๋
 Serial1.print("/");
 Serial1.print(rtc.getMonth(), DEC); // ์
 Serial1.print("/");
 Serial1.print(rtc.getDay(), DEC); // ์ผ
 Serial1.print("\t");
 
 Serial1.print(rtc.getHours(), DEC); // ์
 Serial1.print(":");
 Serial1.print(rtc.getMinutes(), DEC); // ๋ถ
 Serial1.print(":");
 Serial1.print(rtc.getSeconds(), DEC); // ์ด
}
```
