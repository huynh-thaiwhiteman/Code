#include <EEPROM.h>
const int buttonPin = 8;    
const int ledPin = 4;       
int ledState;               
int buttonState;             
int lastButtonState = LOW;  
long lastDebounceTime = 0;  
long debounceDelay = 50;   

void setup() {
  // set input and output
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, ledState);

  Serial.begin (9600);

  checkLedState(); 
}

void loop() {
  int reading = digitalRead(buttonPin);
  if(reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if((millis() - lastDebounceTime) > debounceDelay) {
    if(reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if(buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }


  digitalWrite(ledPin, ledState);
  EEPROM.update(0, ledState);
  lastButtonState = reading;
}

void checkLedState() {
   Serial.println("LED status after restart: ");
   ledState = EEPROM.read(0);
   if(ledState == 1) {
    Serial.println ("ON");
    digitalWrite(ledPin, HIGH);
   } 
   if(ledState == 0) {
    Serial.println ("OFF");
    digitalWrite(ledPin, LOW);
   }
}
