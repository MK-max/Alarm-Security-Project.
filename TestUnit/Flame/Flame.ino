// ประกาศตัวแปรกับขาPin 
const int flamePin = 3; //สัญญาณตรวจจับไฟ
const int buzzerPin = 9; //buzzer(ตัวปล่อยเสียง)เชื่อมกับขาPin9
const int ledPinW = 12; //แสงไฟสีขาว
const int ledPinY = 7; //แสดงไฟสีเหลือง
const int ledPinWW = 10; //แสงไฟสีขาว2
const int ledPinYY = 2; //แสดงไฟสีเหลือง2
int Flame = HIGH; //ประกาศว่าเปิดการทำงานของ เซนเซอร์เปลวไฟ (Interrupt)

  void setup()
 {
     pinMode(flamePin, INPUT);
     pinMode(buzzerPin, OUTPUT);
     pinMode(ledPinW, OUTPUT);
     pinMode(ledPinY, OUTPUT);
     pinMode(ledPinWW, OUTPUT);
     pinMode(ledPinYY, OUTPUT);
     Serial.begin(9600);
 }
 
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
 }
  
//(Interrupt) คือการขัดจังหวะการทำงานของโปรแกรมปกติที่กำลังทำอยู่ มาทำงานที่สำคัญเร่งด่วนทันที เมื่อทำเสร็จก็จะกลับไปทำงานเดิมที่ค้างไว้
// CHANGE จะเกิดอินเตอร์รัพท์เมื่อพอร์ตที่กำหนดไว้มีการเปลี่ยนสถานะ เช่น จากสถานะ HIGH เป็น LOW หรือจาก LOW เป็น HIGH