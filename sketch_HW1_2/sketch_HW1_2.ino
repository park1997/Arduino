int pins_LED[] = {2,3,4,5,6,7,8}; // LED 연결 핀
// 버튼 연결 핀 (15 : 풀다운 저항, 16 : 풀업 저항)
int pins_button[] = {15,11};
int arr[] = {0,0,0,0,0,0,0};
int ledstate = 0;

void setup() {
  Serial.begin(9600); // 시리얼 통신 초기화
  for (int i = 0; i < 7; i++) {
    pinMode(pins_LED[i], OUTPUT); // LED 연결 핀을 출력으로 설정
  }
  for (int i = 0; i < 2; i++) {
    pinMode(pins_button[i], INPUT); // 버튼 연결 핀을 입력으로 설정
  }
}

void loop() {
 
  boolean state1 = digitalRead(pins_button[0]); // 왼쪽 버튼 상태 읽기
  boolean state2 = digitalRead(pins_button[1]); // 오른쪽 버튼 상태 읽기
  
  Serial.print(state1);
  Serial.print(" ");
  Serial.print(state2);
  Serial.print(" ");
  Serial.println(ledstate);
  
  if (state1==1 && state2==0){ // 왼쪽 버튼을 눌렀을때 ledstate 를 -=1해줌
    ledstate -= 1; // ledstate가 나중에 arr의 인덱스가 된다
  }else if(state1==0 && state2==1){ //오른쪽 버튼을 눌렀을때 ledstate +=1해줌
    ledstate += 1; 
  }

  if(ledstate > 6){ // 오른쪽 맨끝 led에서 오른쪽 버튼누르면 처음led로 이동한다
    ledstate=0;
  }
  if(ledstate<0){ // led 가 왼쪽끝에서 왼쪽버튼누르면 오른쪽 맨끝 led로 이동
    ledstate=6;
  }
  
  
  for(int i=0; i<7; i++){ // 버튼누른 값에따라 arr의 인덱스 조정
    if(i == ledstate){
      arr[i] = 0;
    }
    else{
      arr[i] = 1;
    }
  }
  
  for (int i = 0; i < 7; i++) {
    digitalWrite(pins_LED[i], arr[i]); // LED 출력
    Serial.print(arr[i]);
    Serial.print(" ");
  }
  Serial.println(ledstate);
  
  
  
  delay(2000); // 바운싱현상으로 딜레이를 크게 잡았습니다(2초)
}
