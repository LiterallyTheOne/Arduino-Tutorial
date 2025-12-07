#include <Arduino.h>
#include <Wire.h>

#define DS1621_ADDRESS 0x48
#define ARDUINO_2 0x08

float read_temperature()
{
    Wire.beginTransmission(DS1621_ADDRESS);
    Wire.write(0xAA);
    Wire.endTransmission();

    Wire.requestFrom(DS1621_ADDRESS, 2);
    byte temp_msb = Wire.read();
    byte temp_lsb = Wire.read();

    float result = temp_msb;
    if (temp_lsb & 0x80)
    {
        result += 0.5;
    }
    return result;
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

    Wire.beginTransmission(DS1621_ADDRESS);
    Wire.write(0xEE);
    Wire.endTransmission();

    Wire.beginTransmission(DS1621_ADDRESS);
    Wire.write(0xAC);
    Wire.write(0x00);
    Wire.endTransmission();

    delay(200);
}

void loop()
{
    float temperature = read_temperature();
    String str_temp = String(temperature);

    Serial.println(str_temp + " C");

    Wire.beginTransmission(ARDUINO_2);
    for (unsigned int i = 0; i < str_temp.length(); i++)
    {
        Wire.write(str_temp[i]);
    }
    Wire.endTransmission();

    Wire.requestFrom(ARDUINO_2, 2);
    String received_data = "";
    received_data += Wire.read();
    received_data += Wire.read();

    Serial.println("Received from Arduino 2: " + received_data);

    delay(1000);
}