
//ARDUINO LINE FOLLOWING CAR//
 
//including the libraries
#include <AFMotor.h>

//defining pins and variables
#define left A0
#define right A1

//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);



void setup() {
  //declaring pin types
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  //begin serial communication
  Serial.begin(9600);

}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.println(digitalRead(left));

  Serial.println(digitalRead(right));


  //line detected by both
  if(digitalRead(left)==0 && digitalRead(right)==0){
    //Forward
    motor1.run(FORWARD);
    motor1.setSpeed(250);
    motor2.run(FORWARD);
    motor2.setSpeed(250);
    motor3.run(FORWARD);
    motor3.setSpeed(250);
    motor4.run(FORWARD);
    motor4.setSpeed(250);
  }
  // //line detected by left sensor
  else if(digitalRead(left)==0 && !digitalRead(right)==0){
    //turn left
    motor1.run(FORWARD);
    motor1.setSpeed(550);
    motor2.run(FORWARD);
    motor2.setSpeed(550);
    motor3.run(BACKWARD);
    motor3.setSpeed(550);
    motor4.run(BACKWARD);
    motor4.setSpeed(550);

  }

  //line detected by right sensor
  else if(!digitalRead(left)==0 && digitalRead(right)==0){
    //turn right
    motor1.run(BACKWARD);
    motor1.setSpeed(250);
    motor2.run(BACKWARD);
    motor2.setSpeed(250);
    motor3.run(FORWARD);
    motor3.setSpeed(250);
    motor4.run(FORWARD);
    motor4.setSpeed(250);

  }
  

  // we did not implement a stopping fuction.
  // instead we created a physical stopping point with a piece of tape

}
