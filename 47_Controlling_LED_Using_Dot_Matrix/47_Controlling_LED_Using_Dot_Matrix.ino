/*****************************************************
Project Title: Controlling LED Using Dot Matrix
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
*******************************************************/
#include <LedControl.h> 
int UD = 0;
int LR = 0; 

LedControl lc=LedControl(12,11,10,1); //Din = 8, 10 = CLOCK, 9 = CS
void setup() {
 Serial.begin(9600);
 lc.shutdown(0,false); // turn off power saving, enables display
 lc.setIntensity(0,8); // sets brightness (0~15 possible values)
 lc.clearDisplay(0); // clear screen
}
void loop()
{
 LR = analogRead(A2); // VRX - A1
 UD = analogRead(A3); // VRY - A0
 char x_translate = map(LR, 1021, 0, 7, 0); 
 char y_translate = map(UD, 1021, 0, 0, 7);

 Serial.print("UD = ");
 Serial.print(UD, DEC);
 Serial.print(", LR = ");
 Serial.print(LR, DEC);
 Serial.print(", x = ");
 Serial.print(x_translate, DEC);
 Serial.print(", y = ");
 Serial.println(y_translate, DEC);
 // not in shutdown mode
 lc.clearDisplay(0);
 lc.setLed(0,x_translate,y_translate,true);
 delay(150); //adjust delay to get your joystick correct//
}
