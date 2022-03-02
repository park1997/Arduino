/*
 * 183-1 사물인터넷보드(wemos d1r1)가 원하는 시점에 현재시간을 가져와보자!
 * 일단 구글서버(google.com)에 접속한다음 head를 요청해서 시간값을 가져온다음
 * 우리나라에 맞게 local time을 계산해서 활용할 수 있도록 해보자!
 * 앞으로 진행될 예제에 local time이 필요한 상황이 많을 것 같으므로 함수로 구현해보자!
 */

#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "your-ssid" //와이파이 검색했을때 뜨는 이름
#define STAPSK  "your-password" //패스워드
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
WiFiClient client;

typedef struct{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
}Nocktime;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  
  
  Serial.println("DONE");
}

void loop() {
  Nocktime nt;
  if(get_nocktime(nt)){
    //정상적으로 값을 받은경우
    Serial.print("YEAR=");
    Serial.println(nt.year);
    Serial.print("MONTH=");
    Serial.println(nt.month);
    Serial.print("DAY=");
    Serial.println(nt.day);
    Serial.print("HOUT=");
    Serial.println(nt.hour);
    Serial.print("MINUTE=");
    Serial.println(nt.minute);
    Serial.print("SECOND=");
    Serial.println(nt.second);
  }else{
    //에러가난경우
  }
  

  delay(10000);
}

bool get_nocktime(Nocktime &t){
  //--------------------------------------------
  //클라이언트와 서버와 커넥트
  if (!client.connect("google.com", 80)) {
    Serial.println("connection failed");
    return false;
  }
  client.print("HEAD / HTTP/1.1\r\n\r\n");

  //서버로부터 응답이 있을때까지 대기하겠다..
  //언제까지 기다려야하나요..?
  //timeout!
  unsigned long timeout = millis(); //생존시간
  while(1){
    if(client.available()) break;
    if(millis() - timeout > 10000) break;
  }


  //응답이 날라오는 부분!
  Serial.println("request sent");

  bool iscollected = false;
  while(client.available()){
    String data = client.readStringUntil('\n'); //readline();
    //Date: Thu, 17 Dec 2020 10:26:44 GMT
    //01234567890123456789012345678901234
    
    if(data.indexOf("Date: ") != -1){
      //검색결과 date:라는 패턴이 존재하더라~
      //조건문안에 들어온 시점에 data안에는 우리가 원하는 값이 들어있다!
      iscollected = true;
      //Serial.println(data);
      int day = data.substring(11,13).toInt(); //day
      int month = 0;
      //Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
      String mo = data.substring(14,17);
      if(mo == "Jan"){
        month = 1;
      }else if(mo == "Feb"){
        month = 2;
      }else if(mo == "Mar"){
        month = 3;
      }else if(mo == "Apr"){
        month = 4;
      }else if(mo == "May"){
        month = 5;
      }else if(mo == "Jun"){
        month = 6;
      }else if(mo == "Jul"){
        month = 7;
      }else if(mo == "Aug"){
        month = 8;
      }else if(mo == "Sep"){
        month = 9;
      }else if(mo == "Oct"){
        month = 10;
      }else if(mo == "Nov"){
        month = 11;
      }else if(mo == "Dec"){
        month = 12;
      }
      int year = data.substring(18,22).toInt(); //year
      int hour = data.substring(23,25).toInt(); //hour
      int minute = data.substring(26,28).toInt(); //minute
      int second = data.substring(29,31).toInt(); //second

      int dayofmonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
      //년도가 4의 배수일때마다 2월이 29일까지다!
      //year % 4 == 0
      hour += 9;
      if(hour > 24){
        //20 + 9 = 29 = 29-24 = 5
        hour -= 24;
        day++;
        int yoondal = 0;
        if(year % 4 == 0 && month == 2) yoondal = 1;
        
        if(day > dayofmonth[month-1]+yoondal){
          day -= dayofmonth[month-1]+yoondal;
          month++;
          if(month > 12){
            month -= 12;
            year++;
          }
        }
      }
      /*
      Serial.println(year);
      Serial.println(month);
      Serial.println(day);
      Serial.println(hour);
      Serial.println(minute);
      Serial.println(second);
      */
      t.year = year;
      t.month = month;
      t.day = day;
      t.hour = hour;
      t.minute = minute;
      t.second = second;
    }
  }  

  return iscollected;
}
/*
 * 183-1 사물인터넷보드(wemos d1r1)가 원하는 시점에 현재시간을 가져와보자!
 * 일단 구글서버(google.com)에 접속한다음 head를 요청해서 시간값을 가져온다음
 * 우리나라에 맞게 local time을 계산해서 활용할 수 있도록 해보자!
 * 앞으로 진행될 예제에 local time이 필요한 상황이 많을 것 같으므로 함수로 구현해보자!
 */

