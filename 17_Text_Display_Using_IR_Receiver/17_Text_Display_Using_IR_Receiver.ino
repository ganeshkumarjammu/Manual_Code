/********************************************************************
Project Title: Text Display Using IR Receiver And Controller
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
*********************************************************************/
#include<LiquidCrystal_I2C.h>
#include <IRremote.h>
 
int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;
LiquidCrystal_I2C lcd(0x27,16,2);
int i=0;

byte Heart[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000};

byte Z1[] = {
  B01111,
  B00001,
  B00010,
  B00100,
  B01000,
  B01111,
  B00000,
  B00000};

byte Z2[] = {
  B00000,
  B00000,
  B00000,
  B00111,
  B00001,
  B00010,
  B00100,
  B00111};
void setup() {
 lcd.createChar(1, Heart);
  lcd.createChar(2, Z1);
  lcd.createChar(3, Z2);
Serial.begin (9600);
irrecv.enableIRIn();
lcd.begin();
lcd.backlight();
lcd.print("Starting System");
delay(2000);
lcd.clear();
lcd.print("System on");
delay(1000);
lcd.clear();
lcd.setCursor(0, 0);
    lcd.print("Press Button");
lcd.setCursor(0, 1);
    lcd.print("To Get Value");

    
}
void loop(){
  if (irrecv.decode(&results)){
switch(results.value)
     {        
  case 0x3AFF6CC7://1 Button
    Serial.print("Button Pressed 1 Passing Text to LCD");
    lcd.begin();
//    lcd.print("Button Press 1"); // Button 2  
//    lcd.setCursor(0, 1);
lcd.print("Welcome to Soham");
break;          
  
        
  case 0x36A1F8CB://2 Button
    Serial.print("Button Pressed 2 Passing Text to LCD");
    lcd.begin();
//    lcd.print("Button Press 2"); // Button 2  
//    lcd.setCursor(0, 1);
lcd.print("Good Morning");
break;              

  case 0x1FEF807://3 Button
    Serial.print("Button Pressed 3 Passing Text to LCD");
    lcd.begin();
//    lcd.print("Button Press 3"); // Button 2  
//    lcd.setCursor(0, 1);
lcd.print("Good Afternoon");
break;

case 0x1FE30CF://4 Button
    Serial.print("Button Pressed 4 Passing Text to LCD");
    lcd.begin();
//    lcd.print("Button Press 4"); // Button 2  
//    lcd.setCursor(0, 1);
 lcd.print("Good Evening");
break;

case 0x1FEB04F://5 Button
    Serial.print("Button Pressed 5 Passing Text to LCD");
    lcd.begin();
//    lcd.print("Button Press 5"); // Button 2  
//    lcd.setCursor(0, 1);
    lcd.print("What can I do?");
break;

case 0x1FE708F://6 Button
    Serial.print("Button Pressed 6 Passing Text to LCD");
    lcd.begin();
    //lcd.print("Button Press 6"); // Button 2  
    //lcd.setCursor(0, 1);
   lcd.print("Can I help you");
break;

//case 0x1FE708F://6 Button
// Serial.print("Button Pressed 6 Passing Text to LCD");
// lcd.begin();
//  lcd.print("  I  ");-------
//  lcd.write(1);
//  lcd.print(" ARDUINO");
//  lcd.setCursor(0,1);
//  lcd.print("  I sleep ");
//  lcd.write(2);
//  lcd.write(3);
//  break;
  


case 0x1FE00FF://7 Button
    Serial.print("Button Pressed 7 Passing Text to LCD");
    lcd.begin();
   // lcd.print("Button Press 7"); // Button 2  
   // lcd.setCursor(0, 1);
    lcd.print("Robotics");
break;


case  0x1FEF00F://8 Button
    Serial.print("Button Pressed 8 Passing Text to LCD");
    lcd.begin();
//    lcd.print("Button Press 8"); // Button 2  
   // lcd.setCursor(0, 1);
    lcd.print("Soham Academy");
break;

//case 0x1FEF00F://8 Button
//    Serial.print("BLinking");
//    
//    lcd.begin();
//    
//    lcd.print("BLinking"); // Button 2  
//    lcd.setCursor(0, 1);
//    lcd.print("    Text    ");
//    lcd.noBlink();
//    delay(2000);
//    lcd.blink();
//  delay(2000);


//case 0x1FE9867://9 Button
//    Serial.print("Scroll");
//    
//    lcd.setCursor(15,0);
//  lcd.print("I LOVE");
//  delay(500);
//  for(i=0;i<20;i++)
//  {
//    lcd.scrollDisplayLeft();
//    delay(150);
//  }
//  lcd.clear();
//  lcd.setCursor(15,0);
//  lcd.print("ARDUINO");
//  delay(500);
//  for(i=0;i<22;i++)
//  {
//    lcd.scrollDisplayLeft();
//    delay(150);
//  }

case 0x1FE9867://9 Button
    Serial.print("Button Pressed 9 Passing Text to LCD");
    lcd.begin();
//    lcd.print("Button Press 9"); // Button 2  
    //lcd.setCursor(0, 1);
    lcd.print("Thank You");
break;
  lcd.clear();


break;
     default:
Serial.print("Undefined code received: 0x");
Serial.println(results.value, HEX);
lcd.begin();
    lcd.print("Undefined Button");
  lcd.setCursor(0, 1);
    lcd.print(results.value, HEX);
  break;
}
irrecv.resume();
}
}
