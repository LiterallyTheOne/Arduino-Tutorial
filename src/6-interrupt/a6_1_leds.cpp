#include <Arduino.h>

int current_led = 6;

void setup()
{
  for (int i = 6; i < 14; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  digitalWrite(current_led, HIGH);
  delay(200);
  digitalWrite(current_led, LOW);
  current_led++;
  if (current_led > 13)
  {
    current_led = 6;
  }
}