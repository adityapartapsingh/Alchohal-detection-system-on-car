
// Adafruit Motor Shield V2 Library - Version: 1.1.1
#include<AFMotor.h>
#include <Wire.h>


//  I/O pins
#define MQ3 A2
#define Buzzer A1
#define LED 
//Threshold value of MQ3 reading above which it should trigger/
#define Thres_Val 460
// global int to store the analog reading from MQ3 (0 to 1023)
int value;

// motor setup
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);


void setup() {
  Serial.begin(9600) ;
  // declaring the input and output pins
  pinMode(MQ3, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  // set speed of motor
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  Stop();      //  motor stop when code start
}


void loop() {
  // reads the analog value from MQ3
  value = analogRead(MQ3);
  Serial.println(value);

  if ( value > Thres_Val )   //if alcohol is detected
  {
    digitalWrite ( LED, HIGH );     // turns the LED on
    digitalWrite(Buzzer, HIGH); // turn the buzzer on
    Stop();
  }
  else {
    digitalWrite(LED, LOW);       //  turns the LED off
    digitalWrite(Buzzer, LOW);  //  turns off buzzer
    Forward();
  }
  delay (500);            //  a 500ms delay before reading is taken again
}


void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void Forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
