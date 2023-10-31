
#include "U8glib.h"
void draw(void);
//define the pin for IIC communication of OLED
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);//SCL-A5；SDA-A4

void setup() {
}

void loop() {
   u8g.firstPage();  
  do {
     draw();
  } while( u8g.nextPage() );
 
}
void draw(){
 u8g.setFont(u8g_font_fub14);//set format
 u8g.setPrintPos(18,32); //set position
 u8g.print("plant monitor");//show "plant monitor" on the screen
}
