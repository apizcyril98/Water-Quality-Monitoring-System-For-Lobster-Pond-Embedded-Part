#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "fyp2022-2046f-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "i5IdmiEFLLCfBZDc2lkLXbkzZad7Z17KIuzgdMo8"
#define WIFI_SSID "fyp2022"
#define WIFI_PASSWORD "9sampai1"


SoftwareSerial port1(D2,D3); //RX,TX
SoftwareSerial port2(D6,D7); //RX,TX

int period = 1000;
unsigned long time_now = 0;

void waitFor(int time){
    int period = time;
    unsigned long time_now = millis();
    while(millis() < time_now + period){}
  }



void setup(){
  Serial.begin(9600);
  port1.begin(4800);
  port2.begin(4800);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);  
  }
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop(){ 
  port1.listen();
  delay(200);
  while(port1.available()>0){
    float val = port1.parseFloat();
    if(port1.read()== '\n'){
      Serial.print("DO: ");
      Serial.println(val);
      Firebase.setFloat("Data/DO", val);
      break;
    }
  }
  
  port2.listen();
  delay(200);
  while(port2.available()>0){
    float val = port2.parseFloat();
    if(port2.read()== '\n'){
      Serial.print("PH: ");
      Serial.println(val);
      Firebase.setFloat("Data/PH", val);
      break;
    }
  }
  waitFor(1000);
}
