int button_pin =  A0;
int button_val;

int led_pin = 9;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  button_val = digitalRead(button_pin);
  Serial.println(button_val);
  if(button_val == 0){
    digitalWrite(led_pin,LOW);
  }else{
    digitalWrite(led_pin,HIGH);
  }
  delay(20);
}
