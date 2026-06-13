#include <Servo.h>

Servo myservo;

const int ldrLeft = A0;
const int ldrRight = A1;
const int servoPin = 9;

int pos = 90;

void setup()
{
  myservo.attach(servoPin);
  myservo.write(pos);
}

void loop()
{
  int leftValue = analogRead(ldrLeft);
  int rightValue = analogRead(ldrRight);

  int diff = rightValue - leftValue;   // Changed here

  if(diff > 30)
  {
    pos++;
    if(pos > 180) pos = 180;
    myservo.write(pos);
  }
  else if(diff < -30)
  {
    pos--;
    if(pos < 0) pos = 0;
    myservo.write(pos);
  }

  delay(20);
}
Explain this code vvvvv clearly in sinple words