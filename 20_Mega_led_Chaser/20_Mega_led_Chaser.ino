/*********************************************************** 
Project Title : Mega LED Chaser
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
***********************************************************/

void setup() 
{
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
}

void loop()
{
int i; 


// 1st pattern repeat 1 times  
     
     for(i=1; i<=10; i++)                           
     {
      digitalWrite(i,HIGH); 
      delay(50);
      digitalWrite(i,LOW); 
      delay(50);
     }
         
     for(i=10; i>=1; i--)
     {
      digitalWrite(i,HIGH); 
      delay(50);
      digitalWrite(i,LOW); 
      delay(50);
     }
     delay(1000);


//2nd pattern repeat 1 times 

    for(i=1; i<=10 ; i++)
    {
     digitalWrite(i,HIGH);  
     delay(50);
    }
 
    for(i=1; i<=10 ; i++)
    {
     digitalWrite(i,LOW); 
     delay(50);
    }
    
    
    for(i=10; i>=1 ; i--)
    {
     digitalWrite(i,HIGH);  
     delay(50);
    }
 
    for(i=10; i>=1 ; i--)
    {
     digitalWrite(i,LOW); 
     delay(50);
    }
    delay(1000);

//3rd pattern repeat 1 times

    for(i=1; i<=10 ; i++)
    {
     digitalWrite(i,HIGH);  
     delay(50);
    }
    for(i=11; i>=1 ; i--)
    {
     digitalWrite(i,LOW); 
     delay(50);
    }
    
    for(i=10; i>=1 ; i--)
    {
     digitalWrite(i,HIGH);  
     delay(50);
    }
    for(i=1; i<=10 ; i++)
    {
     digitalWrite(i,LOW); 
     delay(50);
    }
    delay(1000);




    
//4th pattern repeat 1 times

    for(i=1; i<=5 ; i++)
    {
     digitalWrite(i,HIGH);  
     digitalWrite(11-i,HIGH);
     delay(100);
    }
    for(i=1; i<=5 ; i++)
    {
     digitalWrite(i,LOW);  
     digitalWrite(11-i,LOW);
     delay(100);
    }
    delay(100);
    for(i=1; i<=5 ; i++)
    {
     digitalWrite(i,HIGH);  
     digitalWrite(11-i,HIGH);
     delay(100);
    }
    for(i=5; i>=1 ; i--)
    {
     digitalWrite(i,LOW);  
     digitalWrite(11-i,LOW);
     delay(100);
    }
    delay(1000);
    
//5th pattern rpeat 1 time    
    
    for(i=1 ; i<=3 ; i++)
     {
      digitalWrite(i,HIGH); 
      digitalWrite(i+3,HIGH); 
      digitalWrite(i+6,HIGH); 
      delay(500/i);
     }
     delay(500);
    
    for(i=1 ; i<=3 ; i++)
     {
      digitalWrite(i,LOW); 
      digitalWrite(i+3,LOW);
      digitalWrite(i+6,LOW); 
      delay(500/i);
     }

    delay(1000);




}
