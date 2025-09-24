#include <Arduino.h>

int counter = 9;
char digits[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};

bool paused = false;

void setup()
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(i, OUTPUT);
  }

  pinMode(8, OUTPUT);
}

void show_digit(int digit)
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(i, (digits[digit] >> i) & 0x01);
  }
}

void loop()
{

  if (digitalRead(8) == HIGH)
  {
    delay(500);
    return;
  }

  show_digit(counter);
  counter--;
  if (counter < 0)
  {
    counter = 9;
  }

  delay(1000);
}