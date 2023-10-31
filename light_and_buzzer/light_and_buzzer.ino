#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.

// this constant won't change. It's the pin number of the sensor's output:
const int trigPin = 9;        //assign pin 9 to trigger
const int echoPin = 10;       //assign pin 10 to echo
const int LED = 13;           //keep the LED on pin 13
const int BUZZER = 8;         //keep the buzzer on pin 8
const boolean debug = true;  //variable to show hide debug info

// establish variables for duration of the ping, and the distance result in centimeters and one for LED blink rate:
long duration, cm;
int blinkrate = 0;

// calculate the distance
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void setup() {
  // initialize serial communication:
  if(debug){
    Serial.begin(9600);
    Serial.println("Starting blinker");
  }
  pinMode(LED, OUTPUT);//Sets the LED in output mode
  pinMode(BUZZER, OUTPUT);//Sets the BUZZER in output mode
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input     
}

void loop() {
  // put your main code here, to run repeatedly:
  //make the ultrasonic work
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
//getting the time by timing the high volts
duration = pulseIn(echoPin, HIGH);
cm = microsecondsToCentimeters(duration);
//changing blinking rate based on distance
if(cm < 100){

  if(cm < 30){
    blinkrate = map(cm, 1, 30, 10, 300);
  }
  else if(cm < 90){
    blinkrate = map(cm, 30, 90, 300, 1000);
  }
  else{
    blinkrate = 0;
  }

  if(debug){
    //print the distance on computer by serial communication
    Serial.print(" cm: ");
    Serial.print(cm);
  }
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(BUZZER, HIGH);// turn the BUZZER on
  delay(blinkrate);                       // delay based on the distance
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(BUZZER, LOW);// turn the BUZZER off
  delay(blinkrate);

}

delay(20);
}
