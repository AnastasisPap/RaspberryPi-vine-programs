//Soil moisture sensor: SIG->A0, GND->GND, VCC->7
//Gas sensor: VCC->5V, GND->GND, A0->A5
//Ultrasonic sensor: GND->GND, Echo->12, Trig->11, VCC->5V
//(DHT22)Humidity and temperature sensor: (from the left)pin#1 -> 5V, pin#2 -> arduino pin 9 and through a 10k ohm res that connects to 5V, pin#4 -> GND
//(DHT11) S -> 9, middle -> 5V, - -> GND
//Electret microphone: VCC -> 5V, GND -> GND, OUT -> arduino pin 8
#include<FreqMeasure.h>
#include<dht11.h>

#define DHTPIN 9
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

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
//MAX4466
  FreqMeasure.begin();
//Soil moisture
  pinMode(soilPower, OUTPUT);
  digitalWrite(soilPower, LOW);
//Ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//Gas sensor
  pinMode(smokeA0, INPUT);
//DHT22
  dht.begin();
}

double sum = 0;
int count = 0;
int max_freqs[4] = {300, 850, 6000, 7400};
int min_freqs[4] = {200, 350, 5000, 6600};
int pos = 5;

void loop() {
//MAX4466
  if(FreqMeasure.available()){
    sum = sum + FreqMeasure.read();
    count = count + 1;

    if(count > 30){
      float frequency = FreqMeasure.countToFrequency(sum/count);      
      for(int i = 0; i< 4; i++){
        if(frequency > min_freqs[i] && frequency < max_freqs[i]){
          pos = i; 
        }        
      }
      switch(pos){
        case 1:
          Serial.println("Honeybee");
          break;
        case 2:
          Serial.println("Mosquito");
          break;
        case 3:
          Serial.println("Chainsaw");
          break;
        case 4:
          Serial.println("Cricket");
          break;
        default:
          Serial.println("None");
          break;
         
      }
      Serial.println(frequency);      
      sum = 0;
      count = 0;
    }else{
      Serial.println("None");
    }
  }

//DHT11
//  int chk = DHT11.read(DHT11PIN);
//  int temperature = DHT11.temperature;
//  int humidity = DHT11.humidity;
  DHT22 humidity and temperature
  float humidity = dht.readHumidity();
  float temperature = dht.readTemp  erature();

  Serial.print(temperature);
  Serial.print("?");
  Serial.print(humidity);

  Serial.print("?");
//Soil moisture  
  value = readSoil();
  if(value < 850){
    Serial.print("Needs water");
  }else{
    Serial.print(value);  
  }
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
