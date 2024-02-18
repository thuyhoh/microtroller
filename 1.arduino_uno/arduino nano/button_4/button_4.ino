int buttonPin1 = 12;
int button_val1;
int buttonPin2 = 11;
int button_val2;
int LEDpin = 9;
int LEDbright = 0;
int buzzerPin = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(LEDpin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  button_val1 = digitalRead(buttonPin1);
  button_val2 = digitalRead(buttonPin2);
  Serial.print("button 1 = ");
  Serial.println(button_val1);
  Serial.print("button 2 = ");
  Serial.println(button_val2);

  if(button_val1 == 1){
    LEDbright = LEDbright + 5;
  }
  if (button_val2 == 1){
    LEDbright = LEDbright - 5;
  }

  if(LEDbright >= 255){
    LEDbright = 255;
    // digitalWrite(buzzerPin,HIGH);
  }
  if(LEDbright <= 0){
    LEDbright = 0;
  }
  Serial.print("value of LEDbright = ");
  Serial.println(LEDbright);
  if(LEDbright > 150){
    digitalWrite(buzzerPin,HIGH);
  }else{
    digitalWrite(buzzerPin,LOW);
  }
  analogWrite(LEDpin,LEDbright);
  delay(250);
}
