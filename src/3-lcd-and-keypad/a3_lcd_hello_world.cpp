#include <Arduino.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Hello");
  delay(500);

  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("World");
  delay(500);
}