/*
  Ping))) Sensor

  This sketch reads a PING))) ultrasonic
  rangefinder and returns the distance to the
  closest object in range. To do this, it sends a
  pulse to the sensor to initiate a reading, then
  listens for a pulse to return.  The length of
  the returning pulse is proportional to the
  distance of the object from the sensor.

  The circuit:
   * +V connection of the PING))) attached to +5V
   * GND connection attached to ground
   * SIG connection attached to digital pin 7

  http://www.arduino.cc/en/Tutorial/Ping

  This example code is in the public domain.
*/
const int trig = 8;  // chân trig của HC-SR04 //
const int echo = 7;  // chân echo của HC-SR04 //
int led1 = 9;
int led2 = 10;
int led3 = 11;

//long readUltrasonicDistance(int trigPin, int echoPin)//

void setup()
{
     Serial.begin(9600);     // giao tiếp Serial với baudrate 9600 //
     pinMode(trig, OUTPUT);  // chân trig sẽ phát tín hiệu //
     pinMode(echo, INPUT);   // chân echo sẽ nhận tín hiệu //
     
     pinMode(led1, OUTPUT);
     pinMode(led2, OUTPUT);
     pinMode(led3, OUTPUT);
     
}
void loop()
{
     
    unsigned long duration;  // Khai báo biến đo thời gian //
    int distance;            // Khai báo biến lưu khoảng cách //
    duration = pulseIn(echo, HIGH);     // Đo độ rộng xung HIGH của chân echo //
    distance = int(duration/2/29.412);  // Tính khoảng cách đến vật //

//Phát xung từ chân trig //
    digitalWrite(trig,0);  // tắt chân trig
    delay(1000);
    digitalWrite(trig,1);  // phát xung từ chân trig
    delay(1000);
    digitalWrite(trig,0);  // tắt chân trig
     
if (distance < 50 ){digitalWrite(led1,1);}
    else {digitalWrite(led1,0);}
    if (distance > 50 && distance < 100 ){digitalWrite(led2,1);}
    else {digitalWrite(led2,0);}
    if (distance > 100 ){digitalWrite(led3,1);}
    else {digitalWrite(led3,0);}
     
//In kết quả ra Serial Monitor//
     
Serial.print(distance);
Serial.println("cm");
delay(1000);
     
}
