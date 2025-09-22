#include <Arduino.h>

int led_state = 0;
bool button_pressed = false;

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(2, INPUT);

  digitalWrite(11, HIGH);
}

void loop()
{
  button_pressed = digitalRead(2);
  if (button_pressed)
  {
    led_state += 1;
    if (led_state > 2)
    {
      led_state = 0;
    }
    for (int i = 0; i <= 2; i++)
    {
      if (i == led_state)
      {
        digitalWrite(11 + i, HIGH);
      }
      else
      {
        digitalWrite(11 + i, LOW);
      }
    }
    delay(500);
  }
}
