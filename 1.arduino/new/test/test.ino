int photonres_pin = A0;
int photonres_val;

int buzzer_pin = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(photonres_pin,INPUT);
  pinMode(buzzer_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  photonres_val = analogRead(photonres_pin);
  Serial.println(photonres_val);
  if(photonres_val < 100){
    digitalWrite(buzzer_pin,HIGH);
  }
  else{
    digitalWrite(buzzer_pin,LOW);
  }
}
