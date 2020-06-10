//defines pins number(กำหนดหมายเลขพิน)
const int trigPin = 6; //Ultrasonic Distance
const int echoPin = 5; //Ultrasonic Distance
const int busser = 9;
const int ledPinW = 13;
const int ledPinR = 12;
const int ledPinWW = 10;
const int ledPinRR = 11;

//defines veriables(กำหนดตัวแปร)
int duration; //ระยะเวลา
int distance; //ระยะทาง
int safetyDistance; //ระยะที่ปลอดภัย

 void setup(){
    pinMode(trigPin, OUTPUT); // Sets the TrigPin as an Output(ให้แสดงผลค่าระยะวัตถุเข้าใกล้)
    pinMode(echoPin, INPUT); // Sets the echoPin as an Intput(ให้รับข้อมูลค่่าระยะวัตถุเข้าใกล้)
    pinMode(busser,OUTPUT); // แสดงเสียง
    pinMode(ledPinW,OUTPUT); // แสดงไฟ
    pinMode(ledPinR,OUTPUT);
    pinMode(ledPinWW,OUTPUT);
    pinMode(ledPinRR,OUTPUT);
    Serial.begin(9600); // Starts the serial communication
}

 void loop(){
    //Clears the trigPin (ให้แสดงค่า Ultrasonic Distanceที่ได้เชื่อมขาไฟพิน 9 )
    //Sets the trigPin on the 0 state for 2 micro seconds (ตั้งค่า TrigPin ในสถานะปิดเป็นเวลา 2 ไมโครวินาที)
    digitalWrite(trigPin, 0); 
    delayMicroseconds(2); //ความหน่วงเวลา

    //Sets the trigPin on the 1 state for 10 micro seconds (ตั้งค่า TrigPin ในสถานะเปิดเป็นเวลา 10 ไมโครวินาที)
    digitalWrite(trigPin, 1);
    delayMicroseconds(10);
    digitalWrite(trigPin, 0); //แล้วก็ปิดไฟ

    //Reads the echoPin, returns the sound wave travel time in microseconds (รับค่าหรืออ่าน echoPin ส่งคืนเวลาเดินทางของคลื่นเสียงเป็นไมโครวินาที)
    duration = pulseIn(echoPin , 1);

    // คำนวนค่าระยะทาง
    distance = duration*0.034/2;

    safetyDistance = distance; //ให้ระยะที่ปลอดภัยรับค่าจากค่าระยะทาง
    if (safetyDistance <= 20){
        digitalWrite(busser, 1);
        digitalWrite(ledPinW, 1);
        digitalWrite(ledPinR, 1);
        digitalWrite(ledPinWW, 1);
        digitalWrite(ledPinRR, 1);
    }
    else{
        digitalWrite(busser, 0);
        digitalWrite(ledPinW, 0);
        digitalWrite(ledPinR, 0);
        digitalWrite(ledPinWW, 0);
        digitalWrite(ledPinRR, 0);
    } 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);   
}
