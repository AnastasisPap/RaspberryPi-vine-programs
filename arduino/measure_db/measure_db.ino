
const int sampleWindow = 50;
unsigned int sample;

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long startMillis = millis();
  float peakToPeak = 0;

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;
  
  while(millis() - startMillis < sampleWindow){
    sample = analogRead(3);
    if(sample < 1024){
      if(sample > signalMax){
        signalMax = sample;    
      }else if(signalMin > sample){
        signalMin = sample;
      }
    }
  }
  peakToPeak = signalMax - signalMin;
  float db = map(peakToPeak, 20, 900, 49.5, 90);
  Serial.println(db);
  delay(1000);
}
