
//RC Tank Ver 2.1.1 Copyright by Emre Albayrak.
//In this version motor pin names changed.
//Ver 2.1.1 is not tested yet.

int ch1;
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;
int gas;
int steer;

#define RightBackward 9
#define LeftBackward 10
#define RightForward 11
#define LeftForward 12

void MoveForward();
void MoveBackward();
void MoveForwardLeft();
void MoveForwardRight();
void MoveBackwardLeft();
void MoveBackwardRight();
void Stop();

void setup() {

  Serial.begin(9600);
  
  pinMode(2, INPUT); //gas input channel 
  pinMode(3, INPUT); //steer input channel
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(RightBackward, OUTPUT);  //Right Motor Backward
  pinMode(LeftBackward, OUTPUT); //Left Motor Backward
  pinMode(RightForward, OUTPUT); //Right Motor Forward
  pinMode(LeftForward, OUTPUT); //Letf Motor Forward
}

void loop(){
  
  ch1 = pulseIn(2, HIGH, 25000);
  ch2 = pulseIn(3, HIGH, 25000);
  ch3 = pulseIn(4, HIGH, 25000);
  ch4 = pulseIn(5, HIGH, 25000);
  ch5 = pulseIn(6, HIGH, 25000);
  ch6 = pulseIn(7, HIGH, 25000);
  
  gas = map(ch1,1000,2000,-100,100); 
  steer = map(ch2,1000,2000,-100,100);

 //---------------------------------------------- Forward
  if(gas >= 10){
    if(steer <= -10){ //Right 
      MoveForwardRight();
    }
    if(steer >= 10){ //Left
      MoveForwardLeft();
    }
    MoveForward();
  }    
//----------------------------------------------- Backward
  if(gas <= -10){
    if(steer >= 10){ //Right
      MoveBackwardRight();
    }
    if(steer <= -10){ //Left
      MoveBackwardLeft();
    }
    MoveBackward();
  } 
//----------------------------------------------- Stop
  if(gas >= -10 && gas <= 10){
   Stop();
  }
}
//----------------------------------------------- Functions
void MoveForward(){
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, HIGH);
  digitalWrite(LeftForward, HIGH);
  Serial.print ("forward");
}

void MoveBackward(){
  digitalWrite(RightBackward, HIGH);
  digitalWrite(LeftBackward, HIGH);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, LOW);
  Serial.print ("backward");
}

void MoveForwardLeft(){
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, HIGH;
  Serial.print ("forward left");
}

void MoveForwardRight(){
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, HIGH);
  digitalWrite(LeftForward, LOW;
  Serial.print ("forward right");
}

void MoveBackwardLeft(){
  digitalWrite(RightBackward, HIGH);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, LOW;
  Serial.print ("backward left");
}

void MoveBackwardRight(){
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, HIGH);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, LOW;
  Serial.print ("backward right"); 
}

void Stop(){
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, LOW;
  Serial.print ("stop");  
}
