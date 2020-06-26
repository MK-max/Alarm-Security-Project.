//------------------- Servo (library + ประกาศตัวแปร)
#include <Servo.h>                                      // เรียกไลบรารี่ ชื่อ servo.h เข้ามาใช้ในโปรแกรม
Servo myservo;                                          // สร้างตัว library เพื่อให้อดูโน่ควบคุม Servo ได้ 

int degree = 0;                                         // ตัวแปรจัดเก็บค่าองศาServo ให้กำหนดเริ่มต้นเท่ากับ 0 องศา
//------------------- SevenSegment (library + ประกาศตัวแปร) 
#include "TM1637.h"                                     // เรียกไลบรารี่ ชื่อ TM1637.h เข้ามาใช้ในโปรแกรม

const int CLK = 17;
const int DIO = 16;

TM1637 sevenSegment(CLK, DIO);                          // สร้างตัว library เพื่อจัดเก็บชนิดobjectและส่วนที่รับพารามิเตอร์ (CLK, DIO)
//------------------- Ultrasonic (ประกาศตัวแปร)
const int trigPin = 6; 
const int echoPin = 5;

int duration;                                           // ตัวแปรจัดเก็บค่าระยะเวลา
int distance;                                           // ตัวแแปรจัดเก็บค่าระยะทาง
int safetyDistance;                                     // ตัวแปรจัดเก็บค่าระยะที่ปลอดภัย
//------------------- Flame (ประกาศตัวแปร)
const int flamePin = 0;                                 // ให้ตัวแปร  flamePin  เชื่อมต่อกับขา A0 เพื่อรับค่า
int flameReading;                                       // ตัวแปรจัดเก็บค่าขาไฟที่รับค่าในการตรวจจับเปลวไป เพื่อแสดงผลการค่าออกมา
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
    myservo.attach(4,0,180);                            // กำหนดขาสัญญาณ(Pin4)ที่ Servo Motor ต่อกับ Arduino และกำหนดความกว้างในการหมุนที่ 0 องศาและ 180 องศา (pin,min,max)
    //----------------------- SevenSegment (แสดงค่า)
    sevenSegment.init();                                // จัดเก็บรับค่าใน()
    sevenSegment.set(7);                                // BRIGHT 0-7; //ระดับความสว่าง0-7; 
    //----------------------- Ultrasonic (แสดงค่า)  
    pinMode(trigPin, OUTPUT);                           // ให้แสดงผล ค่าระยะวัตถุเข้าใกล้
    pinMode(echoPin, INPUT);                            // ให้รับข้อมูล ค่่าระยะวัตถุเข้าใกล้
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
    Serial.begin(9600); //กำหนดอัตราความเร็วในการสื่อสารกับอนูโน่ที่ 9600                     
}
    //ใช้ขา Digital 2 ขา ขาแรกจะทำการ Trig สัญญาณเป็นลอจิคออกไปเป็นระยะเวลาสั้นมากๆแล้วทำการ จับเวลาคลื่นที่สะท้อนกลับมาที่ ขา Echo แล้วนำเวลาที่ได้มาคำนวนหาระยะทางจากสมการ
