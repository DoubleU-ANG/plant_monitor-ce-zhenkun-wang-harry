#include <Arduino.h>
#include <U8g2lib.h>
#include <SoftwareSerial.h>
 
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/22, /* data=*/23); // ESP32 Thing, HW I2C with pin remapping
SoftwareSerial mySerial1(5, 18);
SoftwareSerial mySerial2(19, 21);
int temp=0;
unsigned int i=0;
void setup(void)
{
  Serial.begin(9600);
  mySerial1.begin(9600);
  u8g2.begin();
  u8g2.enableUTF8Print(); // enable UTF8 support for the Arduino print() function
}
void loop(void)
{  
 i = mySerial1.available(); 
  if(i != 0){
    while(i--){
      temp = mySerial1.read();
      Serial.print(temp);
    }
    }     
  u8g2.setFont(u8g2_font_unifont_t_chinese2); // use chinese2
  u8g2.firstPage();
  do
  {
     
    switch (temp)
    {

    case 49:
    u8g2.setCursor(0, 20);
    u8g2.print("Help!"); 
    u8g2.setCursor(0, 40);
    u8g2.print("I need water!"); 
    u8g2.drawGlyph(0, 60, 0x2615); 
    delay(10);
        break;

    case 50:
    u8g2.setCursor(0, 20);
    u8g2.print("Help!"); 
    u8g2.setCursor(0, 40);
    u8g2.print("Too much water!"); 
        break;
    case 51:
    u8g2.setCursor(0, 20);
    u8g2.print("Help!");
    u8g2.setCursor(0, 40);
    u8g2.print("I feel so cold!"); 
        break;

    case 52:
    u8g2.setCursor(0, 20);
    u8g2.print("Help!");
    u8g2.setCursor(0, 40);
    u8g2.print("I feel so hot!"); 
        break;

    case 53:
    u8g2.setCursor(0, 20);
    u8g2.print("Help!");
    u8g2.setCursor(0, 40);
    u8g2.print("I feel so wet!"); 
        break;

    case 54:
    u8g2.setCursor(0, 20);
    u8g2.print("Help!");
    u8g2.setCursor(0, 40);
    u8g2.print("I feel so dry!"); 
        break;

    default:
    u8g2.setCursor(0, 15);
    u8g2.print("Hello!");
    u8g2.setCursor(0, 30);
    u8g2.print("I'm Harry jr!"); 
    u8g2.setCursor(0, 45);
    u8g2.print("So happy to be");  
    u8g2.setCursor(0, 60); 
    u8g2.print("in the CElab!");
        break;
    }
    
  } while (u8g2.nextPage()); 
  
  delay(1000);

}
