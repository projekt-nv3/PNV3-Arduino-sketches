#include <Servo.h>

const int motorPin = 9;  // PWM pin connected to the ESC
Servo motor;

void setup() {
  Serial.begin(9600);
  motor.attach(motorPin);

  // Arm the ESC
  motor.writeMicroseconds(1000);
  delay(2000);
  motor.writeMicroseconds(0);
  delay(1000);
}

void loop() {

  delay(4000);
  motor.writeMicroseconds(1500);
  delay(4000);
  motor.writeMicroseconds(1000);
  delay(4000);
  motor.writeMicroseconds(1300);
  
}
