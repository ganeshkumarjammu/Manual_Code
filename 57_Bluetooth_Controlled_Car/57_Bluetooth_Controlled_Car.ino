/***********************************************************
Project Title : Bluetooth Controlled Car
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
***********************************************************/
#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1); //TX, RX  pins of arduino respetively

int Input1 = 2;                 //araduino Digitalpin 10 set as output Pinconnected to L293D pin input1
int Input2 = 3;                 //araduino Digitalpin 11 set as output Pinconnected to L293D pin input2
int Input3 = 4;                 //araduino Digitalpin 12 set as output Pinconnected to L293D pin input3
int Input4 = 5;                 //araduino Digitalpin 13 set as output Pinconnected to L293D pin input4
char Value;
const int En1 = 6;
const int En2 = 7;

char stop() 
{
  digitalWrite(Input1, LOW);
  digitalWrite(Input2, LOW);
  digitalWrite(Input3, LOW);
  digitalWrite(Input4, LOW);
  digitalWrite(En1, LOW);
  digitalWrite(En2,LOW);
  
}

void setup()
{
  BT.begin(9600);
  pinMode(Input1, OUTPUT);
  pinMode(Input2, OUTPUT);
  pinMode(Input3, OUTPUT);
  pinMode(Input4, OUTPUT);
  pinMode(En1,OUTPUT);
  pinMode(En2,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  String command = "";
  while (BT.available())
  { 
    //Check if there is an available byte to read
    Serial.println("BT Available - Command");
    delay(10);                              //Delay added to make thing stable
    //char command[] = "";
    char c = BT.read();                     //Conduct a serial read
    command += c;                           //build the string.
    Serial.println(command);
  
    //Right  
    if(command == "R"){
      digitalWrite(Input1, HIGH); 
      digitalWrite(Input2, LOW); 
      digitalWrite(Input3, HIGH); 
      digitalWrite(Input4, HIGH);
      digitalWrite(En1,HIGH);
      digitalWrite(En2,HIGH);
      Serial.println("Output is Right");
      delay(1000);
    }

    //Reverse
    if(command == "D"){
      digitalWrite(Input1, LOW); 
      digitalWrite(Input2, HIGH); 
      digitalWrite(Input3, HIGH); 
      digitalWrite(Input4, LOW);
      digitalWrite(En1,HIGH);
      digitalWrite(En2,HIGH);
      Serial.println("Output is Reverse");
      delay(1000);
    }
    //Forward
    if(command == "U"){
      digitalWrite(Input1, HIGH); 
      digitalWrite(Input2, LOW); 
      digitalWrite(Input3, LOW); 
      digitalWrite(Input4, HIGH);
      digitalWrite(En1,HIGH);
      digitalWrite(En2,HIGH);
      Serial.println("Output is Forward");
      delay(1000);
    }
    //Stop
    if(command == "S"){
      digitalWrite(Input1, HIGH); 
      digitalWrite(Input2, HIGH); 
      digitalWrite(Input3, HIGH); 
      digitalWrite(Input4, HIGH);
      digitalWrite(En1,HIGH);
      digitalWrite(En2,HIGH);
      Serial.println("Output is Stop");
      delay(1000);
    }
    //Left  
    if(command == "L"){
      digitalWrite(Input1, HIGH); 
      digitalWrite(Input2, HIGH); 
      digitalWrite(Input3, LOW); 
      digitalWrite(Input4, HIGH);
      digitalWrite(En1,HIGH);
      digitalWrite(En2,HIGH);
      Serial.println("Output is Left");
      delay(1000);
    }
  }
}
// End of program
