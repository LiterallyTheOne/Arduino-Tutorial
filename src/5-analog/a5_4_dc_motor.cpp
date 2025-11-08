#include <Arduino.h>

void setup()
{
  pinMode(3, OUTPUT);
}

void loop()
{
  int our_input = analogRead(A0);
  int speed = map(our_input, 0, 1023, 0, 255);
  analogWrite(3, speed);
  delay(1000);
}