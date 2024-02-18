int pin = 8;
int longW = 2000;
int dit = 100;
int dak = 500;


void setup() {
  // put your setup code here, to run once:
  pinMode(pin,OUTPUT);
}

// void blink(int n){
//   int i ;
//   for(i = 0; i<= n; i++){

//   }
// }

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin,HIGH);
  delay(dit);
  digitalWrite(pin,LOW);
  delay(dit);

  digitalWrite(pin,HIGH);
  delay(dit);
  digitalWrite(pin,LOW);
  delay(dit);

  digitalWrite(pin,HIGH);
  delay(dit);
  digitalWrite(pin,LOW);
  delay(dit);

  digitalWrite(pin,HIGH);
  delay(dak);
  digitalWrite(pin,LOW);
  delay(dak);

  digitalWrite(pin,HIGH);
  delay(dak);
  digitalWrite(pin,LOW);
  delay(dak);

  digitalWrite(pin,HIGH);
  delay(dak);
  digitalWrite(pin,LOW);
  delay(dak);

    digitalWrite(pin,HIGH);
  delay(dit);
  digitalWrite(pin,LOW);
  delay(dit);

  digitalWrite(pin,HIGH);
  delay(dit);
  digitalWrite(pin,LOW);
  delay(dit);

  digitalWrite(pin,HIGH);
  delay(dit);
  digitalWrite(pin,LOW);
  delay(dit);


  delay(20000);
}
