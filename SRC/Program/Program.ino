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

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("\nConnecting to network");
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


  while (!tcpclient.connect(tcpcliconf.host, tcpcliconf.port))
  {
    Serial.println("\nConnection has failed.");
    Serial.println("Retrying in 10 seconds");
    delay(10000);
    tcpclientinit();
  }

Serial.print("\nConnected to TCPServer");
  


}
