#include<Stepper.h>
int stepsPerRevolution = 2048;
int motspeed = 10;// speed 10v/phut
Stepper mystepper(stepsPerRevolution,8,10,9,11);
int dt = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mystepper.setSpeed(motspeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  // xuoi
  mystepper.step(stepsPerRevolution);
  delay(dt);
  // nguoc
  mystepper.step(-stepsPerRevolution);
  delay(dt);
}
