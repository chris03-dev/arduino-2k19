#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int led = 6;
int val, pos, brg;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  pos = myservo.read();
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  brg = map(val, 0, 1023, 0, 255);
  if (pos < val) pos += 1;
  if (pos > val) pos -= 1;
  myservo.write(pos);                  // sets the servo position according to the scaled value
  analogWrite(led, brg);
  Serial.println(val);
  Serial.println(myservo.read());
  delay(15);                           // waits for the servo to get there
}
