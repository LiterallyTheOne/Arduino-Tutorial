#include <Arduino.h>
#include <Keypad.h>

char key;

const byte ROWS = 4;
const byte COLS = 3;

int number = 0;

char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  key = keypad.getKey();
  if (key)
  {
    if (key >= '0' && key <= '9')
    {
      number = number * 10 + (key - '0');
    }
    else if (key == '*')
    {
      number = 0;
    }
    else if (key == '#')
    {
      Serial.println(number);
      number = 0;
    }
    delay(250);
  }
}