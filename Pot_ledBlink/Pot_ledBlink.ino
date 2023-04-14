int Pin[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  int ledNum = 13;
  int ledDelay = 0;
  int potPin = A0;
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /*
  for (int i = 0; i < ledNum; i++)
  {
    if (digitalRead(ledPin[x]) == HIGH)
    digitalRead(ledPin[x], LOW);
    delay(100);
    else digitalRead(ledPin[x], HIGH);
  }*/
  Serial.println(Pin[13]);
  digitalWrite(Pin[13], HIGH);
  delay(1000);
  digitalWrite(Pin[13], LOW);
  delay(1000);
}
