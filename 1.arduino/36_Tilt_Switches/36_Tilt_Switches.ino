int TiltSwpin = 2;
int redpin = 8;
int greenpin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(redpin, OUTPUT);
  pinMode(greenpin,OUTPUT);

  pinMode(TiltSwpin, INPUT);
  digitalWrite(TiltSwpin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(TiltSwpin) == 0){
    digitalWrite(greenpin, HIGH);
    digitalWrite(redpin, LOW);
  }else{
    {
    digitalWrite(greenpin, LOW);
    digitalWrite(redpin, HIGH);
  } 
  }  
}
