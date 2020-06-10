#include "TM1637.h"

const int CLK = 17; //ขาA3
const int DIO = 16; //ขาA2

TM1637 sevenSegment(CLK, DIO); //Class , ชนิดobject , และส่วนที่รับพารามิเตอร์(คอนสตั๊กเกอร์)

void setup() {
  sevenSegment.init();
  sevenSegment.set(7); // BRIGHT 0-7; //ระดับความสว่าง0-7

  //sevenSegment.displayNum(10); 
  //delay(2000);

  //sevenSegment.displayNum(1234);
  //delay(2000);

  //sevenSegment.displayStr("0FF");
  //delay(2000);

  sevenSegment.displayStr("S0S");
  delay(2000);
  sevenSegment.displayStr("HELP");
  delay(2000); 
}

//int number = 0;

void loop() {
  //sevenSegment.displayNum(number++);
  //delay(100);
  sevenSegment.displayStr("S0S");
  delay(2000);
  sevenSegment.displayStr("HELP");
  delay(2000);
}
