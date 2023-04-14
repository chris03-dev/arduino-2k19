// the setup function runs once when you press reset or power the board
void setup() {
  int x = 0;
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int x = analogRead(A0);
  digitalWrite(13, HIGH);
  digitalWrite(11, LOW);
  delay(x);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(x);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  delay(x);
}
