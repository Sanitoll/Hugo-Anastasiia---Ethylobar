#include <Servo.h>;
Servo servo1;
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

int boisson1 = 1;
int boisson2 = 2;
int boisson3 = 3;
int boisson4 = 4;
int boisson5 = 5;
int boisson6 = 6;
int boisson7 = 7;
int boisson8 = 8;
int Boisson=0;

bool promptDone = false;


int temps =3;
int pause =2000;
int i=0; //variable du nombre de pas


void setup(){
Serial.begin(9600);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
servo1.attach(4);
servo1.write(0);
}

void bouge(int degres, bool aller){  
    int pas = 34;
    for (int i = 0; i < degres*pas  ; i++)
    {
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
      if(aller)
      {
        digitalWrite(IN1, LOW);
        digitalWrite(IN4, HIGH);
      } else 
      {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN4, LOW);
      }

      delay(temps);

        digitalWrite(IN1, LOW);
        digitalWrite(IN4, LOW);
      if(aller)
      {
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
      }else
      {
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
      }
      
      delay(temps);  
      
        digitalWrite(IN1, LOW);
        digitalWrite(IN4, LOW);
      if (aller)
      {
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
      }else
      {
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
      }
      
      delay(temps);

        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
      if(aller)
      {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN4, LOW);
      }else
      {
        digitalWrite(IN1, LOW);
        digitalWrite(IN4, HIGH);
      }

      delay(temps);            
   }
}

void Servir(){ //pour un verre sans mélange 
  delay(2000);
  servo1.write(90);
  delay(4000);
  servo1.write(0);  
}

void Servir1(){ //pour un verre sans mélange 
  delay(2000);
  servo1.write(90);
  delay(5000);
  servo1.write(0);  
}

void loop() { 
  if(!promptDone) 
    {
      Serial.println("Choisissez une boisson: ");
      Serial.println("Boisson 1: ...");
      Serial.println("Boisson 2: ...");
      Serial.println("Boisson 3: ...");
      Serial.println("Boisson 4: ...");
      Serial.println("Boisson 5: ...");
      Serial.println("Boisson 6: ...");
      Serial.println("Boisson 7: ... et ...");
      Serial.println("Boisson 8: ... et ...");
      promptDone = true;    
    }
        
    Boisson = Serial.read();
    
    if (Boisson == '1'){
      Servir();
      delay(4000);
      Servir();
      Serial.println("boisson1 est servie");
      promptDone = false;
    }

    if (Boisson == '2'){
      bouge(15, true);
      Servir();
      delay(4000);
      Servir();
      delay(4000);
      Servir();
      delay(4000);
      Servir();
      delay(500);
      bouge(15, false);
      Serial.println("boisson2 est servie");
      promptDone = false;
    }
        
    if (Boisson == '3'){
      bouge(30, true);
      Servir1();
      delay(4000);
      Servir1();
      delay(4000);
      Servir1();
      delay(4000);
      Servir1();
      delay(500);
      bouge(30, false);
      Serial.println("boisson3 est servie");
      promptDone = false;
    }

    if(Boisson == '4') {
      bouge(15, false);
      Servir();
      delay(4000);
      Servir();
      delay(4000);
      Servir();
      delay(4000);
      Servir();
      delay(500);
      bouge(15, true);
      Serial.println("boisson4 est servie");
      promptDone = false;   
    }

    if (Boisson == '5') {
      bouge(30, false);
      Servir1();
      delay(4000);
      Servir1();
      delay(4000);
      Servir1();
      delay(4000);
      Servir1();
      delay(500);
      bouge(30, true);
      Serial.println("boisson5 est servie");
      promptDone = false;
    }

    if (Boisson == '6') {
      bouge(45, false);
      Servir();
      delay(4000);
      Servir();
      delay(4000);
      Servir();
      delay(4000);
      Servir();
      delay(500);
      bouge(45, true);
      Serial.println("boisson6 est servie");
      promptDone = false;
    }

    if (Boisson == '7') { //melange 2 et 5
      bouge(15,true);
      Servir();
      delay(4000);
      Servir();
      delay(500);
      bouge(45,false);
      Servir();
      delay(4000);
      Servir();
      delay(500);
      bouge(30,true);
      Serial.println("boisson7 est servie");
      promptDone = false;
    }
        
    if (Boisson == '8') { //melange 3 et 6
      bouge(30,true);
      Servir1();
      delay(4000);
      Servir1();
      delay(500);
      bouge(15,true);
      Servir();
      delay(4000);
      Servir();
      delay(500);
      bouge(45,false);
      Serial.println("boisson8 est servie");
      promptDone = false;
    }
}