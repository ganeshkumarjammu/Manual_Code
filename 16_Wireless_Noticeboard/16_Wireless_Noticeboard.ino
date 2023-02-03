#include <LiquidCrystal_I2C.h>
char str[34],L=2;
int draft=0,i=0;
int Pass=0,p=0;
 int c,x,d;

LiquidCrystal_I2C lcd(0x27,16,2);

void serialEvent() 
 {
      while (Serial.available()) 
      {
      char inChar=Serial.read();
      str[i++]=inChar;
      delay(10);
      }
       for (p=i+1;p<34;p++)
      {
        str[i++]=32;
      }
    draft=1;
     Serial.print(str);
  Serial.write(str);

  lcd.setCursor(0, 0);
 lcd.print(str);
 delay(4000);
  if(i>16)
  {
    d=16;
    for (x=0;x<=17;x++)
    {
    lcd.setCursor(x,2);
    lcd.print(str[d]);
    
    d++;
    }
  }Serial.println(str);
 }

 void check()
{
if(!(strncmp(str,"1",1)))
  {
   digitalWrite(7,50);
   Serial.println(str);
   lcd.clear(); 
  }
  else if(!(strncmp(str,"2",1)))
  {
   digitalWrite(7,LOW);
   Serial.println(str);
   lcd.clear(); 
  }
}

void setup()
{
 Serial.begin(9600);
 pinMode(7,OUTPUT);
 lcd.begin();
 lcd.setCursor(0, 0);
 lcd.print("Wireless Notice");
 lcd.setCursor(0, 1);
 lcd.print("     Board     ");
 delay(1500);
 lcd.clear();
 lcd.print("Welcome!");
}


void loop() 
{ 
  if(draft==1)
  {
    check();
     draft=0;
    i=0;
    delay(1000);
    serialEvent();
  }
  
}




