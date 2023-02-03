#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include "NewTone.h"
#include <avr/io.h>
#include <avr/wdt.h>

#define Reset_AVR() wdt_enable(WDTO_30MS); while(1) {} 


#define buzzer 11     

LiquidCrystal_I2C lcd(0x27,16,2);

int result;
int RECV_PIN=2;

IRrecv irrecv(RECV_PIN);

decode_results results;
  
void setup() {   
  Serial.begin(9600);               
  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print("-----Choose-----");
  lcd.setCursor(0,1);
  lcd.print("----A Song!!----");
  pinMode(buzzer, OUTPUT);
  irrecv.enableIRIn();
}  

void loop() {
  if (irrecv.decode(&results)) {
    result=results.value, HEX;
    Serial.println(result);
    if (result==12495) {
      ode();
    }
    else if (result==20655) {
      london();
    }
    else if (result==-10201) {
      fur();
    }
    else if (result==-2041) {
      pirate();
    }
    irrecv.resume();
  }
  delay(100);
} 

void fur() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fur Elise");
  delay(1000);
  lcd.clear();
  nota_mi(150,200);
  nota_rez(150,200);
  nota_mi(150,200);
  nota_rez(150,200);
  nota_mi(150,200);
  nota_si(150,200);
  nota_rez(150,200);
  nota_do(150,200);
  nota_la(450,300);
  nota_do(150,200);
  nota_mi(150,200);
  nota_la(150,200);
  nota_si(450,300);
  nota_mi(150,200);
  nota_solz(150,200);
  nota_si(150,200);
  nota_do(450,300);
  nota_mi(150,200);
  nota_mi(150,200);
  nota_rez(150,200);
  nota_mi(150,200);
  nota_rez(150,200);
  nota_mi(150,200);
  nota_si(150,200);
  nota_rez(150,200);
  nota_do(150,200);
  nota_la(450,300);
  nota_do(150,200);
  nota_mi(150,200);
  nota_la(150,200);
  nota_sol(450,300);
  nota_mi(150,200);
  nota_do(150,200);
  nota_si(150,200);
  nota_la(600,800);
  nota_mi(150,200);
  nota_rez(150,200);
  nota_mi(150,200);
  nota_rez(150,200);
  nota_mi(150,200);
  nota_si(150,200);
  nota_rez(150,200);
  nota_do(150,200);
  nota_la(450,300);
  nota_do(150,200);
  nota_mi(150,200);
  nota_la(150,200);
  nota_si(450,300);
  nota_mi(150,200);
  nota_solz(150,200);
  nota_si(150,200);
  nota_do(450,300);
  lcd.clear();
  delay(100);
  Reset_AVR();
}

void london() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("London Bridge");
  lcd.setCursor(0,1);
  lcd.print("Is falling down");
  delay(1000);
  lcd.clear();
  nota_sol(450,600);
  nota_la(150,200);
  nota_sol(300,400);
  nota_fa(300,400);
  nota_mi(300,400);
  nota_fa(300,400);
  nota_sol(600,800);
  nota_re(300,400);
  nota_mi(300,400);
  nota_fa(600,800);
  nota_mi(300,400);
  nota_fa(300,400);
  nota_sol(600,800);
  nota_sol(450,600);
  nota_la(150,200);
  nota_sol(300,400);
  nota_fa(300,400);
  nota_mi(300,400);
  nota_fa(300,400);
  nota_sol(600,800);
  nota_re(600,800);
  nota_sol(600,800);
  nota_mi(300,400);
  nota_do(450,600);
  lcd.clear();
  delay(100);
  Reset_AVR();
}

void ode() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ode to Joy");
  delay(1000);
  lcd.clear();
  nota_mi(300,400);
  nota_mi(300,400);
  nota_fa(300,400);
  nota_sol(300,400);
  nota_sol(300,400);
  nota_fa(300,400);
  nota_mi(300,400);
  nota_re(300,400);
  nota_do(300,400);
  nota_do(300,400);
  nota_re(300,400);
  nota_mi(300,400);
  nota_mi(450,600);
  nota_re(150,200);
  nota_re(600,800);
  nota_mi(300,400);
  nota_mi(300,400);
  nota_fa(300,400);
  nota_sol(300,400);
  nota_sol(300,400);
  nota_fa(300,400);
  nota_mi(300,400);
  nota_re(300,400);
  nota_do(300,400);
  nota_do(300,400);
  nota_re(300,400);
  nota_mi(300,400);
  nota_re(450,600);
  nota_do(150,200);
  nota_do(600,800);
  nota_re(300,400);
  nota_re(300,400);
  nota_mi(300,400);
  nota_do(300,400);
  nota_re(300,400);
  nota_mi(150,200);
  nota_fa(150,200);
  nota_mi(300,400);
  nota_do(300,400);
  nota_re(300,400);
  nota_mi(150,200);
  nota_fa(150,200);
  nota_mi(300,400);
  nota_re(300,400);
  nota_do(300,400);
  nota_re(300,400);
  nota_sol(600,800);
  nota_mi(300,400);
  nota_mi(300,400);
  nota_fa(300,400);
  nota_sol(300,400);
  nota_sol(300,400);
  nota_fa(300,400);
  nota_mi(300,400);
  nota_re(300,400);
  nota_do(300,400);
  nota_do(300,400);
  nota_re(300,400);
  nota_mi(300,400);
  nota_re(450,600);
  nota_do(150,200);
  nota_do(600,800);
  lcd.clear();
  delay(100);
  Reset_AVR();
}

