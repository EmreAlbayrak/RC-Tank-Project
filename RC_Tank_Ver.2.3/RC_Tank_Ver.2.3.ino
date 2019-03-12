//RC Tank Ver 2.3 Copyright by Emre Albayrak.
//

int ch1;
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;
int gas;
int steer;
int GasRfStartValue;
int SteerRfStartValue;
int GasRfForwardLimit;
int GasRfBackwardLimit;
int SteerRfLeftLimit;
int SteerRfRightLimit;

void MoveForward();
void MoveBackward();
void MoveForwardLeft();
void MoveForwardRight();
void MoveBackwardLeft();
void MoveBackwardRight();
void Stop();

void RfCalibration();
bool flag = true;

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
  pinMode(44, OUTPUT); //Right Motor PWM
  pinMode(45, OUTPUT); //Left Motor PWM
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
  RfCalibration();
  
 //---------------------------------------------- Forward
  if(gas >= GasRfForwardLimit){
    if(steer <= SteerRfRightLimit){ //Right 
      MoveForwardRight();
    }
    if(steer >= SteerRfLeftLimit){ //Left
      MoveForwardLeft();
    }
    MoveForward();
  }    
//----------------------------------------------- Backward
  if(gas <= GasRfBackwardLimit){
    if(steer >= SteerRfRightLimit){ //Right
      MoveBackwardRight();
    }
    if(steer <= SteerRfLeftLimit){ //Left
      MoveBackwardLeft();
    }
    MoveBackward();
  } 
//----------------------------------------------- Stop
  if(gas >= GasRfBackwardLimit && gas <= GasRfForwardLimit){
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
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  Serial.print ("stop");  
}

void RfCalibration(){
  if(flag == true){
    digitalWrite(13, HIGH);
    delay(5000);
    GasRfStartValue = gas;
    SteerRfStartValue = steer;
    GasRfForwardLimit = GasRfStartValue + 10;
    GasRfBackwardLimit = GasRfStartValue - 10;
    SteerRfRightLimit = SteerRfStartValue -10;
    SteerRfLeftLimit = SteerRfStartValue + 10;
    digitalWrite(13, LOW);
    flag = false;
  }
}
