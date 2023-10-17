#include <PIDController.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <utility/Adafruit_MS_PWMServoDriver.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

// Define encoder pins

const int leftEncoderPinA = 2;
const int leftEncoderPinB = 3;
const int rightEncoderPinA = 18;
const int rightEncoderPinB = 19;

// Create encoder instances

Encoder leftEncoder(leftEncoderPinA, leftEncoderPinB);
Encoder rightEncoder(rightEncoderPinA, rightEncoderPinB);

// Define PID constants

double Kp = 100;
double Ki = 4500;
double Kd = 500;

// Create PID instances

PID leftPID(&leftEncoderPosition, &leftMotorSpeed, &leftMotorPower, Kp, Ki, Kd, DIRECT);
PID rightPID(&rightEncoderPosition, &rightMotorSpeed, &rightMotorPower, Kp, Ki, Kd, DIRECT);

// Setpoints for left and right encoders

double leftSetpoint = 0;
double rightSetpoint = 0;

// Variables for PID-controlled motor speed and power

double leftEncoderPosition, rightEncoderPosition;
double leftMotorSpeed, rightMotorSpeed;
double leftMotorPower, rightMotorPower;

void setup() {
// Set up motor controller
AFMS.begin();

// Set up encoder pins

pinMode(leftEncoderPinA, INPUT);
pinMode(leftEncoderPinB, INPUT);
pinMode(rightEncoderPinA, INPUT);
pinMode(rightEncoderPinB, INPUT);

// Set up PID parameters

leftPID.SetMode(AUTOMATIC);
rightPID.SetMode(AUTOMATIC);
leftPID.SetOutputLimits(-270, 270);
rightPID.SetOutputLimits(-270, 270);
}

void loop() {
// Read encoder positions

leftEncoderPosition = leftEncoder.read();
rightEncoderPosition = rightEncoder.read();

// Compute PID control outputs

leftPID.Compute();
rightPID.Compute();

// Adjust motor speed based on PID outputs

leftMotor->setSpeed(abs(leftMotorSpeed));
rightMotor->setSpeed(abs(rightMotorSpeed));

// Set motor directions

if (leftMotorSpeed >= 0) {
leftMotor->run(FORWARD);
} else {
leftMotor->run(BACKWARD);
}

if (rightMotorSpeed >= 0) {
rightMotor->run(FORWARD);
} else {
rightMotor->run(BACKWARD);
}

// Adjust motor power based on PID outputs

leftMotor->setSpeed(abs(leftMotorPower));
rightMotor->setSpeed(abs(rightMotorPower));

// Set motor directions

if (leftMotorPower >= 0) {
leftMotor->run(FORWARD);
} else {
leftMotor->run(BACKWARD);
}

if (rightMotorPower >= 0) {
rightMotor->run(FORWARD);
} else {
rightMotor->run(BACKWARD);
}
}
