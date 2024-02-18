int latchpin;
int datapin;
int clockpin;

int val = 0b0010001

void setup() {
  // put your setup code here, to run once:
  pinMode(latchpin,OUTPUT);
  pinMode(latchpin,OUTPUT);
  pinMode(latchpin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchpin,LOW);
  shiftOut(datapin,clockpin,LBSFIST,val);
  digitalWrite(latchpin,HIGH);
  delay(100);
  if(val > 128){
    val = val<<1 | 0b1;
  }else{
    val = val<<1 | 0b0;
  }
}
