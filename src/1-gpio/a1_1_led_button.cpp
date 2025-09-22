#include <Arduino.h>

bool led_state = false;
bool button_pressed = false;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  button_pressed = digitalRead(2);
  if (button_pressed)
  {
    led_state = !led_state;
    digitalWrite(13, led_state);
    delay(500);
  }
}
