#include <Arduino.h>
#include <Servo.h>

Servo my_servo;

void setup()
{
  my_servo.attach(3);
}

void loop()
{
  int our_input = analogRead(A0);
  int angle = map(our_input, 0, 1023, 0, 180);
  my_servo.write(angle);
  delay(1000);
}