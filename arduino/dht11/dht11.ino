#include<dht11.h>

dht11 DHT11;
#define DHT11PIN 7

void setup(){
  Serial.begin(9600);
}

void loop(){
  int chk = DHT11.read(DHT11PIN);
  int temperature = DHT11.temperature;
  int humidity = DHT11.humidity;
  
  Serial.print(temperature);
  Serial.print(" ");
  Serial.println(humidity);
  delay(2000);
}
