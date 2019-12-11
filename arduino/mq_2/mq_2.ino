#define gasPin A0


void setup() {
  Serial.begin(9600);
}

void loop() {
  int gasSensor = analogRead(gasPin);
  if (gasSensor>=350){
    Serial.print("Value: ");
    Serial.println(gasSensor);
    Serial.println("Gas is detected");
    delay(2000);
  }
  else{
    Serial.print("Value: ");
    Serial.println(gasSensor);
    Serial.println("No gas detected");
    delay(2000); 
  }
}
