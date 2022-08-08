#include "WiFi.h"
#include "WifiConfig.h"

void initialisation()
{
    
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, WifiPassword);
    while(WiFi.status() != WL_CONNECTED)
  {
        Serial.print(".");
        delay(100);    
  }
  Serial.print("\nConnection details");
  Serial.print("\nSSID:");
  Serial.println(WiFi.SSID());
  Serial.print("\nDevice IP Address:");
  Serial.println(WiFi.localIP());
  

}
void setup()
{
  Serial.begin(115200);
  initialisation();
  
  
}
void loop() 
{
  
}
