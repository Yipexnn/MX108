#include <MX108.h>

/*
  Dual Motor Example for MX108 Library

  This sketch demonstrates controlling two DC motors independently
  using the MX108 library. Each motor can run forward, reverse,
  stop, or brake at variable speeds.

  Hardware:
  - Motor 1 connected to MX108 driver pins A/B -> Arduino 5/6
  - Motor 2 connected to MX108 driver pins C/D -> Arduino 9/10
*/

MX108 driver(5, 6, 9, 10); // Initialize two motors

void setup() {
  Serial.begin(9600);
  Serial.println("MX108 Dual Motor Example");
}

void loop() {
  Serial.println("Motor1 forward 75%, Motor2 reverse 50%");
  driver.DriveMotor(1, 1, 75);   // Motor 1 forward 75%
  driver.DriveMotor(2, -1, 50);  // Motor 2 reverse 50%
  delay(2000);

  Serial.println("Stop both motors");
  driver.DriveMotor(1, 0, 0);
  driver.DriveMotor(2, 0, 0);
  delay(1000);

  Serial.println("Motor1 reverse 40%, Motor2 forward 40%");
  driver.DriveMotor(1, -1, 40);
  driver.DriveMotor(2, 1, 40);
  delay(2000);

  Serial.println("Brake both motors");
  driver.DriveMotor(1, 99, 0);
  driver.DriveMotor(2, 99, 0);
  delay(1000);
}
