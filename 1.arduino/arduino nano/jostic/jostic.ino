int Xpin = A0;
int Xval;

int Ypin = A1;
int Yval;

int SWpin =  2;
int SWval;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Xval = analogRead(Xval);
  Yval = analogRead(Yval);
  SWval = digitalRead(SWval);
  Serial.print("X :");
  Serial.println(Xval);
  Serial.print("Y :");
  Serial.println(Yval);
  Serial.print("SWval ");
  Serial.println(SWval);
}
