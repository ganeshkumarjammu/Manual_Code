/*****************************************************
Project Title: Gaming Dice
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
*******************************************************/
int SegmentA = 8;
int SegmentB = 9;
int SegmentC = 3;
int SegmentD = 4;
int SegmentE = 5;
int SegmentF = 7;
int SegmentG = 6;
int i = 0;
//Dharmendra Kumar India
int Arduino_Pins[7] = {SegmentA, SegmentB, SegmentC, SegmentD, SegmentE, SegmentF, SegmentG};
int Segment_Pins[10][7] = {
   //{1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 0, 0, 0, 0},//1
  {1, 1, 0, 1, 1, 0, 1},//2  {1, 1, 1, 1, 0, 0, 1},//3
  {0, 1, 1, 0, 0, 1, 1},//4
  {1, 0, 1, 1, 0, 1, 1},//5
  {1, 0, 1, 1, 1, 1, 1},//6
//  {1, 1, 1, 0, 0, 0, 0},//7
//  {1, 1, 1, 1, 1, 1, 1},//8
//  {1, 1, 1, 1, 0, 1, 1},
  };//9

#define Push_Button A0
#define Buzzer 11
const unsigned int Beep = 900;

void setup() {
  pinMode(SegmentA, OUTPUT);
  pinMode(SegmentB, OUTPUT);
  pinMode(SegmentC, OUTPUT);
  pinMode(SegmentD, OUTPUT);
  pinMode(SegmentE, OUTPUT);
  pinMode(SegmentF, OUTPUT);
  pinMode(SegmentG, OUTPUT);

  pinMode(Push_Button, INPUT_PULLUP);
  pinMode(Buzzer, OUTPUT);

}

void loop() {

  int buttonState = digitalRead(Push_Button);
  if (buttonState == LOW) {
    rollTheDice(10, 100);
    rollTheDice(5, 200);
    rollTheDice(1, 100);
    //rollTheDice(1, 300);
    tone(Buzzer, Beep, 50);
  }
}

void rollTheDice(int count, int time) {
  for (int i = 0; i < count; i++) {
    int Segment_Pins = random(1, 7);
    tone(Buzzer, Beep, 50);
    Shownumbers(Segment_Pins);
    delay(time);
  }
}


void Shownumbers(int j) {

  for (j = 0; j < 7; j++)
  {
    digitalWrite(Arduino_Pins[j], Segment_Pins[i][j]);
  }

  {
    while (digitalRead(A0) == 0)
    {

    }
    i++;
  }
  if (i == 7)
  {
    i = 0;
  }
  delay(20);
}
