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
  Wire.write(0x00); // Address that we want to jump to
  Wire.endTransmission();

  Wire.requestFrom(CLOCK_ADDRESS, 7);

  byte second = Wire.read();
  byte minutes = Wire.read();
  byte hours = Wire.read();
  byte dayOfWeek = Wire.read();
  byte dayOfMonth = Wire.read();
  byte month = Wire.read();
  byte year = Wire.read();

  Serial.println("Seconds: " + String(second, HEX));
  Serial.println("Minutes: " + String(minutes, HEX));
  Serial.println("Hours: " + String(hours, HEX));
  Serial.println("Day of Week: " + String(dayOfWeek, HEX));
  Serial.println("Day of Month: " + String(dayOfMonth, HEX));
  Serial.println("Month: " + String(month, HEX));
  Serial.println("Year: " + String(year, HEX));

  delay(1000);
}