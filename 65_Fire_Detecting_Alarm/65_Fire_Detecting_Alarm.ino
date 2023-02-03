/***********************************************************
  Project Title : Fire Detecting Alarm
  Organisation: Soham Academy Of Human Excellence
  Website: https://ria.sohamacademy.org/
***********************************************************/

const int buzzerPin = 11;
const int flamePin = 2;
int Flame = HIGH;
void setup()
{ pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin, INPUT);
  Serial.begin(9600);
} void loop() {
  Flame = digitalRead(flamePin);
  if (Flame == LOW) {
    Serial.println("Fire is Detected")
    ; digitalWrite(buzzerPin, HIGH);

  } else
  { Serial.println("No Fire is Detected");
    digitalWrite(buzzerPin, LOW);
  }
}
