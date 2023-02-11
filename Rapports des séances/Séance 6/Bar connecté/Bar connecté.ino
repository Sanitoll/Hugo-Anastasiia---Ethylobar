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
int test=0;

int temps =3;
int pause =2000;
int i=0; //variable du nombre de pas


void setup(){
Serial.begin(115200);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
servo1.attach(4);
servo1.write(0);
}


void Tourne15(){  //fonction qui fait tourner (en théorie) le gros engrenage de 15°
for (i=0; i < 512; i++){
Serial.println(i);
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
delay(temps);
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
delay(temps);
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
delay(temps);
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
delay(temps); }}


void Tourne30(){  //Fonction qui fait tourner le gros engrenage de 30°
  Tourne15();
  Tourne15();
}

void Servir1(){ //pour un vers sans mélange 
  servo1.write(90);
  delay(4000);
  servo1.write(0);  
}
void Servir2(){ //pour un melange de deux boissons
  servo1.write(90);
  delay(2000);
  servo1.write(0);
}

void loop() { 
  Serial.print("Saisir une valeur entre 1 et 6");

  if (1){
    Tourne15();
    servir();
  }
  Serial.print("boisson1 est servie");
  if (2){
    Tourne30();
    Servir();
  }
  if (3){
    Tourne30();
    Tourne15();
    Servir();
  }
  if(4) {
    Tourne30();
    Tourne30();
    Servir();    
  }
  if (5) {
    Tourne30();
    Tourne30();
    Tourne15();
    Servir();
  }
  if (6) {
    Tourne30();
    Tourne30();
    Tourne30();
    Servir();
  }


}





