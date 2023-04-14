int wait = 0, pin = 13;

void setup() {
    pinMode(pin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.print(wait);
    if (wait < 100) digitalWrite(pin, HIGH);
    else if (wait < 100) digitalWrite(pin, HIGH);
    else if (wait < 200) digitalWrite(pin, LOW);
    else if (wait < 300) digitalWrite(pin, HIGH);
    else if (wait < 400) digitalWrite(pin, LOW);
    else if (wait < 500) digitalWrite(pin, HIGH);
    else if (wait < 600) digitalWrite(pin, LOW);
    else if (wait < 700) digitalWrite(pin, HIGH);
    else if (wait < 800) digitalWrite(pin, LOW);
    else if (wait < 900) digitalWrite(pin, HIGH);
    else if (wait < 1000) digitalWrite(pin, LOW);
    else if (wait < 1050) digitalWrite(pin, HIGH);
    else if (wait < 1100) digitalWrite(pin, LOW);
    else if (wait < 1150) digitalWrite(pin, HIGH);
    else if (wait < 1200) digitalWrite(pin, LOW);
    else if (wait < 1250) digitalWrite(pin, HIGH);
    else if (wait < 1300) digitalWrite(pin, LOW);
    else if (wait < 1350) digitalWrite(pin, HIGH);
    else if (wait < 1400) digitalWrite(pin, LOW);
    else if (wait < 1450) digitalWrite(pin, HIGH);
    else if (wait < 1500) digitalWrite(pin, LOW);
    else wait = 0;

    wait++;
}
