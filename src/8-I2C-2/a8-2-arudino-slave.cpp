#include <Arduino.h>

#include <Wire.h>

String result;

void receiveEvent(int howMany)
{
  while (Wire.available())
  {
    char c = Wire.read();
    if (c == '\n')
    {
      Serial.println(result);
      result = "";
    }
    else
    {
      result += c;
    }
  }
}

void setup()
{
  Serial.begin(9600);

  Wire.begin(8);
  Wire.onReceive(receiveEvent);
}

void loop()
{
}
