
//RC Tank Ver 2.0 Copyright by Emre Albayrak.
//This version working with two loops (left and right) into two gas loops (forward and backward). It is not include pwm for motor driver, only 1/0. Also program print the action via seral monitor.
//Ver 2.0 is not tested yet!

int ch1;
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;
int gas;
int steer;


void setup() 
{
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

void loop() 
{
  
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
    if(steer <= -10){ //Turn Right 
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      Serial.print ("\nforward right");
    }

    if(steer >= 10){ // Turn Left
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      Serial.print ("\nforward left");
    }

    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    Serial.print ("\nforward");
  }
  
    
//---------------------------------------------- Backward

  if(gas <= -10){
    if(steer >= 10){ //Turn Right
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW); 
      Serial.print ("\nbackward right");
    }

    if(steer <= -10){ //Turn Left
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
      Serial.print ("\nbackward left"); 
    }
    
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
    Serial.print ("\nbackward");
  
//------------------------------------------------ Stop

  if(gas >= -10 && gas <= 10){
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    Serial.print ("\nstop");
  }
}
