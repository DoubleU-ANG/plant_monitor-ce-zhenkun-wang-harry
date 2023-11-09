#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(14,16); define software serial port, define pin14 as RX, define pin16 as TX

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  mySerial.print("1");  
  delay(5000); 
  mySerial.print("2");
  delay(5000); 
  mySerial.print("3");
  delay(5000); 
  mySerial.print("4");
  delay(5000); 
  mySerial.print("5");
  delay(5000); 
  mySerial.print("6");  
  delay(1500);

}
