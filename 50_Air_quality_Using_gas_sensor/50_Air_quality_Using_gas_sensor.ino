/*********************************************************
Project Title: Air Quality Using Gas Sensor
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
*********************************************************/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define LCD_I2C_ADDRESS 0x27
#define LCD_DISP_COLS   16
#define LCD_DISP_ROWS   2
LiquidCrystal_I2C lcd( LCD_I2C_ADDRESS, LCD_DISP_COLS, LCD_DISP_ROWS );

int gasLevel = 0;        
String quality ="";

void air_sensor()
{
  gasLevel = analogRead(A0);
  Serial.println(gasLevel);
  lcd.setCursor (0,0);
lcd.print("Air Quality  ");
lcd.setCursor (0,1);
  if(gasLevel<= 130){
    lcd.print("  GOOD!");
  }
  else if (gasLevel >130 && gasLevel<= 170){
    lcd.print("  POOR!");
  }
  else if (gasLevel >170 && gasLevel<= 200){
    lcd.print("  Very BAD");
  }
  else if (gasLevel >200 && gasLevel<= 350){
    lcd.print("You are Dead");  
  }
  else if (gasLevel> 350 ){
      lcd.print("You are Dead"); 
}  
else {
  lcd.print("Good");
}

lcd.print(quality);
delay(2000);
}




void setup() {
  Serial.begin(9600);                   
  lcd.begin();
  lcd.backlight();               
  lcd.setCursor (0,0);                  
  lcd.print("AIR QUALITY");
  lcd.setCursor (0,1);
  lcd.print("MONITOR");
  delay(2000); 
  lcd.clear();                        
}

void loop() {
air_sensor();
}
