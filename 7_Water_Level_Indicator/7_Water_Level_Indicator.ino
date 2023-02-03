/********************************************************************
Project Title: Water Level Indicator
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
*********************************************************************/

#define trigger 10
#define echo 9
int ledpin1=13;
int ledpin2=12;
int ledpin3=11;
long duration, distance;  
void setup()
{
 Serial.begin(9600);
 pinMode(trigger,OUTPUT); // set the trigger pin as an output
 pinMode(echo,INPUT); // set the echo pin as an input
 pinMode(ledpin1,OUTPUT);
 pinMode(ledpin2,OUTPUT);
 pinMode(ledpin3,OUTPUT);
}
void loop()
{
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 //time=pulseIn(echo,HIGH); // stores the time span between the transmitted and reflected waves
 //distance=time*0.034/2; //formula to calculate the distance in cm
 duration = pulseIn(echo, HIGH);
 distance = duration/58.2;
 Serial.println(distance);
 if(distance>=50)
 {
   digitalWrite(ledpin1, LOW);
   digitalWrite(ledpin2, LOW);
   digitalWrite(ledpin3, LOW);
   delay(1000);
 }
  else if(distance<50 && distance >30)
 {
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
  delay(1000);
 }
 else if(distance<30 && distance >20)
 {
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  digitalWrite(ledpin3, LOW);
  delay(1000);
 }
 else if(distance<=20)// check if water is full
 {
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  digitalWrite(ledpin3, HIGH);
  delay(1000);
 }
   Serial.println("LED(1,2,3):");
   Serial.println(digitalRead(ledpin1));
   Serial.println(digitalRead(ledpin2));
   Serial.println(digitalRead(ledpin3));
 delay(1000);
}
