int button_pin =  A0;
int button_val;

int led_pin = 9;

int count = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  button_val = digitalRead(button_pin);
  Serial.print(button_val);
  if(button_val == 0){
    count = count + 1;
  }
  Serial.println(count);
  if(count % 2 == 1){
    digitalWrite(led_pin,HIGH);
  }else{
    digitalWrite(led_pin,LOW);
  }
  if(count == 99) count = 0;
  delay(200);
}
