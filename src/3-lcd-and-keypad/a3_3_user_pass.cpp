#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

byte rowPins[ROWS] = {0, 1, 6, 7};
byte colPins[COLS] = {8, 9, 10};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char key;

String actual_user = "12";
String actual_pass = "5662";

String user = "";
String pass = "";

int state = 0;

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("User:");
  lcd.setCursor(0, 1);
  lcd.print("Pass:");
  lcd.setCursor(5, 0);
}

void loop()
{
  key = keypad.getKey();
  if (key)
  {
    switch (state)
    {
    case 0:

      if (key >= '0' and key <= '9')
      {
        user += key;
        lcd.write(key);
      }
      else if (key == '#')
      {
        state = 1;
        lcd.setCursor(5, 1);
      }

      break;

    case 1:
      if (key >= '0' and key <= '9')
      {
        pass += key;
        lcd.write('*');
      }
      else if (key == '#')
      {
        state = 2;
        lcd.clear();
        if (user == actual_user and pass == actual_pass)
        {
          lcd.print("Access Granted");
        }
        else
        {
          lcd.print("Access Denied");
        }
      }

      break;

    case 2:
      if (key == '#')
      {
        state = 0;
        user = "";
        pass = "";
        lcd.clear();
        lcd.print("User:");
        lcd.setCursor(0, 1);
        lcd.print("Pass:");
        lcd.setCursor(5, 0);
      }
      break;
    }

    delay(500);
  }
}