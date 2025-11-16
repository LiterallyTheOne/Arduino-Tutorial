#include <Arduino.h>

int led_pins[8] = {6, 7, 8, 9, 10, 11, 12, 13};

volatile int current_led = 0;
int x = 1;

void isr_stop()
{
  x = 1 - x;
}

void isr_reset()
{
  digitalWrite(led_pins[current_led], LOW);
  current_led = 0;
  digitalWrite(led_pins[current_led], HIGH);
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
  digitalWrite(led_pins[current_led], HIGH);
  delay(200);
  digitalWrite(led_pins[current_led], LOW);

  current_led += x;
  current_led %= 8;
}