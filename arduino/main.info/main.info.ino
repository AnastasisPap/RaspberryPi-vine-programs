//Soil moisture sensor: SIG->A0, GND->GND, VCC->7
//Gas sensor: VCC->5V, GND->GND, A0->A5
//Ultrasonic sensor: GND->GND, Echo->12, Trig->11, VCC->5V
//(DHT22)Humidity and temperature sensor: (from the left)pin#1 -> 5V, pin#2 -> arduino pin 2, pin#4 -> GND
//(DHT11) S -> 8, middle -> 5V, - -> GND


#include<dht11.h>

dht11 DHT11;
#define DHT11PIN 8 

int smokeA0 = A5;
int sensorThres = 350;

int val = 0;
int soilPin = A0;
int soilPower = 7;

int trigPin = 11;
int echoPin = 12;
long duration, cm;

void setup() {
  Serial.begin(9600);
//DHT22
  
//Soil moisture
  pinMode(soilPower, OUTPUT);
  digitalWrite(soilPower, LOW);
//Ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//Gas sensor
  pinMode(smokeA0, INPUT);
}

void loop() {
//DHT11
  int chk = DHT11.read(DHT11PIN);
  int temperature = DHT11.temperature;
  int humidity = DHT11.humidity;
//DHT22 humidity and temperature
//  int humidity = dht.readHumidity();
//  int temperature = dht.readTemp  erature();

  Serial.print(temperature);
  Serial.print("?");
  Serial.print(humidity);

  Serial.print("?");
//Soil moisture  
  Serial.print(readSoil());

  Serial.print("?");
//Gas sensor
  int analogSensor = analogRead(smokeA0);
  if (analogSensor >= sensorThres){
    Serial.print("Gas detected");        
  }else{
    Serial.print(analogSensor);
  }
  Serial.print("?");
//Ultrasonic 
  Serial.println(get_distance());  

  delay(2000);
}

float get_distance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration/2)/29.1;
  return cm;
}

int readSoil(){
  digitalWrite(soilPower, HIGH);
  delay(10);
  val = analogRead(soilPin);
  digitalWrite(soilPower, LOW);
  return val;
}
