#include <Arduino.h>

int led_pins[8] = {6, 7, 8, 9, 10, 11, 12, 13};

int x = 1;

uint8_t a = 0;

uint8_t how_many = 1;

void isr_stop()
{
  x = 1 - x;
}

void isr_reset()
{
  a = 0;
  how_many = 1;
}

void setup()
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(led_pins[i], OUTPUT);
  }

  attachInterrupt(digitalPinToInterrupt(2), isr_stop, RISING);
  attachInterrupt(digitalPinToInterrupt(3), isr_reset, RISING);
}

void loop()
{
  for (int i = 0; i < 8; i++)
  {
    bool led_on = (a >> i) & 0x01;
    digitalWrite(led_pins[i], led_on);
  }

  if (a & 0x80)
  {
    a = 0;
  }
  a <<= x;

  if (a == 0)
  {
    a = 1;
    a <<= how_many;
    a -= 1;

    how_many++;
    how_many = how_many % 8;
  }

  delay(200);
}