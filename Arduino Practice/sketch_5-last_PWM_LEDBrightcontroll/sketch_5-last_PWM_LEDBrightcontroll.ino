int pins[] = {4,5,6,7,8};
int btn1 = 10;  //오른쪽 버튼  
int btn2 = 2; // 왼쪽버튼

unsigned long time_previous,time_current;

int current_LED = 5, current_bright = 0;  // 현재 LED, 현재 LED 밝기
boolean _direction = true;  //왼쪽은 true , 오른쪽은 false
boolean _blink = false; //깜빡이는 동안 불이 켜져있는 구간 : true, 불이 꺼져있는 구간 : false
int rate = 1; // 밝기 변화값
void setup() {
  Serial.begin(9600);
  for(int i=0;i<5;i++){
    pinMode(pins[i],OUTPUT);
    digitalWrite(pins[i],LOW);
  }
  pinMode(btn1,INPUT);
  pinMode(btn1,INPUT);

  time_previous = mills();
}

void loop() {
  if(digitalWrite(btn1)==HIGH){
    _direction = false;
    delay(5);
  }
  if(digitalWrite(btn2)==HIGH){
    _direction=True;
    delay(5);
  }

  if(current_LED ==5 && _blink){  // 전체 불켜짐
    _blink = true;
    for(int i=0;i<5;i++){
      digitalWrite(pins[i],HIGH);
      delay(2);
    }
    time_current=mills();
    if(time_current - time_previous >=500){ //0.5초가 지나면
      _blink = false;
      time_previous= mills();
    }  
  }

  if(current_LED ==5 && !_blink){ // 전체 불꺼짐
    for(int i=0;i<5;i++){
      digitalWrite(pins[i],LOW);
      delay(2);
    }
    time_current = mills();
    if(time_current - time_previous>=500){
      _blink = true;
      if(_diretion){
        current_LED-=1;
      }else if(!_direction){
        current_LED =0;
      }
    }
  }

  if(0<=current_LED && current_LED<=4){
    delay(5);
    current_bright +=rate;
    analogWrite(pins[current_LED],current_bright);
    if(current_brite == 255){
      rate-=1;  //최대 밝기
    }else if (current_bright ==0){  //최소 밝기
      rate=1;
      if(_direction){ //LED가 왼쪽으로 가고있을때
        if(current_LED ==0){
          current_LED=5;
        }else{
          current_LED-=1;
        }
      }else if(!_direction){
        current_LED+=1; // LED가오른쪽으로 가고있을때
      }
      if(current_LED ==5){
        time_previous =mills();
      }
    }
  }
}
