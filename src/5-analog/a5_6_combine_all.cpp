#include <Arduino.h>
#include <Servo.h>

Servo my_servo;

void setup()
{
  my_servo.attach(9);

  pinMode(5, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int rotation_sensor = analogRead(A0);
  int speed_sensor = analogRead(A1);

  int angle = map(rotation_sensor, 0, 1023, 0, 180);
  Serial.println(String(angle));
  my_servo.write(angle);

  int speed = map(speed_sensor, 0, 1023, 0, 255);
  analogWrite(5, speed);
  analogWrite(11, speed);

  delay(1000);
}