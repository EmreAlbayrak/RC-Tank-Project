/*
=> RC Tank basic remote controller's RF receiver (Tank side) Ver.1.0
=> Copyright by Emre Albayrak ©
*/

//Note: RF Data pin digital 11

#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;

#define RightBackward 6
#define LeftBackward 5
#define RightForward 4
#define LeftForward 3

void MoveForward();
void MoveBackward();
void MoveForwardLeft();
void MoveForwardRight();
void MoveBackwardLeft();
void MoveBackwardRight();
void Stop();

//--------------------------------------------------------- Setup
void setup() {

  rf_driver.init();
  
  Serial.begin(9600);

  pinMode(RightBackward, OUTPUT);  //Right Motor Backward
  pinMode(LeftBackward, OUTPUT); //Left Motor Backward
  pinMode(RightForward, OUTPUT); //Right Motor Forward
  pinMode(LeftForward, OUTPUT); //Letf Motor Forward
}

//--------------------------------------------------------- Main loop
void loop(){
  char message[1]; 
  uint8_t buf[1];
  uint8_t buflen = sizeof(buf);
  if (rf_driver.recv(buf, &buflen)){
    Serial.println((char*)buf);
    char* message = (char*) buf;
    Serial.println(message);
    if(message[0] == 'w'){
      Serial.print("Message Received: ");
      Serial.println((char*)buf);
      MoveForward(); 
    }
    if(message[0] == 'a'){
      Serial.print("Message Received: ");
      Serial.println((char*)buf); 
      MoveForwardLeft();        
    }
    if(message[0] == 's'){
      Serial.print("Message Received: ");
      Serial.println((char*)buf); 
      MoveBackward();
    }
    if(message[0] == 'd'){
      Serial.print("Message Received: ");
      Serial.println((char*)buf);
      MoveForwardRight(); 
    }
    if(message[0] == 'e'){
      Serial.print("Message Received: ");
      Serial.println((char*)buf);
      Stop(); 
    }
    if(message[0] == 'r'){
      Serial.print("Message Received: ");
      Serial.println("RobotArm");
    }
  }
}
//--------------------------------------------------------- Functions
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
