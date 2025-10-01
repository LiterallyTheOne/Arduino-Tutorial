#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    char ch = Serial.read();
    Serial.println(ch);
  }
}