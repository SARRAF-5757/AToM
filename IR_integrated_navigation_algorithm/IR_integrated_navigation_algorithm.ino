#include <Servo.h>

#define leftIR A2
#define rightIR A1

Servo leftWheel;
Servo rightWheel;

int leftReading;
int rightReading;

void setup() {
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  leftWheel.attach(10);
  rightWheel.attach(11);

  Serial.begin(9600);
}

void loop() {

  leftReading = digitalRead(leftIR);
  rightReading = digitalRead(rightIR);

  Serial.println(leftReading);
  Serial.println(rightReading);

  if (leftReading == LOW && rightReading == LOW) {
    leftWheel.write(87);
    rightWheel.write(87);
  }

  else if (leftReading == HIGH && rightReading == LOW) {
    leftWheel.write(87);
    rightWheel.write(90);
  }
  else if (leftReading == LOW && rightReading == HIGH) {
    leftWheel.write(90);
    rightWheel.write(87);
  }
  else {
    leftWheel.write(90);
    rightWheel.write(90);
  }
  
  delay(10);

}