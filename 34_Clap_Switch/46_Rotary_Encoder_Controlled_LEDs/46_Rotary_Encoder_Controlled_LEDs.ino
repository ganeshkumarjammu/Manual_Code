/*********************************************************
Project Title: Rotary Encoder Cotrolled LEDs
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
*********************************************************/
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Rotary Encoder Inputs
#define CLK 2
#define DT 3
#define SW 4

int currentStateCLK;
int lastStateCLK;
unsigned long lastButtonPress = 0;

int leds [] = {5, 6, 7, 8};

unsigned int menu = 0;
int ledStatus[5] = {0};
int timer = 1000;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();

  // Set encoder pins as input
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }

  menu = 0;
  updateMenu();
}

void loop() {
  currentStateCLK = digitalRead(CLK);

  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1) {
    if (digitalRead(DT) != currentStateCLK) {
      menu --;
      updateMenu();
    } else {
      menu ++;
      updateMenu();
    }
  }
  lastStateCLK = currentStateCLK;

  int btnState = digitalRead(SW);
  if (btnState == LOW) {
    if (millis() - lastButtonPress > 50) {
      executeAction();
      updateMenu();
    }
    lastButtonPress = millis();
  }
  delay(1);
}

void printlcd(){
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("LED Controller");
      lcd.setCursor(0, 1);
  }
void updateMenu() {
  
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      printlcd();
      lcd.print("     Led 1>"); 
      break;
    case 2:
      printlcd();
      lcd.print("    <Led 2>");
      break;
    case 3:
      printlcd();
      lcd.print("    <Led 3>");
      break;
    case 4:
      printlcd();
      lcd.print("    <Led 4");
      break;
    case 5:
      menu = 4;
      break;
  }
}
void executeAction() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;
  }
}

void action1() {
  if (ledStatus[menu] != 0) {
    ledStatus[menu] = 0;
    lcd.clear();
    lcd.print("> LED 1 OFF...");
    digitalWrite(leds[menu - 1], ledStatus[menu]);
    delay(timer);
  } else {
    ledStatus[menu] = 1;
    lcd.clear();
    lcd.print("> LED 1 ON...");
    digitalWrite(leds[menu - 1], ledStatus[menu]);
    delay(timer);
  }
}
void action2() {
  if (ledStatus[menu] != 0) {
    ledStatus[menu] = 0;
    lcd.clear();
    lcd.print("> LED 2 OFF...");
    digitalWrite(leds[menu - 1], ledStatus[menu]);
    delay(timer);
  } else {
    ledStatus[menu] = 1;
    lcd.clear();
    lcd.print("> LED 2 ON...");
    digitalWrite(leds[menu - 1], ledStatus[menu]);
    delay(timer);
  }
}
void action3() {
  if (ledStatus[menu] != 0) {
    ledStatus[menu] = 0;
    lcd.clear();
    lcd.print("> LED 3 OFF...");
    digitalWrite(leds[menu - 1], ledStatus[menu]);
    delay(timer);
  } else {
    ledStatus[menu] = 1;
    lcd.clear();
    lcd.print("> LED 3 ON...");
    digitalWrite(leds[menu - 1], ledStatus[menu]);
    delay(timer);
  }
}
void action4() {
  if (ledStatus[menu] != 0) {
    ledStatus[menu] = 0;
    lcd.clear();
    lcd.print("> LED 4 OFF...");
    digitalWrite(leds[menu - 1], ledStatus[menu]);
    delay(timer);
  } else {
    ledStatus[menu] = 1;
    lcd.clear();
    lcd.print("> LED 4 ON...");
    digitalWrite(leds[menu - 1], ledStatus[menu]);
    delay(timer);
  }
}