void loop(){
    //---------------------------------------- Servo (ขาไป)
    for(degree = 0; degree < 180; degree += 1)          // เริ่มต้นที่ 0 องศา เงื่อนไขคือหมุนไปไม่เกิน 180 องศา โดยให้เพิ่มที่ละ 1 องศา(ขาไป)
    {
        myservo.write(degree);                          // บอกให้Servoไปที่ตำแหน่งองศา () ตามที่ต้องการ ในเงื่อนไขของ for
        delay(40);                                      // หน่วงเวลาการหมุน 0.04 วินาที
        //------------------------------------ Ultrasonic (การทำงาน) 
        digitalWrite(trigPin, 0);                       //ตั้งค่า TrigPin ให้แสดงผลในสถานะปิดเป็นเวลา 2 ไมโครวินาที                    
        delayMicroseconds(2);                           //ความหน่วงเวลา(หน่วงไว้แปปเดียวเพื่อการทำงานต่อไป)

        digitalWrite(trigPin, 1);                       //ตั้งค่า TrigPin ให้แสดงผลในสถานะเปิดเป็นเวลา 10 ไมโครวินาที
        delayMicroseconds(10);
        digitalWrite(trigPin, 0);                       //ตั้งค่า TrigPin ให้แสดงผลในสถานะปิด 

        duration = pulseIn(echoPin , 1);                //รับค่าหรืออ่าน echoPin เพื่อส่งคืนเวลาเดินทางของคลื่นเสียงเป็นไมโครวินาที

        distance = duration*0.034/2;                    // คำนวนค่าระยะทาง

        safetyDistance = distance;                      //ให้ระยะที่ปลอดภัยรับค่าจากค่าระยะทางที่คำนวนมาแล้ว
        if (safetyDistance <= 20)                       //ถ้าระยะท่่ปลอดภัยเข้ามาในระยะไม่เกินหรือเท่ากับ 20 cm.
        { 
            digitalWrite(ledPinW, 1);
            digitalWrite(ledPinR, 1);
            digitalWrite(ledPinRR, 1);
        }
        else
        {
            digitalWrite(ledPinW, 0);
            digitalWrite(ledPinR, 0);
            digitalWrite(ledPinRR, 0);
        }
        //------------------------------------- Flame (การทำงาน)
        flameReading = analogRead(flamePin);            //กำหนดให้ flameReading อ่านค่าสัญญาณอนาล็อกที่ขา a0 จากตัวแปร flamePin 
        if (flameReading <= 500 )                       //กำหนด ถ้า flameReading อ่านค่าได้ไม่เกินหรือเท่ากับ 500 นาโนเมตร (ตรวจได้มากสุดถึง 1100 นาโนเมตร)
        {
            digitalWrite(buzzerPin, 1);  
            analogWrite(ledPinY, 255);
            analogWrite(ledPinWW, 255);
            analogWrite(ledPinYY, 255);
            //--------------------------------- SevenSegment (การทำงาน)
            sevenSegment.displayStr("S0S"); 
            delay(1000);                                //หน่วงเวลาในการแสดงผลของคำ 1 วินาที
            sevenSegment.displayStr("HELP"); 
            delay(1000);        
        }
        else 
        {
            digitalWrite(buzzerPin, 0);                 
            analogWrite(ledPinY, 0);
            analogWrite(ledPinWW, 0);
            analogWrite(ledPinYY, 0);
            sevenSegment.displayStr("");         
        }               
    }
    delay(100);                                        //หน่วงเวลาไว้ 0.1 วินาที เนื่องจากให้เวลาพักในการทำงานของการหมุนของมอเตอร์ช่วงขณะนึง ไม่งั้นมอเตอร์จะทำงานหนักมากเกินไป
    
    //----------------------------------------- Servo (ขากลับ)
    for(degree = 180; degree >= 1; degree -= 1)         // เริ่มต้นที่ 180 องศา เงื่อนไขคือหมุนกลับไปไม่เกิน 1 องศา โดยให้ลดที่ละ 1 องศา(ขากลับ)
    {
        myservo.write(degree);
        delay(40);
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
        }
        else
        {
            digitalWrite(ledPinW, 0);
            digitalWrite(ledPinR, 0);
            digitalWrite(ledPinRR, 0);
        }
        //------------------------------------- Flame (การทำงาน)
        flameReading = analogRead(flamePin); 
        if (flameReading <= 500 ) 
        {
            digitalWrite(buzzerPin, 1); 
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
            analogWrite(ledPinY, 0);
            analogWrite(ledPinWW, 0);
            analogWrite(ledPinYY, 0);
            sevenSegment.displayStr("");       
        }                                                   
    }
    delay(100);   
}

// Flame Sensor สามารถอ่านค่าในแบบ Analog เพื่อนำไปวิเคราะห์ได้ (แต่ก็สามารถอ่านค่าแบบ Digital ในบางรุ่นที่มีวงจร Comparators‎ - LM393 ที่สามารถปรับระดับ การตรวจจับได้ มาให้ในตัวโมดูล)
// Comparators วงจรเปรียบเทียบสัญญาณแรงดัน คือ วงจรที่ทำการเปรียบเทียบสัญญาณแรงดันระหว่างสัญญาณขาบวก และลบ ของ op amp เพื่อที่จะเปรียบเทียบว่าขาไหนมีค่าที่มากกว่ากัน
