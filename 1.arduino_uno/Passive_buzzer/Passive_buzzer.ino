// pot 
int potVal;
int potPin = A0;

// passive buzzer
int BuzzerPin = 9;

// time
int buzzerTime_on = 1;
int buzzerTime_off;

void setup() {
  // put your setup code here, to run once:
  pinMode(potVal,INPUT);
  pinMode(BuzzerPin,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  buzzerTime_off = (9940./1023.)*potVal + 60;
  digitalWrite(BuzzerPin,HIGH);
  delayMicroseconds(buzzerTime_on);
  digitalWrite(BuzzerPin,LOW);
  delayMicroseconds(buzzerTime_off);

}
