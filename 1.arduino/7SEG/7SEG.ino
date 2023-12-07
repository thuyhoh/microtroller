int pina = 8;
int pinb = 9;
int pinc = 10;
int pind = 11;
int time = 1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(pina,OUTPUT);
  pinMode(pinb,OUTPUT);
  pinMode(pinc,OUTPUT);
  pinMode(pind,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pina,HIGH);
  digitalWrite(pinb,HIGH);
  digitalWrite(pinc,HIGH);
  digitalWrite(pind,HIGH);
  delay(time);
}
