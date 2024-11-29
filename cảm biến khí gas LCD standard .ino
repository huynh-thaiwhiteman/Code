/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */

// include the library code:
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int leddo = 9;
int ledxanh = 8;
int loa = 6;
int cbgas = A0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(leddo, OUTPUT);
  pinMode(ledxanh, OUTPUT);
  pinMode(loa, OUTPUT);
  pinMode(cbgas, INPUT);
  
}

void loop() {
  int gtcb = analogRead(cbgas);
  Serial.println(gtcb);
  if ( gtcb > 300 )
          {
    digitalWrite(leddo, HIGH);
    digitalWrite(ledxanh, LOW);
    tone (loa,1000,10000);
    lcd.clear();
    lcd.setCursor(5, 1);
    lcd.print("RO GAS");
    delay(1000);
      }
  else {
    digitalWrite(leddo, LOW);
    digitalWrite(ledxanh, HIGH);
    noTone (loa);
    lcd.clear();
    lcd.setCursor(5, 1);
    lcd.print("KHONG RO");
    delay(1000);
  }
}
