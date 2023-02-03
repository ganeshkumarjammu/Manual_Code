#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

#define inSensor 2
#define outSensor 3
 
int inStatus;
int outStatus;
 
int countin = 0;
int countout = 0;
 
int in;
int out;
int now;
 
#define relay 4
 
void setup()
{
  lcd.begin();
  lcd.backlight();
  delay(1000);
  pinMode(inSensor, INPUT);
  pinMode(outSensor, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay,LOW);
 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Visitor Counter");
  delay(2000);
}
 
void loop()
{
  inStatus =  digitalRead(inSensor);
  outStatus = digitalRead(outSensor);
  if (inStatus == 0)
  {
    in = countin++;
  }
 
  if (outStatus == 0)
  {
    out = countout++;
  }
 
  now = in - out;
 
  if (now <= 0)
  {
    digitalWrite(relay, LOW);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0, 1);
    lcd.print("Light Off");
    delay(500);
  }
  else
  {
    digitalWrite(relay, HIGH);
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("Person In Room");

    lcd.setCursor(0,1);
    lcd.print(now);
    delay(500);
  }
}
