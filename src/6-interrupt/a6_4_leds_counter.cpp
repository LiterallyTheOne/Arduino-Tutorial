#include <Arduino.h>

int led_pins[8] = {6, 7, 8, 9, 10, 11, 12, 13};

uint8_t a = 0;

int x = 1;

void isr_stop()
{
  x = 1 - x;
}

void isr_reset()
{
  a = 0;
}

void setup()
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(led_pins[i], OUTPUT);
  }

  attachInterrupt(digitalPinToInterrupt(2), isr_stop, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), isr_reset, FALLING);
}

void loop()
{
  for (int i = 0; i < 8; i++)
  {
    bool led_on = ((a >> i) & 0x01);
    digitalWrite(led_pins[i], led_on);
  }

  a += x;
  delay(200);
}