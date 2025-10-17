#include <MX108.h>

/*
  Single Motor Example for MX108 Library

  This sketch demonstrates controlling a single DC motor using
  the MX108 library. It cycles the motor through forward, reverse,
  stop, and brake modes with different speeds.

  Hardware:
  - Motor connected to MX108 driver
  - Driver inputs connected to Arduino pins 5 and 6
*/

MX108 motor(5, 6); // Initialize motor with pins A=5, B=6

void setup() {
  Serial.begin(9600);
  Serial.println("MX108 Single Motor Example");
}

void loop() {
  Serial.println("Forward 80%");
  motor.DriveMotor(1, 1, 80); // Motor forward at 80% speed
  delay(2000);

  Serial.println("Reverse 50%");
  motor.DriveMotor(1, -1, 50); // Motor reverse at 50% speed
  delay(2000);

  Serial.println("Stop motor");
  motor.DriveMotor(1, 0, 0); // Stop motor (standby)
  delay(1000);

  Serial.println("Brake motor");
  motor.DriveMotor(1, 99, 0); // Brake motor (both outputs HIGH)
  delay(1000);
}
