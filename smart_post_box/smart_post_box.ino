/*
********************************************
📌Smart Post Box  © by Thevapriyan
********************************************
*/

/*
Nodemcu Vin - Mega 5v
Nodemcu Gnd - Mega Gnd
Nodemcu D3 - Echo pin  
Nodemcu D4 - Trig pin   
*/

#define BLYNK_PRINT Serial   // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// NodeMCU Pin D1 > TRIGGER | Pin D2 > ECHO


#define TRIGGER D4
#define ECHO    D3
int x=0;
#define SOUND_VELOCITY 0.034

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[]= "ja9PuZ_23Ak2_qFBVJ2Am0qXC_JembLD";

// Your WiFi connections.
char ssid[]="SLT-4G_C6E8B";
char pass[]="prolink12345";



void setup() {
  
  Serial.begin (115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(D5,OUTPUT);

  int x=0; 
 
  
}

void loop() {
  
  
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
 
 distance = duration * SOUND_VELOCITY/2;
   if (distance <=7) {
    x++;
    Blynk.virtualWrite(V1,x);
   
}
  else {
    Blynk.virtualWrite(V1,x);
   
  }

 
  Serial.print(distance);
  //Serial.println("Centimeter:");
 

   Serial.print("Distance  : ");
  Serial.print(distance);
  Serial.println("Cm");

    
  delay(1000);
  Blynk.run();
}
