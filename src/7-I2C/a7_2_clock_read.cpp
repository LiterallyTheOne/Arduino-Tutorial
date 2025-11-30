#include <Arduino.h>
#include <Wire.h>

#define DS1307_ADDRESS 0x68

#define TIME_READ 7

byte time[TIME_READ];

void read_date_and_time()
{
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);

  for (int i = 0; i < TIME_READ; i++)
  {
    time[i] = Wire.read();
  }
}

void setup()
{
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  read_date_and_time();

  for (int i = 0; i < TIME_READ; i++)
  {
    Serial.print(String(time[i], HEX) + " ");
  }
  Serial.println();

  delay(1000);
}