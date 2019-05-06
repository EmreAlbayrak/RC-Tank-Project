/*
=> RC Tank remote controller's RF transmitter code (Computer side) Ver.1.0
=> Copyright by Emre Albayrak © 
*/

#include <RH_ASK.h>
#include <SPI.h> 
 
RH_ASK rf_driver;

char SerialData[10];

// Data pin digital 12

void ledBlink();
 
void setup(){
    Serial.begin(9600);
    rf_driver.init();
    pinMode(13,OUTPUT);
}

void loop(){
  if(Serial.available()){
    Serial.readBytes(SerialData,4);
    
    if(SerialData[0] == 'w'){
      char *msg = "w";
      rf_driver.send((uint8_t *)msg, strlen(msg));
      rf_driver.waitPacketSent();
      ledBlink(10);
    }
    else if(SerialData[0] == 'a'){
      char *msg = "a";
      rf_driver.send((uint8_t *)msg, strlen(msg));
      rf_driver.waitPacketSent();
      ledBlink(10);
    }
    else if(SerialData[0] == 's'){
      char *msg = "s";
      rf_driver.send((uint8_t *)msg, strlen(msg));
      rf_driver.waitPacketSent();
      ledBlink(10);
    }
    else if(SerialData[0] == 'd'){
      char *msg = "d";
      rf_driver.send((uint8_t *)msg, strlen(msg));
      rf_driver.waitPacketSent();
      ledBlink(10);
    }
    else if(SerialData[0] == 'e'){
      char *msg = "e";
      rf_driver.send((uint8_t *)msg, strlen(msg));
      rf_driver.waitPacketSent();
      ledBlink(10);
    }
    else if(SerialData[0] == 'r'){
      char *msg = "r";
      rf_driver.send((uint8_t *)msg, strlen(msg));
      rf_driver.waitPacketSent();
      ledBlink(10);
    }
  }
}

void ledBlink(int delaytime){
  digitalWrite(13,HIGH);
  delay(delaytime);
  digitalWrite(13,LOW);
  delay(delaytime);
}
