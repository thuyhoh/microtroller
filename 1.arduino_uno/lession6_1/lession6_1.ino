int redPin = 12;
int greenPin = 11;
int bluepPin = 10;
int waitTime = 500;

String mycolor;
String msg = "what is my color of LED?: ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while(Serial.available() == 0){

  }
  mycolor = Serial.readString();
  if(mycolor == "red") {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
    // delay(waitime);
  }
  else if(mycolor == "blue"){
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,HIGH);
    // delay(waitime);
  }
  else if(mycolor == "green"){
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
    digitalWrite(bluePin,LOW);
    // delay(waitime);
  }
}
