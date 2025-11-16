#include <Arduino.h>

volatile int current_led = 6;

int x = 1;

void isr_stop()
{
  x = 1 - x;
}

void isr_reset()
{
  digitalWrite(current_led, LOW);
  current_led = 6;
  digitalWrite(current_led, HIGH);
}

void setup()
{
  for (int i = 6; i < 14; i++)
  {
    pinMode(i, OUTPUT);
  }

  attachInterrupt(digitalPinToInterrupt(2), isr_stop, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), isr_reset, FALLING);
}

void loop()
{
  digitalWrite(current_led, HIGH);
  delay(200);
  digitalWrite(current_led, LOW);

  current_led += x;
  if (current_led > 13)
  {
    current_led = 6;
  }
}