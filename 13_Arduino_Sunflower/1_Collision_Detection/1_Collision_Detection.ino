/*********************************************************
Project Title: Collision Detection
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
*********************************************************/
const int trigPin = 12; //D12 to Trigger Pin of Ultrasonic Sensor 
const int echoPin = 13; //D13 to Echo Pin of Ultrasonic Sensor

const int LED1 = A0; //Connect A0 to Led1 '+'ve 
const int LED2 = A1; //Connect A1 to Led2 '+'ve
const int LED3 = A2; //Connect A2 to Led3 '+'ve
const int LED4 = A3; //Connect A3 to Led4 '+'ve
const int LED5 = A4; //Connect A4 to Led5 '+'ve
const int LED6 = A5; //Connect A5 to Led5 '+'ve
int buzzerPin = 9;   //Connect D9 to Buzzer '+'ve

int duration = 0;
int distance = 0;

void setup() 
{
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);
  
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
  pinMode(LED6 , OUTPUT);
  pinMode(buzzerPin , OUTPUT);
  
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
  distance = duration/58.2;
  
  if ( distance <= 6 )
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(buzzerPin,HIGH);
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(buzzerPin,LOW);
  }
  if ( distance <= 12 )
  {
    digitalWrite(LED2, HIGH);
  }
  else
  {
    digitalWrite(LED2, LOW);
  }
  if ( distance <= 18 )
  {
    digitalWrite(LED3, HIGH);
  }
  else
  {
    digitalWrite(LED3, LOW);
  }
  if ( distance <= 24 )
  {
    digitalWrite(LED4, HIGH);
  }
  else
  {
    digitalWrite(LED4, LOW);
  }
  if ( distance <= 30 )
  {
    digitalWrite(LED5, HIGH);
  }
  else
  {
    digitalWrite(LED5, LOW);
  }
  if ( distance <= 36 )
  {
    digitalWrite(LED6, HIGH);
  }
  else
  {
    digitalWrite(LED6, LOW);
  }
  delay(100);
}
