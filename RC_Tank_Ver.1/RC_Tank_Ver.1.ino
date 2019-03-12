
// Licensed under Wild Bros.

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

  // Set our input pins as such

  pinMode(2, INPUT); 
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(9, OUTPUT);  //Right Backward
  pinMode(10, OUTPUT); //Left Backward
  pinMode(11, OUTPUT); //Right Forward
  pinMode(12, OUTPUT); //Letf Forward

}

void loop() 
{
  
  ch1 = pulseIn(2, HIGH, 25000);
  ch2 = pulseIn(3, HIGH, 25000);
  ch3 = pulseIn(4, HIGH, 25000);
  ch4 = pulseIn(5, HIGH, 25000);
  ch5 = pulseIn(6, HIGH, 25000);
  ch6 = pulseIn(7, HIGH, 25000);

  // Print data to Serial Monitor window
  
  gas = map(ch1,1000,2000,-100,100);
  steer = map(ch2,1000,2000,-100,100);

 //---------------------------------------------- Forward / Backward
 
  if(gas >= 10){
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
  }
  
  else{
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
  
  if(gas <= -10){
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
    
//---------------------------------------------- Forward Left / Right

  if(gas >= 10 && steer >= 10){ //Turn Right Forward
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  }

  if(gas >= 10 && steer <= -10){ // Turn Left Forward
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  }

  //---------------------------------------------- Backward Left / Right

  if(gas <= -10 && steer >= 10){ // Turn Right Backward
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW); 
  }

  if(gas >= -10 && steer <= -10){ //Turn Left Backward
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH); 
  }
}
