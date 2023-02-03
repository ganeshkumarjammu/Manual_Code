/**************************************************
Project Title: Stick For Blindman
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
**************************************************/

const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

long duration;
int distance;
int safetyDistance;

void setup()
{
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); 
}

void loop() 
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
  Serial.print("duration");
  Serial.println(duration);

distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);

safetyDistance = distance;
if (safetyDistance <=10)
{
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else
{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}
}
