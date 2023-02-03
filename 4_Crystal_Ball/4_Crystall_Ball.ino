#include <LiquidCrystal_I2C.h>
// Global variables
byte switch_val      = 0;
byte prev_switch_val = 0;
byte reply           = 0; // varies from 0 to 7
const byte SWITCH_PIN = 2;
String Msg1 = "    Ask the ";
String Msg2 = " Crystall Ball";
LiquidCrystal_I2C Lcd(0x27, 16, 2);
void printMsg(String msg1 , String msg2) {
  Lcd.clear();
  Lcd.setCursor(0, 0);
  Lcd.print(msg1);
  Lcd.setCursor(0, 1);
  Lcd.print(msg2);
  delay(2000);
}
void setup() {
  Lcd.begin();
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  // intro message
  printMsg(Msg1,Msg2);
}

void loop() {
  switch_val = digitalRead(SWITCH_PIN);
  if ((switch_val != prev_switch_val) && (switch_val == HIGH)) {
    Serial.println("The ball says");
    reply = random(8); // randomly choose 1 out of 8 anwers
    Lcd.clear();
    Lcd.setCursor(0, 0);
    Lcd.print("The ball says...");
    Lcd.setCursor(0, 1);
    delay(1000);
    switch (reply) {
      case 0:
        Lcd.print("Absolutely");
        break;
      case 1:
        Lcd.print("Probably");
        break;
      case 2:
        Lcd.print("Maybe");
        break;
      case 3:
        Lcd.print("Yep");
        break;
      case 4:
        Lcd.print("Unsure");
        break;
      case 5:
        Lcd.print("Repeat Again");
        break;
      case 6:
        Lcd.print("No");
        break;
      case 7:
        Lcd.print("Impossible");
        break;
    }
    delay(2000);
    printMsg(Msg1,Msg2);
  }
  prev_switch_val = switch_val;
}
