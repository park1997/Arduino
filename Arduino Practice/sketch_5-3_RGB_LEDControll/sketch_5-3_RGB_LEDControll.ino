int RGB_LED[] ={6,7,8}  // RGB LED연결핀

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<3;i++){
    pinMode(RGB_LED[i],OUTPUT);
  }
}

void loop() {
  // blue 색상 조절, green, red 끔
  digitalWrite(RGB_LED[1],LOW);
  digitalWrite(RGB_LED[2],LOW);
  for(int i=0;i<256;i++){
    analogWrite(RRB_LED[0],i);
    delay(10);
  }

  // green색상 조절, blue,red 끔
  digitalWrite(RGB_LED[0],LOW);
  digitalWrite(RGB_LED[2],LOW);
  for(int i=0; i<256;i++){
    digitalWrite(RGB_LED[1],i);
    delay(10); 
  }

  // red색상조절 green blue끔
  digitalWrite(RGB_LED[0],LOW);
  digitalWrite(RGB_LED[1],LOW);
  for(inti=0;i<256;i++){
    digitalWrite(RGB_LED[2],i);
    delay(10);
  }


  
}
