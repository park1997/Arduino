int pins[] = {2,3,4,5};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // 시리얼 통신 초기화
  for(int i=0;i<4;i++){
    pinMode(pins[i],OUTPUT); //출력 모드로 설정
    digitalWrite(pins[i],LOW); // 꺼진 상태로 시작
  }
}

void loop() {
  int temp=0; // 이진수를 만들기위해 필요한 temp 변수 선언
  for(int i=0;i<=15;i++){
    int number[] = {0,0,0,0}; // 2진수가 들어갈 배열 공간
    temp=i;
    for(int j=0;j<4;j++){
      number[j]=temp%2; // for 문이 0부터 15까지 돌아가면서 이진수를위한 숫자 0또는 1의숫자 삽입
      temp/=2;  
    }
    digitalWrite(5,number[3]);
    digitalWrite(4,number[2]);
    digitalWrite(3,number[1]);
    digitalWrite(2,number[0]);
    delay(1000); //1초 쉼

  }

    
}
