#include<Servo.h>
int servoPin = 9; 
int servoPos;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  
  Serial.println("what angle fot the servo?");
  
  while(Serial.available() == 0){
  // Serial.println(Serial.available());
  }
  servoPos = Serial.parseInt();
  myServo.write(servoPos);
  // put your main code here, to run repeatedly:
  fflush(stdin);
  Serial.println(servoPos);
}
