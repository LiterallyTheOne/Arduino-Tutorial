#include <Arduino.h>

#include <Wire.h>

String result;
bool i2c_ready = false;

void receiveEvent(int howMany)
{
  i2c_ready = true;
  result = "";
  while (Wire.available())
  {
    char c = Wire.read();
    result += c;
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
  if (i2c_ready)
  {
    i2c_ready = false;
    Serial.println(result);
  }
}
