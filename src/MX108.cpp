#include "MX108.h"
#include <Arduino.h>

MX108::MX108(int pinA,int pinB)
{
  this->pinA = pinA;
  this->pinB = pinB;

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
}

MX108::MX108(int pinA, int pinB, int pinC, int pinD)
{
  this->pinA = pinA;
  this->pinB = pinB;
  this->pinC = pinC;
  this->pinD = pinD;

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
}

void MX108::DriveMotor(int motor, int direction, float speed)
{
  speed = constrain(speed, 0, 100);
  int pwm = (int)(255.0 * speed / 100.0);

  int a, b;
  if (motor == 1) {
    a = pinA;
    b = pinB;
  } else if (motor == 2){
    a = pinC;
    b = pinD;
  }
  else 
  {
    return;
  }

  switch (direction) {
    case -1:
      digitalWrite(a, LOW);
      analogWrite(b, pwm);
      break;
    case 0:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      break;
    case 1:
      digitalWrite(b, LOW);
      analogWrite(a, pwm);
      break;
    default:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;
  }
}