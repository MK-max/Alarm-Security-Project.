#include "TM1637.h" //เรียนไลบรารี่เข้ามาใช้ในโปรแกรม

const int CLK = 17; //ขาA3
const int DIO = 16; //ขาA2

TM1637 sevenSegment(CLK, DIO); //Class , ชนิดobject , และส่วนที่รับพารามิเตอร์(คอนสตั๊กเกอร์)

void setup() {
  sevenSegment.init(); 
  sevenSegment.set(7); // BRIGHT 0-7; //ระดับความสว่าง0-7;  
}

void loop() {
  sevenSegment.displayStr("S0S"); //จอแสดงผล SOS
  delay(2000); //หน่วงเวลา 2 วินาที
  sevenSegment.displayStr("HELP"); //จอแสดงผล HELP
  delay(2000); //หน่วงเวลา 2 วินาที
}
