#include <SoftwareSerial.h>

SoftwareSerial mySerial(13, 12); // RX, TX，接esp的Tx,Rx

#include "U8glib.h"//U8g2库
void draw(void);
//四针iic的引脚定义
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);//SCL-A5；SDA-A4

void setup() {
  Serial.begin(115200); 
  Serial.println("Hello,serial!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(115200);
  mySerial.println("AT");
  u8g.firstPage(); 
}

void loop() { // run over and over
  if (mySerial.available()) {
 //   char a =mySerial.read();
 //   Serial.write(a);
 Serial.write(mySerial.read());

  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
