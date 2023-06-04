/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/


#include <Servo.h>

Servo servo;  // create servo object to control a servo

void setup() {
  servo.attach(8);
  servo.write(0);
  delay(2000);
}

void loop() {
  // servo.write(85);                 // sets the servo position according to the scaled value
  // // delay(1000);                           // waits for the servo to get there
  // servo.write(97);
  // delay(2000);
  // servo.write(72);                 // sets the servo position according to the scaled value
  // delay(2000);  

  servo.write(90);
  delay()
}
