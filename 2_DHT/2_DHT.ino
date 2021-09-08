#include <DHT.h>
#define DHTPIN A1
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
//  Serial.print("humidity : ");
  Serial.println(h);
//  Serial.print("\t temperature : ");
//  Serial.println(t);
//  Serial.println();
  
}
