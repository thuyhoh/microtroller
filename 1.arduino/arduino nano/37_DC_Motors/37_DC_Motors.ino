int M1 = 11; // chan thuan
int M2 = 10; // chan nghic
int speedPin = 9;
int speed =  255;
void setup() {
  // put your setup code here, to run once:
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(speedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // xoay theo chieu thuan 
  analogWrite(speedPin, speed);
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  delay(5000);
  
  // xoay theo chieu nghich
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  delay(5000);

}
