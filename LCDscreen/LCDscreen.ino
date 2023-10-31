
#include "U8glib.h"//U8g2库
void draw(void);
//四针iic的引脚定义
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);//SCL-A5；SDA-A4
void setup() {
 
 
}
void draw(){
 u8g.setFont(u8g_font_fub14);//设置字体和字号
 u8g.setPrintPos(18,32); //显示的位置
 u8g.print("hello world");//显示时间字样
}
void loop() {
   u8g.firstPage();  
  do {
     draw();
  } while( u8g.nextPage() );
 
}
