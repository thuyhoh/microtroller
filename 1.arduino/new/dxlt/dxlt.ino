#define inA1 7 //Định nghĩa chân in1 của động cơ A
#define inA2 6 //Định nghĩa chân in2 của động cơ A
#define inB1 8 //Định nghĩa chân in1 của động cơ B
#define inB2 9 //Định nghĩa chân in2 của động cơ B
#define linesens1 A0 //Định nghĩa chân cảm biến line 1
#define linesens2 A1 //Định nghĩa chân cảm biến line 2
#define linesens3 A2 //Định nghĩa chân cảm biến line 3
#define linesens4 A3 //Định nghĩa chân cảm biến line 4
#define linesens5 A4
void setup() {
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(inA1, OUTPUT);//Set chân in1 của dc A là output
  pinMode(inA2, OUTPUT);//Set chân in2 của dc A là output
  pinMode(inB1, OUTPUT);//Set chân in1 của dc B là output
  pinMode(inB2, OUTPUT);//Set chân in2 của dc B là output
  pinMode(linesens1, INPUT);//Set chân cảm biến 1 là input
  pinMode(linesens2, INPUT);//Set chân cảm biến 2 là input
  pinMode(linesens3, INPUT);//Set chân cảm biến 3 là input
  pinMode(linesens4, INPUT);//Set chân cảm biến 4 là input
  pinMode(linesens5, INPUT);

}

void loop() {
  Serial.print(linesens2);
}

void darkLineFollower (byte inR1, byte inR2, byte inL1, byte inL2, byte sen1, byte sen2, byte sen3, byte sen4)
{
  //Hàm điều khiển robot bám line màu tối
  //inR1, inR2 và inL1, inL2 là các chân tín hiệu lần lượt điều khiển động cơ di chuyển bên phải và trái
  //sen1 đến sen4 là chân nhận tín hiệu từ cảm biến hồng ngoại
  //Bây giờ thì lập trình thôi
  switch (deviationDarkLine4Sensor (sen1, sen2, sen3, sen4))
  {
    case -1:
      robotMover( inR1, inR2, inL1, inL2, 6);// rẽ phải
      break;
    case -2:
      robotMover( inR1, inR2, inL1, inL2, 6);
      break;
    case 1:
      robotMover( inR1, inR2, inL1, inL2, 5);// rẽ trái
      break;
    case 2:
      robotMover( inR1, inR2, inL1, inL2, 5);
      break;
    case 0:
      robotMover( inR1, inR2, inL1, inL2, 1);// tiến thẳng
      break;
    case 3:
      robotMover( inR1, inR2, inL1, inL2, 2);// lệch vạch thì lùi
      break;
    case 4:
      robotMover( inR1, inR2, inL1, inL2, 0);
      digitalWrite(4, 1);
      delay(500);
      digitalWrite(4, 0);
      delay(500);
      digitalWrite(4, 1);
      delay(500);
      digitalWrite(4, 0);
      delay(500);
      digitalWrite(4, 1);
      delay(500);
      digitalWrite(4, 0);
      delay(500);
      robotMover( inR1, inR2, inL1, inL2, 1);
      delay(500);
      break;

  }

}
void robotMover (byte inR1, byte inR2, byte inL1, byte inL2, byte action)
{
  /*
    inR1 inR2 là 2 chân tín hiệu động cơ bên phải
    inL1 inL2 là 2 chân tín hiệu động cơ bên trái
    action= 0 đứng yên
    action =1 đi thẳng
    action =2 lùi lại
    action =3 quay trái
    action =4 quay phải
    action =5 rẽ trái
    action =6 rẽ phải

  */
  switch (action)
  {
    case 0:// không di chuyển
      motorControlNoSpeed(inR1, inR2, 0);
      motorControlNoSpeed(inL1, inL2, 0);
      break;
    case 1://đi thẳng
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 1);
      break;
    case 2:// lùi lại
      motorControlNoSpeed(inR1, inR2, 2);
      motorControlNoSpeed(inL1, inL2, 2);
      break;
    case 3:// quay trái
      motorControlNoSpeed(inR1, inR2, 2);
      motorControlNoSpeed(inL1, inL2, 1);
      break;
    case 4:// quay phải
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 2);
      break;
    case 5:// rẽ trái
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 0);
      break;
    case 6:// rẽ phải
      motorControlNoSpeed(inR1, inR2, 0);
      motorControlNoSpeed(inL1, inL2, 1);
      break;
    default:
      action = 0;

  }
}


void motorControlNoSpeed (byte in1, byte in2, byte direct)
{
  // in1 and in2 are 2 signal pins to control the motor
  // en is the enable pin
  // the defauspeed is the highest
  // direct includes:
  //    0:Stop
  //    1:Move on 1 direct
  //    2:Move on another direct
  switch (direct)
  {
    case 0:// Dừng không quay
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      break;
    case 1:// Quay chiều thứ 1
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      break;
    case 2:// Quay chiều thứ 2
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      break;
      //default:
  }
}
boolean IFSensor (byte PinNumb)
{
  //0 sáng
  //1 tối
  return (digitalRead (PinNumb));
}

int deviationDarkLine4Sensor (int PinNumb1, int PinNumb2, int PinNumb3, int PinNumb4)
{
  int left = 0; //biến kiểm tra lệch trái
  int right = 0; // biến kiểm tra lệch phải
  left = IFSensor (PinNumb1) + IFSensor (PinNumb2); //kiểm tra mấy cảm biến trái ở trong màu đen
  right = IFSensor (PinNumb3) + IFSensor (PinNumb4); //kiểm tra mấy cảm biến phải ở trong màu đen
  Serial.print("left=");
  Serial.println(left);
  Serial.print("right=");
  Serial.println(right);
  if (IFSensor (PinNumb1) + IFSensor (PinNumb2) + IFSensor (PinNumb3) + IFSensor (PinNumb4) == 4)
  {
    Serial.println("Gap vach ngang");
    return 4;
  }
  if ((left != 0) || (right != 0))return left - right;
  else return 3;

  /*
    Kết quả trả về là 0 là không lệch
    Âm là lệch trái
    Dương là lệch phải
  */
}