/*****************************************************
  Project Title: Servo Distance Indicator
  Organisation: Soham Academy Of Human Excellence
  Website: https://ria.sohamacademy.org/
*******************************************************/
#include<Servo.h>
int trig = 8;
int echo = 9;
//int dt=10;
Servo servo;
int  degree = 60 ;

//int distance,duration;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  servo.attach(11);
}

int calc_dis()
{
  int duration, distance;
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 29.1;
  return distance;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (calc_dis() < 3)
  {
    servo.write(0);
    Serial.println(calc_dis());
    delay(500);
  }
  else if (calc_dis() > 180 ) {
    servo.write(0);
    Serial.println(calc_dis());
    delay(500);
  }
  else {
    degree = ((calc_dis() * 180) / 60) ;
    servo.write(degree);
    Serial.println(degree);
    delay(1000);
    servo.write(0);
  }
}

//This code is written to calculate the DISTANCE using ULTRASONIC SENSOR
