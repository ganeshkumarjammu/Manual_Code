/*****************************************************
Project Title: Smartphone Liquid Level Monitoring System
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
****************************************************/
#include <NewPing.h>
#include <SoftwareSerial.h> 
SoftwareSerial bt(0, 1); // RX | TX 
int flag;
String FirstName="Kushal";
#define TRIGGER_PIN 10
#define ECHO_PIN 11
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  bt.begin(38400);
}

void loop() {
  if (bt.available())
   flag = bt.read(); 
  
  Serial.print(sonar.ping_cm());
  Serial.println(" cm");
  delay(1000);                           
}
