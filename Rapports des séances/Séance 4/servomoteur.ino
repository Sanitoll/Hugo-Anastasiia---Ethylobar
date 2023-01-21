#include <Servo.h>;
Servo servo1;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(4);
  servo1.write(0);
}
void loop() {
  for (int position=0; position <=180; position++){
    servo1.write(position);
    delay(15);
  }

  for (int position=180; position>=0; position --){
    servo1.write(position);
    delay(15);
  }
}
