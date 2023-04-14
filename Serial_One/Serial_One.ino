String str = "", last_com = "", message = "";
int sv, ls_sv, i = 0;

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        pinMode(13, OUTPUT);
        Serial.println("-----WELCOME-----");
        Serial.println("Here are the following commands:");
        Serial.println("1 to 13 - Set LED # entered on.");
        Serial.println("0 - Turn off all LEDs.");
}

void loop()
{
        str = "";
        while (Serial.available() > 0)
        {
            str += char(Serial.read());
            str.trim();
            
            sv = str.toInt();
            delay(10);
        }
        
        for (int i = 1; i <= 13; i++) if (i != sv) digitalWrite(i, LOW);
        
        if (sv > 0)
        {
            digitalWrite(sv, HIGH);
            message = "Turned on LED " ;
        }
        else if (sv == 0)  message = "Turned off all LEDs.";
        else message = "Invalid command.";
        
        if ((message != last_com)||(ls_sv != sv))
        {
            Serial.print(message);
            if (sv != 0)
            {
                Serial.print(sv);
                Serial.print(".");
            }
            Serial.println();
            last_com = message;
        }
        ls_sv = sv;
}
