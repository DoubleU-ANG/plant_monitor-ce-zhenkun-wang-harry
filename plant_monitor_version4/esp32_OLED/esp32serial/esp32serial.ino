#include <Arduino.h>
#include <U8g2lib.h>
#include <SoftwareSerial.h>
#include<Servo.h>                  /
Servo myservo;                     //define a servo object
int _servo = 21;                   //use pin21 to control the servo
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/22, /* data=*/23); // ESP32 Thing, HW I2C with pin remapping
SoftwareSerial mySerial1(5, 18);

int temp=0;
unsigned int i=0;
int LED=19;
void setup(void)
{
  pinMode(LED,OUTPUT);
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
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(1000);
     for(int i=0;i<180;i++)             //control the servo to move
  {
    myservo.write(i);                
    delay(2);
  }
  
  for(int i=180;i<=0;i--)            
  {
    myservo.write(i);                
    delay(10);
  }
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
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(1000);
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
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(1000); 
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
