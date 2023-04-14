const String str = "", str_sv = "", last_com = "", message = "";

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        pinMode(13, OUTPUT);
        Serial.println("-----WELCOME-----\nHere are the following commands:\non\noff");
}

void loop()
{
        str = "";
        while (Serial.available() > 0)
        {
            str += char(Serial.read());
            str.trim();
            str_sv = str;
            delay(10);
        }
        
        if (str_sv == "on")
        {
            digitalWrite(11, LOW);
            digitalWrite(12, LOW);
            digitalWrite(13, HIGH);
            message = "Turned on LED.";
        }
        else if (str_sv == "off")
        {
            digitalWrite(13, LOW);
            message = "Turned off LED.";
        }
        else message = "Invalid command.";
        
        if (message != last_com) 
        {
            Serial.println(message);
            last_com = message;
        }
}
