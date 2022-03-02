int analog = A5;
int led = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  int val = analogRead(analog);
  val = map(val,0,1023,0,255);
  Serial.println(val);
  analogWrite(led,val);
  
}
