// motor
#define Ma1 7
#define Ma2 6

#define Mb1 8
#define Mb2 9

// line sensor

#define line1 A0 //left
#define line2 A1 //left
#define line3 A2
#define line4 A3 // right
#define line5 A5 // right

// dieu khien speed
#define ENa 3 // moto phai
#define ENb 5 // moto trai
// speed 
int8_t Max = 255;
int8_t Min = 0;


void Tien(){
  // analogWrite(ENa,speed);
  // analogWrite(ENb,speed);
  digitalWrite(Ma1,HIGH);
  digitalWrite(Ma2,LOW);

  digitalWrite(Mb1,HIGH);
  digitalWrite(Mb2,LOW);
} 
void Lui(int8_t speed){
  analogWrite(ENa,speed);
  analogWrite(ENb,speed);

  digitalWrite(Ma1,LOW);
  digitalWrite(Ma2,HIGH);

  digitalWrite(Mb1,LOW);
  digitalWrite(Mb2,HIGH);
}

void dung(){
  digitalWrite(Ma1,LOW);
  digitalWrite(Ma2,LOW);

  digitalWrite(Mb1,HIGH);
  digitalWrite(Mb2,HIGH);
}


void ReTrai(){
  // analogWrite(ENa,speedr);
  // analogWrite(ENb,speedl);

  digitalWrite(Ma1,LOW);
  digitalWrite(Ma2,LOW);

  digitalWrite(Mb1,HIGH);
  digitalWrite(Mb2,LOW);
}

void RePhai(){
  // analogWrite(ENa,speedr);
  // analogWrite(ENb,speedl);

  digitalWrite(Ma1,HIGH);
  digitalWrite(Ma2,LOW);

  digitalWrite(Mb1,LOW);
  digitalWrite(Mb2,HIGH);
}

int line(int line_i){
  return (!digitalRead(line_i));
}

int doline(){
  int8_t l1 = line(line1);
  int8_t l2 = line(line2);
  int8_t l3 = line(line3);
  int8_t l4 = line(line4);
  int8_t l5 = line(line5);

  int8_t left = l1 + l2;
  int8_t right = l4 + l5;
  // 0  -> tien
  // 2  -> re trai
  // -2 -> re phai
  // 1 -> chinh  trai
  // -1 ->
  if(l3 == 1){
    if(left < 2 && right < 2 ){
      return 0; // tien 
    }else if(left == 2 && right < 2){
      return 2; // re trai
    }else if(left < 2 && right == 2){
      return -2; // re phai+
    }else if(left == 2 && right == 2){
      return 10;
    } 
  }else{
    // if(left == 0 && right == 0){
    //   return 0;
    // }else 
    if(left >= 1 && right == 0){
      return 1; // chinh trai 100
    }else if(left == 0 && right >= 1){
      return -1;// chinh phai 100
    }
  }

}


// void chedo(){
//   switch(doline()){
//     case 0:
//       Tien(255);
//       break;
//     case 2:
//       digitalWrite(ENa,LOW);
//       digitalWrite(ENb,LOW);
//       delay(100);
//       ReTrai(255,20);
//       break;
//     case -2:
//       digitalWrite(ENa,LOW);
//       digitalWrite(ENb,LOW);
//       delay(100);
//       RePhai(20,255);
//       break;
//     case 10: // truong hop luong lu
//       digitalWrite(ENa,LOW);
//       digitalWrite(ENb,LOW);
//       delay(100);
//       break;
//     case 1:
//       digitalWrite(ENa,LOW);
//       digitalWrite(ENb,LOW);
//       ReTrai(100,255);
//       delay(100);
//     case -1:
//       digitalWrite(ENa,LOW);
//       digitalWrite(ENb,LOW);
//       RePhai(255,100);
//       delay(100);

//   }
// }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // set motor
  pinMode(Ma1,OUTPUT);
  pinMode(Ma2,OUTPUT);
  pinMode(Mb1,OUTPUT);
  pinMode(Mb2,OUTPUT);
  pinMode(ENa, OUTPUT);
  pinMode(ENb, OUTPUT);
  // set line sensor
  pinMode(line1, INPUT);
  pinMode(line2, INPUT);
  pinMode(line3, INPUT);
  pinMode(line4, INPUT);
  pinMode(line5, INPUT);

}

void loop() {
  int8_t l1 = line(line1);
  int8_t l2 = line(line2);
  int8_t l3 = line(line3);
  int8_t l4 = line(line4);
  int8_t l5 = line(line5);

  int8_t left = l1 + l2;
  int8_t right = l4 + l5;

  Serial.print("cen ");
  Serial.println(l3);

  Serial.print("left ");
  Serial.println(left);

  Serial.print("right ");
  Serial.println(right);

  Serial.print("l4");
  Serial.println(l4);
  Serial.print("l5");
  Serial.println(l5);
  // delay(500);


  Tien();
  // Tien();
    if(l3 == 1){
      if(left < 2 && right < 2 ){
        dung();
        delay(1000);
        Tien(); // tien 
      }else if(left == 2 && right < 2){
        dung();
        delay(1000);
        ReTrai(); // re trai
      }else if(left < 2 && right == 2){
        dung();
        delay(1000);
        RePhai(); // re phai+
      }
    }
    else{
      // if(left == 0 && right == 0){
      //   return 0;
      // }else 
      if(left >= 1 && right == 0){
        dung();
        delay(1000);
        ReTrai(); // chinh trai 100
      }else if(left == 0 && right >= 1){
        dung();
        delay(1000);
        RePhai();// chinh phai 100
      }
    }

  // Serial.print("line 2 ");
  // Serial.println(left1);
  // if(cent == 1){
  //   Tien();
  // }else{
  //   dung();
  // }
  // // if()
  


  
}
