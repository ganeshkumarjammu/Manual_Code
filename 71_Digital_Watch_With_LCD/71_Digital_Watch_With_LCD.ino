/*********************************************************** 
Project Title : Digital Watch with LCD
Description: Make your own Clock with RTC Module,LCD Display, And get time and Date displays on the LCD
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
***********************************************************/ 

#include "RTClib.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Su", "M", "T", "W", "Th", "F", "S"};

void setup () {
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.clear();
   Serial.begin(9600);
  Serial.print("started");
  
  if (! rtc.begin()) {
    
    Serial.println("Couldn't find RTC");
    while (1);
    delay(10);
  }
  

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  
 
  }
}

void loop () {
    DateTime now = rtc.now();
     lcd.setCursor(0, 0);
    lcd.print("DATE: "); 
    lcd.print(now.year(), DEC);
    Serial.println(now.year(), DEC);
    lcd.print('/');
    lcd.print(now.month(), DEC);
    Serial.println(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.day(), DEC);
    Serial.println(now.day(), DEC);
    
//    lcd.print(" (");
//    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
//    lcd.print(") ");

    lcd.setCursor(0, 1);
    lcd.print("TIME: ");
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    lcd.print(now.second(), DEC);

}
