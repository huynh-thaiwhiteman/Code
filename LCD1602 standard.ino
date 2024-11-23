#include <LiquidCrystal.h>
#define SENSOR_PIN A0
float voltage = 0;
float sensor = 0;
float celisus = 0;
float fahrenheit = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("NHIET DO");
  
}
void loop() {
  sensor = analogRead(SENSOR_PIN);
  voltage = (sensor*5000)/1024;
  voltage = voltage-495;
  celisus = voltage/10;
  lcd.setCursor(5, 1);
  lcd.print(celisus);

}
