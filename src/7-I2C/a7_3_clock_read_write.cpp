#include <Arduino.h>
#include <Wire.h>

#define DS1307_ADDRESS 0x68

#define TIME_READ 7

// seconds, minutes, hours, weekday, day, month, year
byte time[TIME_READ];

void write_date_and_time(int *time_to_write)
{
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(0x00);

  for (int i = 0; i < TIME_READ; i++)
  {
    byte time_byte = (time_to_write[i] / 10) * 16 + time_to_write[i] % 10;
    Wire.write(time_byte);
  }
  Wire.endTransmission();
}

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

  for (int i = 0; i < 127; i++)
  {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0)
    {
      Serial.println("Device found at address: 0x" + String(i, HEX));
    }
  }

  int time_to_write[7] = {
      20, // second
      30, // minute
      11, // hour
      7,  // day of the week
      23, // day of the month
      11, // month
      25, // year
  };
  write_date_and_time(time_to_write);
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