String last_com = "", message = "";
int input = 0, input_sv, i = 0;

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  pinMode(13, OUTPUT);
  Serial.println("-----WELCOME-----\nHere are the following commands:\n1 to 13\n0");
}

void loop()
{
  input = 0;
  if (Serial.available() > 0)
  {
    input += int(Serial.read());
    if (input >= 10) input_sv = input - 97;
    delay(100);
  }

  Serial.println(input_sv);
  
  if (input_sv > 0)
  {
      for (i = 1; i <= 13; i++)
      {
          if (i = input) digitalWrite(i, HIGH);
          else digitalWrite(i, LOW);

          message = "Turned LED on.";
      }
  }
  else if (input_sv = 0)
  {
    for (int i = 1; i <= 13; i++) digitalWrite(i, LOW);
    message = "Turned off LED.";
  }
  else message = "Invalid command.";

  if (message != last_com)
  {
    Serial.println(message);
    last_com = message;
  }
}
