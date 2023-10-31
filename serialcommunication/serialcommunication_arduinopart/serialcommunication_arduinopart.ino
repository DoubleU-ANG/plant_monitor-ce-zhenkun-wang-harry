#include <SoftwareSerial.h>

SoftwareSerial mySerial(13, 12); // define softwareserial port


void setup() {
  // set the data rate for the hardwareSerial port
  Serial.begin(115200); 
  Serial.println("Hello,serial!");

  // set the data rate for the softwareSerial port
  mySerial.begin(115200);
  mySerial.println("AT");
}

void loop() { // run over and over
  // when arduino receive information from esp8266
  if (mySerial.available()) {
 Serial.write(mySerial.read());// then it will send that information to computer
  }
  // when arduino receive information from computer
  if (Serial.available()) {
    mySerial.write(Serial.read());// then it will send that information to esp8266
  }
}
