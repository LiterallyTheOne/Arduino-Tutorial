#include <Arduino.h>

int led_state = 0;
bool button_1_pressed = false;

bool disable_all = false;
bool button_2_pressed = false;

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(2, INPUT);
  pinMode(3, INPUT);

  digitalWrite(11, HIGH);
}

void loop()
{
  button_1_pressed = digitalRead(2);
  button_2_pressed = digitalRead(3);

  if (button_2_pressed)
  {
    disable_all = !disable_all;
    if (disable_all)
    {
      for (int i = 0; i <= 2; i++)
      {
        digitalWrite(11 + i, LOW);
      }
    }
    else
    {
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
    }
    delay(500);
  }

  if (button_1_pressed && !disable_all)
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
