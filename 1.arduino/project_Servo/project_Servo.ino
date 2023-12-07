#include<Servo.h>
Servo myServo;
int ServoPos;
int ServoPin = 9;
//
int lightVal;
int photoresPin = A0;
//
int dt = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(photoresPin,INPUT);
  myServo.attach(ServoPin);
  Serial.begin(9600);
  pinMode(ServoPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(photoresPin);
  Serial.println(lightVal);
  ServoPos = (-16./63.)*lightVal +16.*780./63.;
  myServo.write(ServoPos);
  delay(dt);
}
