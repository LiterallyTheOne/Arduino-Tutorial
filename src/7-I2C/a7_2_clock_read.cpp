#include <Arduino.h>
#include <Wire.h>

#define DS1307_ADDRESS 0x68

#define TIME_READ 7

// seconds, minutes, hours, weekday, day, month, year
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
    int time_int = 0;
    time_int = (time[i] / 16) * 10 + time[i] % 16;
    Serial.print(String(time_int) + " ");
  }
  Serial.println();

  delay(1000);
}