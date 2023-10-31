#include <Arduino.h>
#include <Wire.h>


void setup()
{
    Serial.begin(115200); //set up serial and data rate
}

void loop()
{                    
        Serial.print("delay1");//send text to arduino
        delay(500);
 
}
