/*on start
//configure LCD: 1, type to: I2C(PCF8574), with address: 32 */
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_1(32, 16, 2);
void setup() {
//set possition on LCD: 1 to column: 0 row: 0
lcd_1.init();
lcd_1.setCursor(0, 0);
//on LCD: 1 turn on the backlight
lcd_1.backlight();
//on LCD: 1 turn on the display
lcd_1.display();
}
/*forever*/
void loop() {
//set possition on LCD: 1 to column: 0 row: 0;
lcd_1.setCursor(0, 0);
//print to LCD: 1 HuynhThai
lcd_1.print("HuynhThai");
//wait 2000 miliseconds
delay(2000);
//set position on LCD: 1 to column: 0,  row: 1
lcd_1.setCursor(0, 1);
//print to LCD: Hello World!
lcd_1.print("Hello World!");
//wait 2000 miliseconds
delay(2000);
//on LCD: 1 clear the screen
lcd_1.clear();
//change LCD
}



/* LCD I2C chatGPT and me //
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Địa chỉ I2C của module LCD, thường là 0x27 hoặc 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD 16x2

void setup() {
  // Khởi tạo LCD
  lcd.init();
  lcd.backlight(); // Bật đèn nền
  lcd.setCursor(0, 0); // Đặt con trỏ tại dòng 1, cột 1
  lcd.print("Hello, World!"); // Hiển thị dòng chữ
}

void loop() {
  // Hiển thị dòng chữ ở dòng 2
  lcd.setCursor(0, 1);
  lcd.print("I2C with LCD!");
  delay(1000); // Tạo độ trễ để quan sát
  // You can add more code here for dynamic content
} 
