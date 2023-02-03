/*****************************************************
Project Title: Automatic_Bed_Light
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
*******************************************************/

#define LDR A0 //Light dependent resisotr (LDR) connected to analog pin A2 
#define LED 5 //LED connected to digital pin 5
int LDR_value; //variable to store result value read by LDR

void setup()
{
Serial.begin(9600); //intialize the serial port for communicaion
pinMode(LED, OUTPUT); // set LED as output
pinMode(LDR, INPUT); //set light dependent resistor as input
}

void loop()
{
 LDR_value=analogRead(LDR); //read the data from analog pin A2 and store in LDR_value
 Serial.print("LDR value is: ");
 Serial.println(LDR_value);
if (LDR_value <= 30) //if LDR_value value is less than or equal to 300 that means its dark outside so LED should be turn on
{   
   digitalWrite(LED, HIGH);//turn on the LED
  Serial.println("its dark turn on the LED");// display "its dark turn on the LED" on serial monitor and set the cursor to the new line
  Serial.println("LDR value:"); //display "LDR value:" on serial monitor and set the cursor to the new line
  Serial.println(LDR_value); // print the value of sensor
 delay(200); 
}
else //if LDR_value value is greater than 300 that means its bright outside so LED should be turn off
{
    digitalWrite(LED, LOW); //turn off the LED
    Serial.println("its bright turn off the LED"); // display "its bright turn off the LED" on serial monitor and set the cursor to the new line
    Serial.println("LDR value:"); //display "LDR value:" on serial monitor and set the cursor to the new line
    Serial.println(LDR_value); // print the value of sensor
}
delay(200); 
}
