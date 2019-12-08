void setup(){
    Serial.begin(9600);
}
int a = 0;

void loop(){
    a++;
    Serial.println(a);
    delay(1000);
}
