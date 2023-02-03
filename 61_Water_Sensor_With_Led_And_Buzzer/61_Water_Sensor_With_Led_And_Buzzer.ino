
/*****************************************************
Project Title: Water Sensor With LED and Buzzer
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
*******************************************************/

/********************************
  name: Water level sensor module with Arduino Uno, LEDs,
  piezo buzzer
  function: Measuring water level and sending
  status about the water level to serial monitor and LEDs.
  If water level is between:
  10-15mm the green LED will be on
  20-25mm the blue LED will be on
  35-40mm the red LED will be on
  35-40mm the piezo buzzer will be activated too
  and
  switch off when sensor is out of water and dry.
********************************/
//Email:info@acoptex.com
//Website:www.acoptex.com
/********************************/
// include libraries
// no libraries required
/********************************/
int sensorPin = A1;  // select the input pin (must be analog) for the water level sensor module
//int GreenPin = 8;      // select the pin for the green LED
//int BluePin = 7;      // select the pin for the blue LED
int RedPin = 5;      // select the pin for the red LED
int sensorValue = 0; // variable to store the value coming from the sensor
int speakerPin = A0;  // select the pin for the piezo buzzer
/********************************/
void setup() {
  Serial.begin(9600); // initialize serial communications at 9600 bps
  //pinMode(GreenPin, OUTPUT);  // declare the GreenPin as an OUTPUT
  //pinMode(BluePin, OUTPUT);  // declare the BluePin as an OUTPUT
  pinMode(RedPin, OUTPUT);  // declare the RedPin as an OUTPUT
  pinMode(speakerPin, OUTPUT); // declare the speakerPin as an OUTPUT
 }

void loop() {

  sensorValue = analogRead(sensorPin); // read the value from the sensor
  // send the message about water level to serial monitor

  if (sensorValue <= 0) {
    Serial.println("Water level: 0mm - Empty!");
  }
  else if (sensorValue > 0 && sensorValue <= 223) {
    Serial.println("Water lvl:0-5mm");

  }
  else if (sensorValue > 223 && sensorValue <= 251) {
    Serial.println("Water lvl: 5-10mm");
  }
  else if (sensorValue > 251 && sensorValue <= 277) {
    Serial.println("Water lvl: 10-15mm");
    //digitalWrite(GreenPin, HIGH);  // turn the green LED on  
  }
  else if (sensorValue > 277 && sensorValue <= 294) {
    Serial.println("Water lvl: 15-20mm");
  }
  else if (sensorValue > 294 && sensorValue <= 311) {
    Serial.println("Water lvl: 20-25mm");
    //digitalWrite(BluePin, HIGH);  // turn the blue LED on   
  }
  else if (sensorValue > 311 && sensorValue <= 314) {
    Serial.println("Water lvl: 25-30mm");
  }
  else if (sensorValue > 314 && sensorValue <= 323) {
    Serial.println("Water lvl: 30-35mm");
  }
  else if (sensorValue > 323) {
    digitalWrite(speakerPin, HIGH); // turn the piezo buzzer on
    digitalWrite(RedPin, HIGH);  // turn the red LED on
    Serial.println("Water lvl: 35-40mm - Alarm! Alarm!");
    }
  delay(1000); // delay 1 second
  //digitalWrite(GreenPin, LOW);// turn the green LED off
  //digitalWrite(BluePin, LOW);// turn the blue LED off
  digitalWrite(RedPin, LOW);// turn the red LED off
  digitalWrite(speakerPin, LOW);// turn the speakerPin off - reset
  // the system when sensor out off the water and dry

}
