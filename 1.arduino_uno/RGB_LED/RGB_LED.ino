// input
int Rpin = A0;
int Gpin = A1;
int Bpin = A2;

//pot value
int RP;
int GP;
int BP;


//value of color
int R;
int G;
int B;

// output
int redpin = 8;
int greenpin = 9;
int bluepin = 10;

void setup() {
  // put your setup code here, to run once:
  // input
  pinMode(Rpin,INPUT);
  pinMode(Gpin,INPUT);
  pinMode(Bpin,INPUT);

  // output
  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(bluepin,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  RP = analogRead(Rpin);
  GP = analogRead(Gpin);
  BP = analogRead(Bpin);
  

  R = (RP*255)*1./1023.;
  G = (GP*255)*1./1023.;
  B = (BP*255)*1./1023.;

  Serial.print("R: ");
  Serial.print(R);
  Serial.print("B: ");
  Serial.print(B);
  Serial.print("G: ");
  Serial.println(G);

  analogWrite(redpin,R);
  analogWrite(greenpin,G);
  analogWrite(bluepin,B);
  

}
