#include <Arduino.h>
#include <Wire.h>

#define CLOCK_ADDRESS 0x68

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  delay(1000);

  for (int i = 0; i < 128; i++)
  {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0)
    {
      Serial.println("Device found at address: 0x" + String(i, HEX));
    }
  }
}

void loop()
{
  Wire.beginTransmission(CLOCK_ADDRESS);
  Wire.write(0x01); // Address that we want to jump to
  Wire.endTransmission();

  Wire.requestFrom(CLOCK_ADDRESS, 2);

  byte minutes = Wire.read();
  byte hours = Wire.read();

  Serial.println("Minutes: " + String(minutes, HEX));
  Serial.println("Hours: " + String(hours, HEX));

  delay(1000);
}