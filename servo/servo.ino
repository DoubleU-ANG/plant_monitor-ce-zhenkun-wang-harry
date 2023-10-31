#include <Servo.h>  
Servo myservo;        // create a servo object 
int pos = 0;          // define pos for storing the degree that servo rotates

void servo_move()
{
     for(pos = 0; pos < 180; pos += 1){         
      myservo.write(pos);           // make servo rotate from 0 degree to 180 degree  
      delay(1);                    
   }
    for(pos = 180; pos>=1; pos-=1) {                                  
       myservo.write(pos);        // make servo rotate from 180 degree to 0 degree    
       delay(11);                 
    } 
}

void setup() { 
    myservo.attach(9);  // connect the servo with pin 9
} 

void loop() { 
  servo_move();
  delay(1000);
}



