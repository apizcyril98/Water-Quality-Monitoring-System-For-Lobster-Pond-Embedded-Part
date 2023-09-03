#include <SoftwareSerial.h>
#include <Wire.h>

#define doAddress 97
#define phAddress 99

byte code=0;                
char data[20];            
byte in_char=0;                  
byte i=0;                      
int time_=2000;                 
float RTD_float; 

SoftwareSerial port1(11,10); //RX,TX
SoftwareSerial port2(13,12);

void setup() {
  Serial.begin(9600);
  port1.begin(4800);
  port2.begin(4800);
  Wire.begin();

}

void loop() {
 //for DO
 Wire.beginTransmission(doAddress);
 Wire.write('r');
 Wire.endTransmission();
 delay(time_);
 Wire.requestFrom(doAddress, 20, 1);
 code = Wire.read();
 
 while(Wire.available()){        
  in_char = Wire.read();        
  data[i]= in_char;             
  i+=1;                            
  if(in_char==0){                 
  i=0;                             
  break;                      
    }
  }
  port1.print(data);
  port1.println("\n");
  delay(30);

  //for PH
  Wire.beginTransmission(phAddress);
  Wire.write('r');
  Wire.endTransmission();
  delay(time_);
  Wire.requestFrom(phAddress, 20, 1);
  code = Wire.read();
  while(Wire.available()){        
    in_char = Wire.read();        
    data[i]= in_char;             
    i+=1;                           
    if(in_char==0){                 
      i=0;                             
      break;                      
    }
  }
  port2.print(data);
  port2.println("\n");
  delay(30);
  
  port1.listen();
  delay(3000);
  while(port1.available()>0){
    float val = port1.parseFloat();
    if(port1.read()== '\n'){
      Serial.print("from port 1: ");
      Serial.println(val);
      break;
    }
  }

}
