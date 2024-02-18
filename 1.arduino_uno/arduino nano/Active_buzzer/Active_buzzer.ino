// buzzers
int buzzPin = 8;
int buzzTime = 1000;

// pot
int potPin = A0;
int potVal;


void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin,OUTPUT);
  pinMode(potPin,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  if(potVal > 800){
    digitalWrite(buzzPin,HIGH);
    delay(buzzTime);
    digitalWrite(buzzPin,LOW);
    delay(buzzTime);
  }
}
