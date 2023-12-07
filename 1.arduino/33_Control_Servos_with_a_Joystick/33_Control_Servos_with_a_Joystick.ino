#include<Servo.h>

int Xpin = A0;
int Xval;

int Ypin = A1;
int Yval;

int SWpin =  2;
int SWval;

// Servo
int Servopin1 = 9;
int S1_val;

int Servopin2 = 10;
int S2_val;

// buzzer
int buzzerpin = 7;

Servo Servo1;
Servo Servo2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  pinMode(Servopin1, OUTPUT);
  pinMode(Servopin2, OUTPUT);
  pinMode(buzzerpin,OUTPUT);
  Servo1.attach(Servopin1);
  Servo2.attach(Servopin2);
}

void loop() {
  // put your main code here, to run repeatedly:
  Xval = analogRead(Xval);
  Yval = analogRead(Yval);
  SWval = digitalRead(SWval);
  S1_val = (180./1023.)* Xval;
  S2_val = (180./1023.)* Yval;

  Servo1.write(s1_val);
  Servo2.write(s2_val);

  if(Swval == 0){
    digitalWrite(buzzerpin,HIGH);
  }else{
    digitalWrite(butzzerpin,LOW);
  }

  Serial.print("X : ");
  Serial.print(Xval);
  Serial.print(" Y : ");
  Serial.println(Yval);
  Serial.print(" SWval : ");
  Serial.println(SWval);
}
