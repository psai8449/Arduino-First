//The following code allows us to control the direction of a servo and the
speed of a dc motor by varying the values of resistance of a potentiometer
and a flex sensor respectively.
//It also prints the output in the specified CSV format to the serial
monitor.
#include <Servo.h>
Servo servo1;
//pin declarations
const int flexPin = A0;
const int motorPin = 5;
const int potPin = A1;
void setup() {
Serial.begin(9600);
servo1.attach(11);
pinMode(motorPin, OUTPUT);
}
void loop() {
//variable declarations
int flexValue;
int servoPosition;
int potValue;
int dcSpeed;
//servo controls
potValue = analogRead(potPin);
servoPosition = map(potValue, 0, 1000, 0, 180);
servoPosition = constrain(servoPosition, 0, 180);
servo1.write(servoPosition);
//dc_motor controls
flexValue = analogRead(flexPin);
dcSpeed = map(flexValue, 900, 1020, 50, 255);
dcSpeed = constrain(dcSpeed, 0, 255);
analogWrite(motorPin, dcSpeed);
//CSV printcommands
Serial.print(potValue);
Serial.print(",");
Serial.print(servoPosition);
Serial.print(",");
Serial.print(flexValue);
Serial.print(",");
Serial.println(dcSpeed);
delay(400);
}