void pirate() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("He's a Pirate");
  delay(1000);
  lcd.clear();
  nota_mi(150,200);
  nota_sol(150,200);
  nota_la(300,400);
  nota_la(300,400);
  nota_la(150,200);
  nota_si(150,200);
  nota_do(300,400);
  nota_do(300,400);
  nota_do(150,200);
  nota_re(150,200);
  nota_si(300,400);
  nota_si(300,400);
  nota_la(150,200);
  nota_sol(150,200);
  nota_sol(150,200);
  nota_la(450,600);
  nota_mi(150,200);
  nota_sol(150,200);
  nota_la(300,400);
  nota_la(300,400);
  nota_la(150,200);
  nota_si(150,200);
  nota_do(300,400);
  nota_do(300,400);
  nota_do(150,200);
  nota_re(150,200);
  nota_si(300,400);
  nota_si(300,400);
  nota_la(150,200);
  nota_sol(150,200);
  nota_la(300,400);
  delay(400);
  nota_mi(150,200);
  nota_sol(150,200);
  nota_la(300,400);
  nota_la(300,400);
  nota_la(150,200);
  nota_do(150,200);
  nota_re(300,400);
  nota_re(300,400);
  nota_re(150,200);
  nota_mi(150,200);
  nota_fa(300,400);
  nota_fa(300,400);
  nota_mi(150,200);
  nota_re(150,200);
  nota_mi(150,200);
  nota_la(450,600);
  nota_la(150,200);
  nota_si(150,200);
  nota_do(300,400);
  nota_do(300,400);
  nota_re(300,400);
  nota_mi(150,200);
  nota_la(450,600);
  nota_la(150,200);
  nota_do(150,200);  
  nota_si(300,400);
  nota_si(300,400);
  nota_do(150,200);
  nota_la(150,200);
  nota_si(900,1200);
  nota_si(300,400);
  nota_si(300,400);
  nota_do(150,200);
  nota_la(150,200);
  nota_si(900,1200);
  nota_si(300,400);
  nota_si(300,400);
  nota_la(150,200);
  nota_sol(150,200);
  nota_la(600,800);
  lcd.clear();
  delay(100);
  Reset_AVR();
}

void shut() {
  if (irrecv.decode(&results)) {
    result=results.value, HEX;
    Serial.println(result);
    if (result==-23971) {
      Reset_AVR();
    }
  }
  irrecv.resume();
}

void nota_do(int duration, int pause) {
  shut();
  lcd.setCursor(0, 0);
  lcd.print("Do    ");
  NewTone(11,262,duration); //DO
  delay(pause);
  }

void nota_doz(int duration, int pause) {
  shut();
  lcd.setCursor(0, 0);
  lcd.print("Do #  ");
  NewTone(11,277,duration); //DO
  delay(pause);
  }

void nota_re(int duration, int pause) {
  shut;
  lcd.setCursor(0, 0);
  lcd.print("Re    ");
  NewTone(11,294,duration); //RE
  delay(pause);
  }

void nota_rez(int duration, int pause) {
  shut;
  lcd.setCursor(0, 0);
  lcd.print("Re #  ");
  NewTone(11,311,duration); //RE
  delay(pause);
  }

void nota_mi(int duration, int pause) {
  shut();
  lcd.setCursor(0, 0);
  lcd.print("Mi    ");
  NewTone(11,330,duration); //MI
  delay(pause);
  }

void nota_fa(int duration, int pause) {
  shut();
  lcd.setCursor(0, 0);
  lcd.print("Fa    ");
  NewTone(11,349,duration); //FA
  delay(pause);
  }

void nota_faz(int duration, int pause) {
  shut();
  lcd.setCursor(0, 0);
  lcd.print("Fa #  ");
  NewTone(11,370,duration); //FA
  delay(pause);
  }


void nota_sol(int duration, int pause) {
  shut();
  lcd.setCursor(0, 0);
  lcd.print("Sol   ");
  NewTone(11,392,duration); //SOL
  delay(pause);
  }

void nota_solz(int duration, int pause) {
  shut();
  lcd.setCursor(0, 0);
  lcd.print("Sol # ");
  NewTone(11,415,duration); //SOL
  delay(pause);
  }

void nota_la(int duration, int pause) {
  shut();
  lcd.setCursor(0, 0);
  lcd.print("La    ");
  NewTone(11,440,duration); //LA
  delay(pause);
  } 

void nota_laz(int duration, int pause) {
  shut();
  lcd.setCursor(0, 0);
  lcd.print("La #  ");
  NewTone(11,466,duration); //LA
  delay(pause);
  }

void nota_si(int duration, int pause) {
  shut();
  lcd.setCursor(0, 0);
  lcd.print("Si    ");
  NewTone(11,494,duration); //SI
  delay(pause);
  }
