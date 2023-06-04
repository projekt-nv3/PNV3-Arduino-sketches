#include <Servo.h>

Servo servo;  // create servo object to control a servo

void setup() {
  servo.attach(9);
  servo.write(90);
  delay(10000);
}

void loop() {
  // servo.write(40);
  // delay(2000);
  // servo.write(130);                 // sets the servo position according to the scaled value
  // delay(2000);  
}
