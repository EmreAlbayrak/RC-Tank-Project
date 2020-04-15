/*
 *Latest Update : 15.04.2020 
 *Developer     : Emre Albayrak Istanbul/TURKEY
 *This program written for control the arduino based robot tank chassis with using two channel of RC module. 
 *It uses RC modul's two channel (throttle and steer) an mix them for tank motion principle.
 *For more https://github.com/EmreAlbayrak/Arduino-RC-RF-Tank-Project/.
*/
//---------------------- For motor driver
#define RightBackward      6
#define LeftBackward       7
#define RightForward       5
#define LeftForward        8
#define R_Enable           10
#define L_Enable           9
void MoveForward();
void MoveBackward();
void MoveForwardLeft();
void MoveForwardRight();
void MoveBackwardLeft();
void MoveBackwardRight();
void TankTurnLeft();
void TankTurnRight();
void Stop();
int left_pwm_value;
int right_pwm_value;
//---------------------- For RC receiver
#define throttle 2 //throttle input from rc receiver
#define steering 3 //steering input from rc receiver
int ch1; //Steering channel direct input value
int ch2; //Throttle channel direct input value
int ch1_map; //Steer channel map value
int ch2_map; //Throttle channel map value
//--------------------------------------------------------- Setup
void setup() {
  Serial.begin(9600);
//----------------------- For motor driver
  pinMode(RightBackward, OUTPUT);  //Right Motor Backward
  pinMode(LeftBackward, OUTPUT); //Left Motor Backward
  pinMode(RightForward, OUTPUT); //Right Motor Forward
  pinMode(LeftForward, OUTPUT); //Letf Motor Forward
  pinMode(R_Enable, OUTPUT);
  pinMode(L_Enable,OUTPUT);
//----------------------- For RC receiver  
  pinMode(throttle, INPUT);
  pinMode(steering, INPUT);
}
//--------------------------------------------------------- Main code 
void loop(){
  ch1 = pulseIn(steering, HIGH, 25000);
  ch2 = pulseIn(throttle, HIGH, 25000);
  ch1_map = map(ch1,1000,2000,-100,100);
  ch2_map = map(ch2,1000,2000,-100,100);
  if(ch2_map >= 10){
    MoveBackward();
  }
  else if(ch2_map <= -10){
    MoveForward();
  }
  else if(ch1_map >= 10){
    TankTurnLeft();
  }
  else if(ch1_map <= -10){
    TankTurnRight();
  }
  else {
    Stop();
  }
}
//--------------------------------------------------------- Functions
void MoveForward(){
  if(ch1_map >= 10){
    right_pwm_value = map(ch2_map,-10,-105,50,255);
    left_pwm_value = map(ch1_map,10,105,50,right_pwm_value);
    left_pwm_value = right_pwm_value - left_pwm_value;
  }
  else if(ch1_map <= -10){
    left_pwm_value = map(ch2_map,-10,-105,50,255);
    right_pwm_value = map(ch1_map,-10,-105,50,left_pwm_value);
    right_pwm_value = left_pwm_value - right_pwm_value;
  }
  else{
    right_pwm_value = map(ch2_map,-10,-105,50,255);
    left_pwm_value = map(ch2_map,-10,-105,50,255); 
  }
  analogWrite(R_Enable, right_pwm_value);
  analogWrite(L_Enable, left_pwm_value);
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, HIGH);
  digitalWrite(LeftForward, HIGH);
  Serial.print ("\nforward");
/*
  Serial.print("left pwm: ");
  Serial.println(left_pwm_value);
  Serial.print("right pwm: ");
  Serial.println(right_pwm_value);
*/
}
void MoveBackward(){
  if(ch1_map >= 10){
    right_pwm_value = map(ch2_map,10,105,50,255);
    left_pwm_value = map(ch1_map,10,105,50,right_pwm_value);
    left_pwm_value = right_pwm_value - left_pwm_value;
  }
  else if(ch1_map <= -10){
    left_pwm_value = map(ch2_map,10,105,50,255);
    right_pwm_value = map(ch1_map,-10,-105,50,255);
    right_pwm_value = left_pwm_value - right_pwm_value;
  }
  else{
    right_pwm_value = map(ch2_map,10,105,50,255);
    left_pwm_value = map(ch2_map,10,105,50,255);
  }
  analogWrite(R_Enable, right_pwm_value);
  analogWrite(L_Enable, left_pwm_value);
  digitalWrite(RightBackward, HIGH);
  digitalWrite(LeftBackward, HIGH);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, LOW);
  Serial.print ("\nbackward");
}
void MoveForwardLeft(){
  analogWrite(R_Enable, right_pwm_value);
  analogWrite(L_Enable, left_pwm_value);
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, HIGH);
  digitalWrite(LeftForward, LOW);
  Serial.print ("\nforward left");
}
void MoveForwardRight(){
  analogWrite(R_Enable, right_pwm_value);
  analogWrite(L_Enable, left_pwm_value);
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, HIGH);
  Serial.print ("\nforward right");
}
void MoveBackwardLeft(){
  analogWrite(R_Enable, right_pwm_value);
  analogWrite(L_Enable, left_pwm_value);
  digitalWrite(RightBackward, HIGH);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, LOW);
  Serial.print ("\nbackward left");
}
void MoveBackwardRight(){
  analogWrite(R_Enable, right_pwm_value);
  analogWrite(L_Enable, left_pwm_value);
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, HIGH);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, LOW);
  Serial.print ("\nbackward right"); 
}
void TankTurnLeft(){
  right_pwm_value = map(ch1_map,10,105,50,255);
  left_pwm_value = map(ch1_map,10,105,50,255); 
  analogWrite(R_Enable, right_pwm_value);
  analogWrite(L_Enable, left_pwm_value);
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, HIGH);
  digitalWrite(RightForward, HIGH);
  digitalWrite(LeftForward, LOW);
  Serial.print ("\ntank turn left"); 
}
void TankTurnRight(){
  right_pwm_value = map(ch1_map,-10,-105,50,255);
  left_pwm_value = map(ch1_map,-10,-105,50,255); 
  analogWrite(R_Enable, right_pwm_value);
  analogWrite(L_Enable, left_pwm_value);
  digitalWrite(RightBackward, HIGH);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, HIGH);
  Serial.print ("\ntank turn right"); 
}
void Stop(){
  digitalWrite(RightBackward, LOW);
  digitalWrite(LeftBackward, LOW);
  digitalWrite(RightForward, LOW);
  digitalWrite(LeftForward, LOW);
  Serial.print ("\nstop");
}
