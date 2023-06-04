#include <Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:4
  Serial.begin(9600);
  servo.attach(8);  // attaches the servo on pin 9 to the servo object
  servo.write(90);
  delay(2000);
  while(!Serial){

  }
}
const char TERMINATOR = '|';

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    // String commandFromJetson = Serial.readStringUntil(TERMINATOR);
    // String msg = "Message from jetson  " + commandFromJetson;
    String msg = Serial.readString();
    // String msg = commandFromJetson;
    int num;
    num = msg.toInt();
    Serial.print(num);

    servo.write(num);
    delay(1000);
    // servo.write(0);
    // delay(1000);
  }
  delay(1000);

}