#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "your-ssid" //와이파이 검색했을때 뜨는 이름
#define STAPSK  "your-password" //패스워드
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
WiFiClient client;

typedef struct{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
}Nocktime;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  
  
  Serial.println("DONE");
}

void loop() {
  Nocktime nt;
  if(get_nocktime(nt)){
    //정상적으로 값을 받은경우
    Serial.print("YEAR=");
    Serial.println(nt.year);
    Serial.print("MONTH=");
    Serial.println(nt.month);
    Serial.print("DAY=");
    Serial.println(nt.day);
    Serial.print("HOUT=");
    Serial.println(nt.hour);
    Serial.print("MINUTE=");
    Serial.println(nt.minute);
    Serial.print("SECOND=");
    Serial.println(nt.second);
  }else{
    //에러가난경우
  }
  

  delay(10000);
}

bool get_nocktime(Nocktime &t){
  //--------------------------------------------
  //클라이언트와 서버와 커넥트
  if (!client.connect("google.com", 80)) {
    Serial.println("connection failed");
    return false;
  }
  client.print("HEAD / HTTP/1.1\r\n\r\n");

  //서버로부터 응답이 있을때까지 대기하겠다..
  //언제까지 기다려야하나요..?
  //timeout!
  unsigned long timeout = millis(); //생존시간
  while(1){
    if(client.available()) break;
    if(millis() - timeout > 10000) break;
  }


  //응답이 날라오는 부분!
  Serial.println("request sent");

  bool iscollected = false;
  while(client.available()){
    String data = client.readStringUntil('\n'); //readline();
    //Date: Thu, 17 Dec 2020 10:26:44 GMT
    //01234567890123456789012345678901234
    
    if(data.indexOf("Date: ") != -1){
      //검색결과 date:라는 패턴이 존재하더라~
      //조건문안에 들어온 시점에 data안에는 우리가 원하는 값이 들어있다!
      iscollected = true;
      //Serial.println(data);
      int day = data.substring(11,13).toInt(); //day
      int month = 0;
      //Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
      String mo = data.substring(14,17);
      if(mo == "Jan"){
        month = 1;
      }else if(mo == "Feb"){
        month = 2;
      }else if(mo == "Mar"){
        month = 3;
      }else if(mo == "Apr"){
        month = 4;
      }else if(mo == "May"){
        month = 5;
      }else if(mo == "Jun"){
        month = 6;
      }else if(mo == "Jul"){
        month = 7;
      }else if(mo == "Aug"){
        month = 8;
      }else if(mo == "Sep"){
        month = 9;
      }else if(mo == "Oct"){
        month = 10;
      }else if(mo == "Nov"){
        month = 11;
      }else if(mo == "Dec"){
        month = 12;
      }
      int year = data.substring(18,22).toInt(); //year
      int hour = data.substring(23,25).toInt(); //hour
      int minute = data.substring(26,28).toInt(); //minute
      int second = data.substring(29,31).toInt(); //second

      int dayofmonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
      //년도가 4의 배수일때마다 2월이 29일까지다!
      //year % 4 == 0
      hour += 9;
      if(hour > 24){
        //20 + 9 = 29 = 29-24 = 5
        hour -= 24;
        day++;
        int yoondal = 0;
        if(year % 4 == 0 && month == 2) yoondal = 1;
        
        if(day > dayofmonth[month-1]+yoondal){
          day -= dayofmonth[month-1]+yoondal;
          month++;
          if(month > 12){
            month -= 12;
            year++;
          }
        }
      }
      /*
      Serial.println(year);
      Serial.println(month);
      Serial.println(day);
      Serial.println(hour);
      Serial.println(minute);
      Serial.println(second);
      */
      t.year = year;
      t.month = month;
      t.day = day;
      t.hour = hour;
      t.minute = minute;
      t.second = second;
    }
  }  

  return iscollected;
}
