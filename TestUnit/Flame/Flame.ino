//----------------------------------------- ของเก่า

// ประกาศตัวแปรกับขาPin 
/* 
const int flamePin = 3; //สัญญาณตรวจจับไฟ
const int buzzerPin = 9; //buzzer(ตัวปล่อยเสียง)เชื่อมกับขาPin9
const int ledPinW = 12; //แสงไฟสีขาว
const int ledPinY = 7; //แสดงไฟสีเหลือง
const int ledPinWW = 10; //แสงไฟสีขาว2
const int ledPinYY = 2; //แสดงไฟสีเหลือง2
int Flame = HIGH; //ประกาศว่าเปิดการทำงานของ เซนเซอร์เปลวไฟ (Interrupt)
*/

/* 
  void setup()
 {
     pinMode(flamePin, INPUT);
     pinMode(buzzerPin, OUTPUT);
     pinMode(ledPinW, OUTPUT);
     pinMode(ledPinY, OUTPUT);
     pinMode(ledPinWW, OUTPUT);
     pinMode(ledPinYY, OUTPUT);
     Serial.begin(9600);
 }*/
 
 /* 
  void loop()
 {
     Flame = digitalRead(flamePin); 
     if (flamePin == 0) //(Interrupt) แบบ FALLING จะเกิดอินเตอร์รัพท์เมื่อพอร์ตที่กำหนดไว้มีการเปลี่ยนสถานะจาก HIGH เป็น LOW
     {
         digitalWrite(buzzerPin, 1);
         digitalWrite(ledPinW, 1);
         digitalWrite(ledPinY, 1);
         digitalWrite(ledPinWW, 1);
         digitalWrite(ledPinYY, 1);        
     }
     else {
         digitalWrite(buzzerPin, 0);
         digitalWrite(ledPinW, 0);
         digitalWrite(ledPinY, 0);
         digitalWrite(ledPinWW, 0);
         digitalWrite(ledPinYY, 0);       
     }
 }*/
  
//(Interrupt) คือการขัดจังหวะการทำงานของโปรแกรมปกติที่กำลังทำอยู่ มาทำงานที่สำคัญเร่งด่วนทันที เมื่อทำเสร็จก็จะกลับไปทำงานเดิมที่ค้างไว้
// CHANGE จะเกิดอินเตอร์รัพท์เมื่อพอร์ตที่กำหนดไว้มีการเปลี่ยนสถานะ เช่น จากสถานะ HIGH เป็น LOW หรือจาก LOW เป็น HIGH

//--------------------------------------- ของใหม่

const int flamePin = 0; //เชื่อมต่อกับขา A0
const int buzzerPin = 9; //buzzer(ตัวปล่อยเสียง)เชื่อมกับขาPin9
const int ledPinW = 12; //แสงไฟสีขาว
const int ledPinY = 7; //แสงไฟสีเหลือง
const int ledPinWW = 10; //แสงไฟสีขาว2
const int ledPinYY = 2; //แสดงไฟสีเหลือง2
int flameReading; //อ่านค่าอนาล็อกจากตัวแบ่งตัวต้านทางแบบอนาล็อก


void setup() {
    pinMode(flamePin, INPUT); //รับค่า flamePin
    pinMode(buzzerPin, OUTPUT);
    pinMode(ledPinW, OUTPUT);
    pinMode(ledPinY, OUTPUT);
    pinMode(ledPinWW, OUTPUT);
    pinMode(ledPinYY, OUTPUT);  
    Serial.begin(9600);  //กำหนดอัตราความเร็วในการสื่อสาร   
}
 
void loop() {
  flameReading = analogRead(flamePin); //กำหนดให้ flameReading อ่านค่าสัญญาณอนาล็อกที่ขา a0 จากตัวแปร flamePin 
  if (flameReading <= 500 ) //กำหนด ถ้า flameReading อ่านค่าได้ไม่เกินหรือเท่ากับ 500 (ดูที่จอ Serial Monitor)
    {
        digitalWrite(buzzerPin, 1); //เปิดเสียงด้วยคำสั่ง digitalWrite (หยาบ 0 กับ 1)
        analogWrite(ledPinW, 255); //ปล่อยไฟ 255 เพราะใช้คำสั่ง analogWrite (ละเอียด)
        analogWrite(ledPinY, 255);
        analogWrite(ledPinWW, 255);
        analogWrite(ledPinYY, 255);        
    }
    else 
    {
        digitalWrite(buzzerPin, 0);
        analogWrite(ledPinW, 0);
        analogWrite(ledPinY, 0);
        analogWrite(ledPinWW, 0);
        analogWrite(ledPinYY, 0);       
    }

  Serial.print("Analog reading = "); //แสดงบรรทัด
  Serial.println(flameReading); //แสดงข้อมูลตัวแปร flameReading   
  delay(1000); //หน่วงเวลา 1 วินาที
}
