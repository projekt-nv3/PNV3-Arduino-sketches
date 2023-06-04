#include <Servo.h>
#define NO_BREAK 145
#define BREAK 95


Servo servo;
// int angle = 180;

void setup() {
  servo.attach(11);
  servo.write(NO_BREAK);
  delay(2000);
}

void loop() 
{ 
    // now scan back from 180 to 0 degrees
  for(int angle = NO_BREAK; angle > BREAK; angle-=10)    
  {                                
    servo.write(angle);           
    delay(100);       
  } 
  delay(2000);
 // scan from 0 to 180 degrees
  for(int angle = BREAK; angle < NO_BREAK; angle+=10)  
  {                                  
    servo.write(angle);               
    delay(100);                   
  } 

}