const int buzzer = 9;

void setup(){
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);   
    //delay(1000);
}

void loop(){
    digitalWrite(buzzer, 1);
    delay(500); //หน่วงเวลา 0.5 วินาที
    digitalWrite(buzzer, 0);
    delay(500); //หน่วงเวลา 0.5 วินาที
}