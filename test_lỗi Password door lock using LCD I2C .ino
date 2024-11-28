// C++ code

/*LCD Display With I2C Connections:
  VCC ==== +5V
  GND ==== GND
  SCL  ==== SCL
  SDA ==== SDA
Servo motor Connections:
   VCC ==== +5V
   GND ==== GND
   Signal port === to Digital I/O  10
Keypad  Connections:
   Row1 ==== to Digital I/O  7
   Row2 ==== to Digital I/O  6
   Row3 ==== to Digital I/O  5
   Row4 ==== to Digital I/O  4
   Column1 ==== to Digital I/O  3
   Column2 ==== to Digital I/O  2
   Column3 ==== to Digital I/O  1
   Column4 ==== to Digital I/O  3
*/
     
#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

#define led 13


Servo servo;

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

Keypad kp = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char correctPass[] = "1234";
int number = sizeof(correctPass)-1;
char pass[sizeof(correctPass)-1];
int i=0,counter=0;

bool door = 1;


void setup() {
    pinMode(led,OUTPUT);
    servo.attach(10);
    lcd.begin(16, 2);
    
    lcd.print("Enter the Pass");
    servo.write(0);
    lcd.setCursor(0,1);
}

void loop() {

    if(door==0){
         char key = kp.getKey();
         if(key=='C'){
         servo.write(0);
         i = counter = 0;
         lcd.clear();
         lcd.print("Enter the pass");
         lcd.setCursor(0,1);
         door = 1;
         } 
      
    }else{
         char key = kp.getKey();
         if(key >= '0' && key <='9'){
            lcd.print('*');
            pass[i]=key;
            i++;
         }
         else if(key=='D'){
            if(i==number){
                for(int j=0 ; j<number ; j++){
                   if(pass[j]==correctPass[j])counter++;
                }
                if(counter==number){
                  correct();
                }
                else{wrong();}
            }
            else{wrong();}
         }
        
     }
}

void wrong(){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Wrong Pass     ");
        lcd.setCursor(0,1);
        lcd.print("    Try Again   ");
        delay(2000);
        i=0;
        counter=0;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Enter the Pass");
        lcd.setCursor(0,1);
}
void correct(){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Correct Pass    ");
        delay(2000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("The door is open");
        lcd.setCursor(0,1);
        lcd.print("<C> To close");
        servo.write(90);
        delay(1000);
        i=0;
        counter=0;
        door = 0;
        
        
}

