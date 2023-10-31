
#include <Arduino.h>
#include <Wire.h>


void setup()
{
    Serial.begin(115200); 
}

void loop()
{                    
                    Serial.print("delay1");//esp-->单片机
                    delay(500);
 
}