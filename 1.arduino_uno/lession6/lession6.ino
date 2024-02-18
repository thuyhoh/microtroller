String myname;
String msg = "what is your name? ";
String msg2 = "Hello ";
String msg3 = ", welcome to arduino";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg);
while(Serial.available() == 0){

}
myname = Serial.readString();
Serial.print(msg2);
Serial.print(myname);
Serial.print(msg3);
Serial.println();
}
