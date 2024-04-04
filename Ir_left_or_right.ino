#include <Servo.h>

Servo leftMotor;
Servo rightMotor;

unsigned long start_time;

void setup() {
  leftMotor.attach(10);
  rightMotor.attach(11);

  start_time = millis();
}

void driveFwd(){
  leftMotor.writeMicroseconds(2000);
  rightMotor.writeMicroseconds(2000);
}

void driveBackwards(){
  leftMotor.writeMicroseconds(1000);
  rightMotor.writeMicroseconds(1000);
  delay(5000);
}


void stop(){
  leftMotor.writeMicroseconds(1500);
  rightMotor.writeMicroseconds(1500);
}

void spin(){
  leftMotor.writeMicroseconds(1000);
  rightMotor.writeMicroseconds(1000);
}

void turnLeft(){
  leftMotor.writeMicroseconds(1500);
  rightMotor.writeMicroseconds(2000);
}

// void turnRight(){
//   leftMotor.writeMicroseconds(2000);
//   rightMotor.writeMicroseconds(1500);
// }

int curTime = millis();

void loop() {
  while (millis() - curTime < 1000) {
    turnLeft();
  }
  while (1000 <= millis() - curTime && millis() - curTime < 2000) {
    stop();
  }
  while (2000 <= millis() - curTime && millis() - curTime < 5000) {
    driveFwd();
  }
  while(millis() - curTime >= 5000) {
    curTime = millis();
  }
}