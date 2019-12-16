#include<FreqMeasure.h>

void setup() {
  Serial.begin(9600);
  FreqMeasure.begin();
}

double sum = 0;
int count = 0;
int max_freqs[4] = {300, 850, 6000, 7400};
int min_freqs[4] = {200, 350, 5000, 6600};
int pos = 5;

void loop() {
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
}
