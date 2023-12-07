// using analogWrite(pin,val_analog);// 0 < val_analog < 255 -> 0->5v;

int pin = 9;
int val_analog = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pin, val_analog);// 
}
