const int ledPinW = 12;
const int ledPinWW = 10;
const int ledPinR = 13;
const int ledPinRR = 11;
const int ledPinY = 7; 
const int ledPinYY = 2; 

void setup(){
    pinMode(ledPinW, OUTPUT);
    pinMode(ledPinWW, OUTPUT);
    pinMode(ledPinR, OUTPUT);
    pinMode(ledPinRR, OUTPUT);
    pinMode(ledPinY, OUTPUT);
    pinMode(ledPinYY, OUTPUT);    
}

void loop(){
    digitalWrite(ledPinW, 1);
    digitalWrite(ledPinWW, 1);
    digitalWrite(ledPinR, 1);
    digitalWrite(ledPinRR, 1);
    digitalWrite(ledPinY, 1);
    digitalWrite(ledPinYY, 1);
    delay(500);
    digitalWrite(ledPinW, 0);
    digitalWrite(ledPinWW, 0);
    digitalWrite(ledPinR, 0);
    digitalWrite(ledPinRR, 0);
    digitalWrite(ledPinY, 0);
    digitalWrite(ledPinYY, 0);
    delay(500);   
}