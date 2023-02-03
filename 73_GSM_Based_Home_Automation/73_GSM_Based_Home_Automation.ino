/*********************************************************** 
Project Title : GSM Based Home Automation
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
***********************************************************/ 
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27, 16, 2); // CHANGE THE 0X3F ADDRESS TO YOUR SCREEN ADDRESS IF NEEDED
//LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2); 
//GSM (SIM-900A) IN WORK CONDITION
//DC-PWR AND STATUS should be on (no blinck) state
//Nwk should be blink 
//NOTE: To check whether sim can receive message or not we can call to the number and 1)If rings then we can performe the activity without any doubt and 2)If it doesnt ring then the network is not set just wait for a while and try again.  

#define Fan 3
#define Light 4
#define TV 5
int temp=0,i=0;
int led=13;
char str[15];
void setup()
{
  lcd.begin();
  Serial.begin(9600);
  pinMode(led, OUTPUT);
   pinMode(Fan, OUTPUT);
    pinMode(Light, OUTPUT);
     pinMode(TV, OUTPUT);
  
  lcd.setCursor(0,0);
  lcd.print("GSM Control Home");
  lcd.setCursor(0,1);
  lcd.print("   Automaton    ");
  delay(2000);
  lcd.clear();
  lcd.print("Haccian");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("System Ready");
  Serial.println("AT+CNMI=2,2,0,0,0");
  delay(500);
  Serial.println("AT+CMGF=1");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fan   Light  TV ");
  lcd.setCursor(0,1);
  lcd.print("OFF    OFF   OFF "); 
}
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Fan   Light  TV");
  serialEvent();
  if(temp==1)
  {
    check();
    temp=0;
    i=0;
    delay(1000);
  }
}
 void serialEvent() 
 {
  while(Serial.available()) 
  {
    if(Serial.find("#A."))
    {
      digitalWrite(led, HIGH);
      delay(1000);
      digitalWrite(led, LOW);
      while (Serial.available()) 
      {
      char inChar=Serial.read();
      Serial.print(inChar);
      str[i++]=inChar;
      if(inChar=='*')
      {
        temp=1;
        return;
      } 
      } 
    }
   }
 }
void check()
{
   if(!(strncmp(str,"TV ON",5)))
    {
      digitalWrite(TV, HIGH);
      Serial.print("received tv on");
       Serial.print(str);
      lcd.setCursor(13,1); 
      lcd.print("ON    ");
      delay(200);
    }  
   
   else if(!(strncmp(str,"TV OFF",6)))
    {
      digitalWrite(TV, LOW);
       Serial.print("received tv off");
       Serial.print(str);
      lcd.setCursor(12,1); 
      lcd.print("OFF    ");
      delay(200);
    }
  
    else if(!(strncmp(str,"FAN ON",6)))
    {
      digitalWrite(Fan, HIGH);
       Serial.print("received fan on");
       Serial.print(str);
      lcd.setCursor(0,1); 
      lcd.print("ON   ");
      delay(200);
    }
 
    else if(!(strncmp(str,"FAN OFF",7)))
    {
      digitalWrite(Fan, LOW);
       Serial.print("received fan off");
       Serial.print(str);
      lcd.setCursor(0,1); 
      lcd.print("OFF    ");
      delay(200);
    }
 
    else if(!(strncmp(str,"LIGHT ON",8)))
    {
      digitalWrite(Light, HIGH);
       Serial.print("received light on");
      // Serial.print(str);
      lcd.setCursor(7,1); 
      lcd.print("ON    ");
      delay(200);
    }
 
    else if(!(strncmp(str,"LIGHT OFF",9)))
    {
      digitalWrite(Light, LOW);
       Serial.print("received light off");
       Serial.print(str);
      lcd.setCursor(7,1); 
      lcd.print("OFF    ");
      delay(200);
    } 
    
    else if(!(strncmp(str,"ALL ON",6)))
    {
      digitalWrite(Light, HIGH);
      digitalWrite(Fan, HIGH);
      digitalWrite(TV, HIGH);    
      lcd.setCursor(0,1); 
      lcd.print("ON     ON    ON  ");
      delay(200);
    }
 
    else if(!(strncmp(str,"ALL OFF",7)))
    {
      digitalWrite(Light, LOW);
      digitalWrite(Fan, LOW);
      digitalWrite(TV, LOW);
      lcd.setCursor(0,1); 
      lcd.print("OFF   OFF    OFF  ");
      delay(200);
    }
    }
