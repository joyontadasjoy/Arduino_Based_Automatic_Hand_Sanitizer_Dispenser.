#include <Servo.h>

// HC-SR04 Echo Pin & Trigger Pin connect to the Arduino Uno Digital Pins
#define echo_pin 2
#define trigger_pin 3

// Servo PWM
#define servo_pin 5

Servo servo_motor;

void setup() {
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  Serial.begin(9600);

  servo_motor.attach(servo_pin);
}

void loop() {

  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);

  long duration = pulseIn(echo_pin, HIGH); 
  double distance = duration * 0.034 / 2;

  Serial.print(distance);


  // If the distance read by the sensor is less than 10 cm and more than the minimum 3 cm, then it is assumed that there is a hand under the sanitizer
  if ((distance > 3) && (distance < 10)) {
    servo_motor.write(90);
    delay(100);
  }
  servo_motor.write(0);
}
