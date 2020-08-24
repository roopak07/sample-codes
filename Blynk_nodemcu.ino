#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<String.h>

char auth[] = "e9d0c7f4f2f44ac0889c201e7aee194f";
char ssid[] = "Leap Robots LLP";
char pass[] = "leaprobot$";
BlynkTimer timer;

int result;
void sendSensor()
{
  bool result = Blynk.connected();
  Serial.println("Online Status: "+String(result));
  if(result==1)  // indication for online
   digitalWrite(15,HIGH); 
  else
    digitalWrite(15,LOW);
  // Include Accelerometer sensor read code here
  if(Acceleromter z val > 250)
  {
   Blynk.email("abc@gmail.com", "Email subject", "Email body");
  }
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(15,OUTPUT); //D8 , for online indication
  // Define pin modes for Accelerometer here
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
