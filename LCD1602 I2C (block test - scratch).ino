/*on start
//configure LCD: 1, type to: I2C(PCF8574), with address: 32 */
#include<Liquid Crystal_I2C.h>
Liquid Crystal_I2C lcd_1(32, 16, 2);
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
//print to LCD: 1 Embedded Engineer
lcd_1.print("Embedded Engineer");
//wait 2000 miliseconds
delay(2000);
//on LCD: 1 clear the screen
lcd_1.clear();
}