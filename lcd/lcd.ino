#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("bakso tikus   ");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("testing goreng");
  delay(1000);
}