// #include <Wire.h>
// #include <Adafruit_PWMServoDriver.h>

// // Initialize the PCA9685 module
// Adafruit_PWMServoDriver pwm;

// // Servo motor parameters
// const uint8_t servoChannel = 6;   // Channel connected to the servo motor
// const uint16_t servoMin = 150;    // Minimum pulse width (corresponding to 0 degrees)150
// const uint16_t servoMax = 600;    // Maximum pulse width (corresponding to 180 degrees)600

// void setup() {
//   // Initialize communication with the PCA9685 module
//   Wire.begin();
//   pwm.begin();
//   pwm.setOscillatorFrequency(27000000);  // Set the PWM frequency (default is 25MHz)

//   // Optionally, you can set the frequency and resolution of the PWM output
//   // pwm.setPWMFreq(50);  // Set the PWM frequency to 50Hz (default is 1000Hz)
//   // pwm.setPWMResolution(12);  // Set the PWM resolution to 12 bits (default is 16 bits)

//   // Set the initial position of the servo motor to the middle position
//   setPosition(90);  // Set to 90 degrees (or adjust as desired)
// }

// void loop() {
//   // Move the servo motor to different positions
//   setPosition(90);     // Move to 0 degrees
//   delay(2000);        // Delay for 2 seconds
//   setPosition(40);    // Move to 90 degrees
//   delay(2000);        // Delay for 2 seconds
//   setPosition(130);   // Move to 180 degrees
//   delay(2000);        // Delay for 2 seconds
// }

// // Function to set the position of the servo motor
// void setPosition(uint16_t position) {
//   uint16_t pulseWidth = map(position, 0, 180, servoMin, servoMax);
//   pwm.setPWM(servoChannel, 0, pulseWidth);
// }


#include "HCPCA9685.h"
 
/* I2C slave address for the device/module. For the HCMODU0097 the default I2C address
 
is 0x40 */
 
#define  I2CAdd 0x40
 
/* Create an instance of the library */
 
HCPCA9685 HCPCA9685(I2CAdd);
 
void setup()
 
{
 
  /* Initialise the library and set it to 'servo mode' */
 
HCPCA9685.Init(SERVO_MODE);
 
  /* Wake the device up */
 
HCPCA9685.Sleep(false);
 
}
 
void loop()
 
{
 
unsigned int Pos;
 
  /* Sweep the servo back and forth from its minimum to maximum position. If your servo is hitting its end stops then you should adjust the values so that the servo can sweep though its full range without hitting the end stops. You can adjust the min & max positions by altering the trim values in the libraries HCPCA9685.h file*/
 
for(Pos = 10; Pos< 450; Pos++)
 
  {
 
    /* This function sets the servos position. It takes two parameters,
 
     * the first is the servo to control, and the second is the servo
 
     * position. */
 
HCPCA9685.Servo(3, Pos);
 
HCPCA9685.Servo(8, Pos);
 
delay(10);
 
  }
 
for(Pos = 450; Pos>= 10; Pos--)
 
  {
 
HCPCA9685.Servo(3, Pos);
 
HCPCA9685.Servo(8, Pos);
 
delay(10);
 
  }
 
}