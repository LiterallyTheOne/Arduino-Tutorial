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
  byte minutes_to_write = 25;
  // convert 25 to 0x25
  minutes_to_write = (minutes_to_write / 10) * 16 + minutes_to_write % 10;

  // Write minutes
  Wire.beginTransmission(CLOCK_ADDRESS);
  Wire.write(0x01); // Address that we want to jump to
  Wire.write(minutes_to_write);
  Wire.endTransmission();

  // Read minutes
  Wire.beginTransmission(CLOCK_ADDRESS);
  Wire.write(0x01); // Address that we want to jump to
  Wire.endTransmission();

  Wire.requestFrom(CLOCK_ADDRESS, 1);

  byte minutes = Wire.read();

  Serial.println("Minutes:" + String(minutes, HEX));

  delay(1000);
}