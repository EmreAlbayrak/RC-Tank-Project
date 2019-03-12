
//RC Tank Ver 2.1 Copyright by Emre Albayrak.
//In this version motor moves reorganized with using functions.
//Ver 2.1 is not tested yet.

int ch1;
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;
int gas;
int steer;

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
  pinMode(9, OUTPUT);  //Right Motor Backward
  pinMode(10, OUTPUT); //Left Motor Backward
  pinMode(11, OUTPUT); //Right Motor Forward
  pinMode(12, OUTPUT); //Letf Motor Forward
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
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  Serial.print ("forward");
}

void MoveBackward(){
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  Serial.print ("backward");
}

void MoveForwardLeft(){
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  Serial.print ("backward left");
}

void MoveForwardRight(){
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  Serial.print ("forward right");
}

void MoveBackwardLeft(){
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  Serial.print ("backward left");
}

void MoveBackwardRight(){
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW); 
  Serial.print ("backward right"); 
}

void Stop(){
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  Serial.print ("stop");  
}
