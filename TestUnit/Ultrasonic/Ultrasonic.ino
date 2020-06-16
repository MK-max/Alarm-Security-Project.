//defines pins number(กำหนดขาหมายเลขPin เพื่อสั่งการทำงาน)
const int trigPin = 6; //Ultrasonic Distance
const int echoPin = 5; //Ultrasonic Distance
const int ledPinW = 12; //ไฟสีขาวดวงที่1
const int ledPinR = 13; //ไปสีแดงดวงที่1
const int ledPinWW = 10; //ไฟสีขาวดวงที่2
const int ledPinRR = 11; //ไปสีแดงดวงที่2

//defines veriables(กำหนด/ประกาศ ตัวแปร)
int duration; //ระยะเวลา
int distance; //ระยะทาง
int safetyDistance; //ระยะที่ปลอดภัย

 void setup(){
        pinMode(trigPin, OUTPUT); //ให้แสดงผล ค่าระยะวัตถุเข้าใกล้
        pinMode(echoPin, INPUT); //ให้รับข้อมูล ค่่าระยะวัตถุเข้าใกล้
        pinMode(ledPinW,OUTPUT); //แสดงไฟสีขาว1
        pinMode(ledPinR,OUTPUT); //แสดงไฟสีแดง1
        pinMode(ledPinWW,OUTPUT); //แสดงไฟสีขาว2
        pinMode(ledPinRR,OUTPUT); //แสดงไฟสีขาว2
        Serial.begin(9600); //กำหนดความเร็วในการติดต่อกับอนูโน่ 9600
    }

 void loop(){
    //Clears the trigPin 
        digitalWrite(trigPin, 0); //ตั้งค่า TrigPin ในสถานะปิดเป็นเวลา 2 ไมโครวินาที
        delayMicroseconds(2); //ความหน่วงเวลา(หน่วงไว้แปปเดียวเพื่อการทำงานต่อไป)

        digitalWrite(trigPin, 1); //ตั้งค่า TrigPin ในสถานะเปิดเป็นเวลา 10 ไมโครวินาที
        delayMicroseconds(10);
        digitalWrite(trigPin, 0); //ตั้งค่า TrigPin ในสถานะปิด 

        duration = pulseIn(echoPin , 1); //รับค่าหรืออ่าน echoPin เพื่อส่งคืนเวลาเดินทางของคลื่นเสียงเป็นไมโครวินาที

        // คำนวนค่าระยะทาง
        distance = duration*0.034/2; //(ระยะที่วัตุเข้ามา จะแจ้งเตือนประมาณ20ซม.)

        safetyDistance = distance; //ให้ระยะที่ปลอดภัยรับค่าจากค่าระยะทาง
        if (safetyDistance <= 20){ //ถ้าระยะท่่ปลอดภัยเข้ามาในระยะไม่เกินหรือเท่ากับ 20 cm.
            digitalWrite(ledPinW, 1);
            digitalWrite(ledPinR, 1);
            digitalWrite(ledPinWW, 1);
            digitalWrite(ledPinRR, 1);
        }
        else{
            digitalWrite(ledPinW, 0);
            digitalWrite(ledPinR, 0);
            digitalWrite(ledPinWW, 0);
            digitalWrite(ledPinRR, 0);
        } 
        // Prints the distance on the Serial Monitor
        Serial.print("Distance: "); //แสดงบรรทัด
        Serial.println(distance); //แสดงข้อมูลตัวแปร  
    }

// ความเร็วเสียงในอากาศประมาณ 340 เมตร/วินาที
// เวลาที่ใช้คือ ระยะทางไปกลับ ดังนั้นระยะทางคือ ครึ่งหนึ่งของที่วัดได้
// ระยะทางที่วัดได้จะสัมพันธ์กับระยะเวลาที่คลื่นอัลตร้าโซนิกเคลื่อนที่ไปกระทบวัตถุและสะท้อนกลับมายังตัวรับ
