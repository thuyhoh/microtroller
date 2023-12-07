// photonresitor
int photonres_pin = A0;
int photonres_val;

// LED
int red_Pin = 9;
int green_Pin = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(photonres_pin,INPUT);
  pinMode(red_Pin,OUTPUT);
  pinMode(green_Pin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  photonres_val = analogRead(photonres_pin);
  Serial.println(photonres_val);
  if(photonres_val > 150){
      digitalWrite(red_Pin,HIGH);
      digitalWrite(green_Pin,LOW);
  }else{
    digitalWrite(red_Pin, LOW);
    digitalWrite(green_Pin,HIGH);
  }
}
