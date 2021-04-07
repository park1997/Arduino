void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String str[5] = {"bbb","aaa","eee","ddd","ccc"};
  
  //compareTo() : 문자열의 사전순 값을 비교하여 그에 해당되는 int 값을 리턴한다.
  for(int i=0;i<4;i++){
    for(int j =i+1 ; j<5;j++){
      int compare = str[i].compareTo(str[j]);
      if(compare>0){ //오름차순으로 정렬!
        String temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }

  for(int i=0;i<5;i++){
    Serial.println(str[i]);
  }
  



}
