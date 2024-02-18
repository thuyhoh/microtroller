byte SpMaxL = 220;
byte SpMaxR = 220;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // dc A -> output
  pinMode(6, OUTPUT); // in1
  pinMode(7, OUTPUT); // in2
  // dc b -> output
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  // 5 cam bien
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Tien();
  // Lui();
  // Retrai();
  // Rephai();
  doline();
  //delay(1000);
  // Serial.println(reangThai5CamBien());
  // delay(1000);
}

void doline(){
  switch(trangThai5CamBien()){
    case 200:
      // tien(spMaxL,SpMaxR - 150);
      Lui(100,100);
      // Rephai();
      break;
    case 0:
      Tien(SpMaxL,SpMaxR);
      break;
    case 1:
      Tien(SpMaxL,SpMaxR - 20);
      break;
    case 2:
      Tien(SpMaxL,SpMaxR  - 40);
      break;
    case 3:
      Tien(SpMaxL, 0);
      break;
    case -1:
      Tien(SpMaxL - 20, SpMaxR);
      break;
    case -2:
      Tien(SpMaxL - 40, SpMaxR);
      break;
    case -3:
      Tien(0, SpMaxR);
      break;
    default:
      digitalWrite(6,0);
      digitalWrite(7,0);
      digitalWrite(8,0);
      digitalWrite(9,0);
      break;      
  }
} 

boolean IFSensor(byte PinNumb){
  return (!digitalRead(PinNumb));
}

int trangThai5CamBien(){
  /* 

  */
  int Sens1 = IFSensor(A0);
  int Sens2 = IFSensor(A1);
  int Sens3 = IFSensor(A2);
  int Sens4 = IFSensor(A3);
  int Sens5 = IFSensor(A4);
  switch(lechvach5mat()){
    case -3:
      return -3;
    case -2:
      return -2;
    case -1:
      return -1;
    case 0:
      if((abs(Sens1) + abs(Sens2) + abs(Sens3) + abs(Sens4) + abs(Sens5)) == 0){
        return 200;
      }else return 0;
    case 1:
      return 1;
    case 2:
      return 2;
    case 3:
      return 3;
  }
}

int lechvach5mat(){
  int Sens1 = IFSensor(A0);
  int Sens2 = IFSensor(A1);
  int Sens3 = IFSensor(A2);
  int Sens4 = IFSensor(A3);
  int Sens5 = IFSensor(A4);

  int lechvach = -2*Sens1 - Sens2 + Sens4 + 2*Sens5;
  switch(lechvach){
    case -3:
      return -2;
    case -2:
      return -3;
    case -1:
      return -1;
    case 0:
      return 0;
    case 1:
      return 1;
    case 2:
      return 3;
    case 3:
      return 2;
  }
}

void Tien(byte speedL, byte speedR){
  analogWrite(5,speedL);
  analogWrite(10,speedR);
  digitalWrite(6,1);
  digitalWrite(7,0);
  digitalWrite(8,1);
  digitalWrite(9,0);
}

void Lui(byte SpeedL, byte SpeedR){
  analogWrite(5,SpeedL);
  analogWrite(10,SpeedR);
  digitalWrite(6,0);
  digitalWrite(7,1);
  digitalWrite(8,0);
  digitalWrite(9,1);
}

void Rephai(){
  analogWrite(5,255);
  analogWrite(10,255);
  digitalWrite(6,1);
  digitalWrite(7,0);
  digitalWrite(8,0);
  digitalWrite(9,0);
}

void Retrai(){
  analogWrite(5,255);
  analogWrite(10,255);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,1);
  digitalWrite(9,0);
}