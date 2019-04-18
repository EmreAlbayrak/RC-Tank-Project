/*RC Tank cahassis drive test code Ver.1.0*/
/*Copyright by Emre Albayrak*/

#define RightBackward 12
#define LeftBackward 10
#define RightForward 11
#define LeftForward 9

void MoveForward();
void MoveBackward();
void MoveForwardLeft();
void MoveForwardRight();
void MoveBackwardLeft();
void MoveBackwardRight();
void Stop();

void setup() {

  Serial.begin(9600);

  pinMode(RightBackward, OUTPUT);  //Right Motor Backward
  pinMode(LeftBackward, OUTPUT); //Left Motor Backward
  pinMode(RightForward, OUTPUT); //Right Motor Forward
  pinMode(LeftForward, OUTPUT); //Letf Motor Forward
}

//----------------------------------------------- Main code here
void loop(){
  MoveForward();
  delay(2000);
  Stop();
  delay(2000);
  MoveBackward();
  delay(2000);
  Stop();
  delay(2000);
  MoveForwardLeft();
  delay(2000);
  Stop();
  delay(2000);
  MoveBackwardLeft();
  delay(2000);
  Stop();
  delay(2000);
  MoveForwardRight();
  delay(2000);
  Stop();
  delay(2000);
  MoveBackwardRight();
  delay(2000);
  Stop();
  delay(2000);
}
//----------------------------------------------- Functions
void MoveForward(){
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, HIGH);
  digitalWrite(LeftForward, HIGH);
  Serial.print ("\nforward");
}

void MoveBackward(){
  digitalWrite(RightBackward, HIGH);
  digitalWrite(LeftBackward, HIGH);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, LOW);
  Serial.print ("\nbackward");
}

void MoveForwardLeft(){
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, HIGH);
  Serial.print ("\nforward left");
}

void MoveForwardRight(){
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, HIGH);
  digitalWrite(LeftForward, LOW);
  Serial.print ("\nforward right");
}

void MoveBackwardLeft(){
  digitalWrite(RightBackward, HIGH);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, LOW);
  Serial.print ("\nbackward left");
}

void MoveBackwardRight(){
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, HIGH);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, LOW);
  Serial.print ("\nbackward right"); 
}

void Stop(){
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, LOW);
  Serial.print ("\nstop");  
}
