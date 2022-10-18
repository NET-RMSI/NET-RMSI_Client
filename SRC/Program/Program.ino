#include "WiFi.h"
#include "WifiConfig.h"
#include "TCPClientConfig.h"
#include "WiFiMulti.h"

void setup()
{
  Serial.begin(115200);
  delay(10000);
  wifiinit();
  tcpclientinit();

}
void loop()
{

}
void wifiinit()
{
  WifiConfig wc;
  WiFi.mode(WIFI_STA);
  WiFi.begin(wc.SSID, wc.WifiPassword);

  Serial.print("\nConnecting to network");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }
  
  Serial.print("\nConnected to network");
  Serial.print("\nConnection details:");
  Serial.print("\nSSID:");
  Serial.println(WiFi.SSID());
  Serial.print("\nDevice IP Address:");
  Serial.println(WiFi.localIP());

}
void tcpclientinit()
{
  TCPClientConfig tcpcliconf;

  WiFiClient tcpclient;

  Serial.println("\nAttempting to connect to TCPServer.");
  while (!tcpclient.connected())
  {
    
    tcpclient.connect(tcpcliconf.host, tcpcliconf.port);
    
    
    
  }

Serial.print("\nConnected to TCPServer");
  


}
