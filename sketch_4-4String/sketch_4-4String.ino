void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String str1 = "One String", str2 = "Another String";
  int n = 1234;
  float f = 3.14;
  char c = 'A';

  Serial.println(str1); //String 출력
  Serial.println(str1 + " " +str2); //문자열 연결
  Serial.println(String(n)); //정수로 부터 10진 문자열 생성
  Serial.println(String(n,BIN)); //정수로 부터 2진 문자열 생성
  Serial.println(String(n,HEX)); // 정수로 부터 16진 문자열 생성
  Serial.println();
  
  // 실수의 경우 문자열로 직접 변환할 수 없다.
  // 단, Serial클래스의 print 함수는 문자열 형식의 
//   Serial.println(String(f));
  Serial.println(f);
  //다른 타입의 데이터를 연결하여 새로운 String 
  Serial.println("String + integer : "+String(n));
  String str3 = "String + charcter : ";
  str3 += c;
  Serial.println(str3);
  Serial.println();

  while(true);


  
}
