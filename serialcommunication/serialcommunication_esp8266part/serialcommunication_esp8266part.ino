#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(14,16);

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  mySerial.print("0");  
  delay(5000); 
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
