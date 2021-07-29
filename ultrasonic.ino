// C++ code
//
#include <Servo.h>

int ultrasonic = 0;

int motor = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_7;

void setup()
{
  pinMode(7, OUTPUT);
  servo_7.attach(7, 500, 2500);

}

void loop()
{
  ultrasonic = 0.01723 * readUltrasonicDistance(3, 2);
  if (ultrasonic <= 100) {
    digitalWrite(7, HIGH);
    servo_7.write(90);
    delay(2000); // Wait for 2000 millisecond(s)
    servo_7.write(0);
  } else {
    servo_7.write(0);
  }
}