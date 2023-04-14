//GSM Shield for Arduino
//www.open-electronics.org
//this code is based on the example of Arduino Labs.

//Simple sketch to send and receive SMS.

#include "SIM900.h"
#include <SoftwareSerial.h>

#include "sms.h"
SMSGSM sms;

int numdata;
boolean started=false;
char smsbuffer[160];
char n[20];

void setup() 
{
  //Serial connection.
  Serial.begin(9600);
  Serial.println("GSM Shield testing.");
  if (gsm.begin(2400)){
    Serial.println("\nstatus=READY");
    started=true;  
  }
  else Serial.println("\nstatus=IDLE");
  
  if(started){
        //SET THE RECEIVER'S PHONE NUMBER AND THE MESSAGE, (replace the 0 in the first digit with your country code,In my case I use +63 because I'm in the Philippines).
    if (sms.SendSMS("+639452178545", "TEXT MESSAGE HERE")) 
      Serial.println("\nSMS sent to 09453791528");
  }

};

void loop() 
{
  if(started){
    //Read if there are messages on SIM card and print them.
    if(gsm.readSMS(smsbuffer, 160, n, 20))
    {
      Serial.println(n);
      Serial.println(smsbuffer);
    }
    delay(1000);
  }
};
