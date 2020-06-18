//------------------- Servo (library + ประกาศตัวแปร)
#include <Servo.h>  
Servo myservo; 

int degree = 0;
//------------------- SevenSegment (library + ประกาศตัวแปร) 
#include "TM1637.h" 

const int CLK = 17;
const int DIO = 16;

TM1637 sevenSegment(CLK, DIO);
//------------------- Ultrasonic (ประกาศตัวแปร)
const int trigPin = 6; 
const int echoPin = 5;

int duration; 
int distance; 
int safetyDistance;
//------------------- Flame (ประกาศตัวแปร)
const int flamePin = 0; 
int flameReading;
//-------------------- ประกาศตัว Output (แสงไฟ+เสียง) 
const int ledPinW = 12; 
const int ledPinR = 13; 
const int ledPinWW = 10; 
const int ledPinRR = 11;
const int ledPinY = 7;
const int ledPinYY = 2;
const int buzzerPin = 9; 

void setup(){
    //----------------------- Servo (แสดงค่า)
    myservo.attach(4,0,180);
    //----------------------- SevenSegment (แสดงค่า)
    sevenSegment.init(); 
    sevenSegment.set(7);  
    //----------------------- Ultrasonic (แสดงค่า)  
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT);
    //----------------------- Flame (แสดงค่า) 
    pinMode(flamePin, INPUT);
    //----------------------- Output แสงไฟ+เสียง (แสดงค่า)
    pinMode(ledPinW,OUTPUT); 
    pinMode(ledPinR,OUTPUT); 
    pinMode(ledPinWW,OUTPUT); 
    pinMode(ledPinRR,OUTPUT);
    pinMode(ledPinY, OUTPUT);
    pinMode(ledPinYY, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    //------------------------     
    Serial.begin(9600);                  
}
 
void loop(){
    //---------------------------------------- Servo (ขาไป)
    for(degree = 0; degree < 180; degree += 1) 
    {
        myservo.write(degree); 
        delay(50);
        //------------------------------------ Ultrasonic (การทำงาน) 
        digitalWrite(trigPin, 0); 
        delayMicroseconds(2); 

        digitalWrite(trigPin, 1); 
        delayMicroseconds(10);
        digitalWrite(trigPin, 0); 

        duration = pulseIn(echoPin , 1); 

        distance = duration*0.034/2; 

        safetyDistance = distance;
        if (safetyDistance <= 20)
        { 
            digitalWrite(ledPinW, 1);
            digitalWrite(ledPinR, 1);
            digitalWrite(ledPinRR, 1);
            //digitalWrite(ledPinWW, 1);
        }
        else
        {
            digitalWrite(ledPinW, 0);
            digitalWrite(ledPinR, 0);
            digitalWrite(ledPinRR, 0);
            //digitalWrite(ledPinWW, 0);
        }
        //------------------------------------- Flame (การทำงาน)
        flameReading = analogRead(flamePin); 
        if (flameReading <= 500 ) 
        {
            digitalWrite(buzzerPin, 1); 
            //analogWrite(ledPinW, 255); 
            analogWrite(ledPinY, 255);
            analogWrite(ledPinWW, 255);
            analogWrite(ledPinYY, 255);
            //--------------------------------- SevenSegment (การทำงาน)
            sevenSegment.displayStr("S0S"); 
            delay(1000); 
            sevenSegment.displayStr("HELP"); 
            delay(1000);        
        }
        else 
        {
            digitalWrite(buzzerPin, 0);
            //analogWrite(ledPinW, 0);
            analogWrite(ledPinY, 0);
            analogWrite(ledPinWW, 0);
            analogWrite(ledPinYY, 0);
            sevenSegment.displayStr(""); 
            delay(5);         
        }
        //---------------------------------- Ultrasonic (แสดงใน Serial Monitor)
        //Serial.print("Distance: "); 
        //Serial.println(distance); 
        //delay(1000);
        //---------------------------------- Flame (แสดงใน Serial Monitor) 
        //Serial.print("Analog reading = "); 
        //Serial.println(flameReading);
        //delay(1000);                        
    }
    
    //----------------------------------------- Servo (ขากลับ)
    for(degree = 180; degree >= 1; degree -= 1)
    {
        myservo.write(degree);
        delay(50);
        //------------------------------------ Ultrasonic (การทำงาน) 
        digitalWrite(trigPin, 0); 
        delayMicroseconds(2); 

        digitalWrite(trigPin, 1); 
        delayMicroseconds(10);
        digitalWrite(trigPin, 0); 

        duration = pulseIn(echoPin , 1); 

        distance = duration*0.034/2; 

        safetyDistance = distance;
        if (safetyDistance <= 20)
        { 
            digitalWrite(ledPinW, 1);
            digitalWrite(ledPinR, 1);
            //digitalWrite(ledPinWW, 1);
            digitalWrite(ledPinRR, 1);
        }
        else
        {
            digitalWrite(ledPinW, 0);
            digitalWrite(ledPinR, 0);
            //digitalWrite(ledPinWW, 0);
            digitalWrite(ledPinRR, 0);
        }
        //------------------------------------- Flame (การทำงาน)
        flameReading = analogRead(flamePin); 
        if (flameReading <= 500 ) 
        {
            digitalWrite(buzzerPin, 1); 
            //analogWrite(ledPinW, 255); 
            analogWrite(ledPinY, 255);
            analogWrite(ledPinWW, 255);
            analogWrite(ledPinYY, 255);
            sevenSegment.displayStr("S0S"); 
            delay(1000); 
            sevenSegment.displayStr("HELP"); 
            delay(1000);        
        }
        else 
        {
            digitalWrite(buzzerPin, 0);
            //analogWrite(ledPinW, 0);
            analogWrite(ledPinY, 0);
            analogWrite(ledPinWW, 0);
            analogWrite(ledPinYY, 0);
            sevenSegment.displayStr(""); 
            delay(5);       
        }
        //---------------------------------- Ultrasonic (แสดงใน Serial Monitor)
        //Serial.print("Distance: "); 
        //Serial.println(distance); 
        //delay(500);
        //---------------------------------- Flame (แสดงใน Serial Monitor) 
        //Serial.print("Analog reading = "); 
        //Serial.println(flameReading);
        //delay(500);                           
    }
    //---------------------------------- Ultrasonic (แสดงใน Serial Monitor)
    Serial.print("Distance: "); 
    Serial.println(distance); 
    delay(1000);
    //---------------------------------- Flame (แสดงใน Serial Monitor) 
    Serial.print("Analog reading = "); 
    Serial.println(flameReading);
    delay(1000);    
}

