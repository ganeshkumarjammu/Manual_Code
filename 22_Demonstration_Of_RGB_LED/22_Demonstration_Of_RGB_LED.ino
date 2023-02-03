/*****************************************************
Project Title: Demonstration Of RGB LED
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
*******************************************************/

float now_r = 0, now_g = 0, now_b = 0;
float ran_r, ran_g, ran_b;

void setup() {

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  //random value is what we want to achieve
  //if current r value is bigger than random r value we have to decrement the value
  if(now_r > ran_r){
    now_r--;
    //if value is smaller we have to increment the value
  }else if(now_r < ran_r){
    now_r++;
  }else{
    //we bove values are qeual we have to set new random value
    ran_r = random(0, 255);
  }

  if(now_g > ran_g){
    now_g--;
  }else if(now_g < ran_g){
    now_g++;
  }else{
    ran_g = random(0, 255);
  }

  if(now_b > ran_b){
    now_b--;
  }else if(now_b < ran_b){
    now_b++;
  }else{
    ran_b = random(0, 255);
  }

  //here we are writing those values to pins with analogwrite because we use PWM
  analogWrite(11, now_r);
  analogWrite(10,now_g);
  analogWrite(9, now_b);
  //0.01 second of delay between each iteration, you can change it to make it faster or slower
  delay(5);
  

}
