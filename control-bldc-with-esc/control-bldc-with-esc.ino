// #include<Servo.h>
// // Servo ser;
// Servo esc;
// void setup() {
//   // ser.attach(11);
//   // ser.write(90);
//   esc.attach(9);  // Attach the ESC control signal to the specified pin
//   delay(2000);  // Delay to ensure stability

//   // Send the maximum throttle signal
//   esc.writeMicroseconds(1100);
//   delay(2000);  // Delay to allow the ESC to recognize the maximum signal

//   // Send the minimum throttle signal
//   esc.writeMicroseconds(1000);
//   delay(2000);  // Delay to allow the ESC to recognize the minimum signal

//   // Send the stop signal
//   esc.writeMicroseconds(1000);
//   delay(2000);  // Delay for stability

//   // Calibration complete
// }

// void loop() {
//   // esc.writeMicroseconds(1040);
//   // delay(2000);
//   for(int i=1000;i<1400;i++){
//     esc.writeMicroseconds(i);
//     delay(100);
//   }
// }



#include <Servo.h>

Servo esc;   // Create a servo object
Servo ser;
void setup() {
  Serial.begin(9600);
  ser.attach(11);
  esc.attach(9);   // Attach the ESC signal wire to Arduino pin 9
  delay(2000);     // Delay for 2 seconds before calibration
  // esc.writeMicroseconds(1200);  // Send maximum throttle signal
  // delay(2000);     // Delay for 2 seconds
  // esc.writeMicroseconds(1000);  // Send minimum throttle signal
  // delay(2000);     // Delay for 2 seconds
  ser.write(90);
  esc.writeMicroseconds(1000);  // Send neutral throttle signal
  delay(2000);
}

void loop() {
  // Other code or actions can be performed here
  // for(int i=1000;i<1100;i++){
  //   esc.writeMicroseconds(i);
  //   delay(100);
  //   Serial.println(i);
  // }
  // for(int j=1100;j>1000;j--){
  //   esc.writeMicroseconds(j);
  //   delay(100);
  // }
  for(int i=1200;i<1600;i++){
    esc.writeMicroseconds(i);
    delay(100);
    Serial.println(i);
  }
  for(int j=1600;j>1200;j--){
    esc.writeMicroseconds(j);
    delay(100);
  }
  
  delay(2000);
}
