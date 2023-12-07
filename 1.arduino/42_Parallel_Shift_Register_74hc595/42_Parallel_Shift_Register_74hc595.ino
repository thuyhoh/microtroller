int clockpin ;
int datapin;
int latchpin;

int LEDs = 0xff; // 0b11111111
void setup() {
  // put your setup code here, to run once:
  pinMode(clockpin,OUTPUT);
  pinMode(datapin,OUTPUT);
  pinMode(latchpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchpin,LOW); // ha chot
  shiftOut(datapin,clockpin,LSBFIRST,LEDs);
  digitalWrite(latchpin,HIGH);
}
