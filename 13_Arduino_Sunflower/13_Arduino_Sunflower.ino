/****************************************************
Project Title: Arduino Sunflower
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
****************************************************/

#include <Servo.h>

int sensorPin = A0;
int servoPin  = 9;

int sensorValue = 0;
int servoGrad = 90;
int tolerance = 40;
int meanValue = 512 ;

Servo myservo;

void setup() {
  pinMode( sensorPin, INPUT);
  myservo.attach( servoPin );
  myservo.write( servoGrad );
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("Sensor value :");
  Serial.println(sensorValue);
  if ( sensorValue < (meanValue-tolerance) )
  {
    if (servoGrad < 180) servoGrad++;
  }

  if ( sensorValue > (meanValue+tolerance) )
  {
    if (servoGrad > 0) servoGrad--;
  }

  myservo.write( servoGrad ); 
  delay(100);
}
