

#define BLYNK_PRINT Serial
#include <Servo.h>

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include "HX711.h"


char auth[] = "HP_BBzdUf28xg04RPGudj80DrDvPxgfU";


char ssid[] = "vippar";
char pass[] = "vipul5678";

float p=0;


HX711 scale(D1,D2);


Servo servo;

BLYNK_WRITE(V3) {

servo.write(param.asInt());
Serial.begin(9600);
Serial.print(param.asInt());
}



void setup()
{

  scale.set_scale(-228);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();  
  scale.read();

  Serial.begin(9600);
  
   
  Blynk.begin(auth, ssid, pass);

  servo.attach(D3);
}

void loop()
{
  
  Blynk.run();
  scale.get_units();

  p = scale.get_units();
 
  Serial.println(p);
  Blynk.virtualWrite(V5, p);




}
