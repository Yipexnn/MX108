/**
 * @file MX108.h
 * @brief Library for controlling up to two DC motors via the MX108 driver module.
 *
 * Provides bidirectional and PWM speed control for one or two motors.
 * Designed for MX108-compatible H-bridge motor drivers.
 *
 * @author Jan Bernitt
 * @date 2025
 */

#ifndef MX108_h
#define MX108_h

#include "Arduino.h"

/**
 * @class MX108
 * @brief Class for controlling one or two DC motors using an MX108 motor driver.
 *
 * The MX108 class allows independent speed and direction control for up to two motors.
 * It supports both single-motor and dual-motor configurations.
 */
class MX108
{
public:
  /**
   * @brief Construct an MX108 object for controlling a single motor.
   *
   * This constructor initializes two output pins for controlling one motor.
   * Use this version when only one motor is connected.
   *
   * @param pinA PWM or digital output pin connected to motor input A.
   * @param pinB PWM or digital output pin connected to motor input B.
   *
   * @example
   * MX108 motor(5, 6);
   * motor.DriveMotor(1, 1, 80); // Run motor forward at 80% speed
   */
  MX108(int pinA, int pinB);

  /**
   * @brief Construct an MX108 object for controlling two motors.
   *
   * This constructor initializes four output pins for controlling two independent motors.
   * Use this version when both motor channels (A/B and C/D) are connected.
   *
   * @param pinA PWM or digital output pin for motor 1 input A.
   * @param pinB PWM or digital output pin for motor 1 input B.
   * @param pinC PWM or digital output pin for motor 2 input A.
   * @param pinD PWM or digital output pin for motor 2 input B.
   *
   * @example
   * MX108 motors(5, 6, 9, 10);
   * motors.DriveMotor(1, 1, 75); // Motor 1 forward 75%
   * motors.DriveMotor(2, -1, 50); // Motor 2 reverse 50%
   */
  MX108(int pinA, int pinB, int pinC, int pinD);

  /**
   * @brief Drive one of the motors connected to the MX108 driver.
   *
   * This function provides bidirectional control of up to two DC motors
   * using PWM for speed control. The motor direction and speed are set
   * independently for each motor channel.
   *
   * @param motor
   *        Selects which motor to control:
   *        - **1** → first motor (pins A/B)
   *        - **2** → second motor (pins C/D)
   *
   * @param direction
   *        Sets the motor rotation direction:
   *        - **-1** → reverse (A = LOW, B = PWM)
   *        - **0**  → stop / standby (A = LOW, B = LOW)
   *        - **1**  → forward (B = LOW, A = PWM)
   *        - *any other value* → brake (A = HIGH, B = HIGH)
   *
   * @param speed
   *        Motor speed in percent (0–100%).
   *        Internally mapped to 8-bit PWM (0–255).
   *
   * @note
   * - The `speed` parameter controls PWM duty cycle — not torque.
   * - If `motor == 2` and the object was created with the 2-pin constructor,
   *   the command will be ignored safely.
   *
   * @example
   * MX108 driver(5, 6, 9, 10);
   * driver.DriveMotor(1, 1, 75);  // motor 1 forward 75%
   * driver.DriveMotor(2, -1, 50); // motor 2 reverse 50%
   */
  void DriveMotor(int motor, int direction, float speed);

private:
  int pinA = 0;  ///< Motor 1 input A pin
  int pinB = 0;  ///< Motor 1 input B pin
  int pinC = 0;  ///< Motor 2 input A pin
  int pinD = 0;  ///< Motor 2 input B pin
};

#endif
