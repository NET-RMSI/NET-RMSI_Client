#include "WiFi.h"
#include "WifiConfig.h"
#include "TCPClientConfig.h"
#include "WiFiMulti.h"

void wifiinit()
{
  WifiConfig wc;
  WiFi.mode(WIFI_STA);
  WiFi.begin(wc.SSID, wc.WifiPassword);

  Serial.print("\nConnecting to specified network");

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("\nFailed to connect to specified network");
    while(true);
  }
  else
  {
    Serial.print("\nConnected to network");
    Serial.print("\nConnection details:");
    Serial.print("\nSSID:");
    Serial.println(WiFi.SSID());
    Serial.print("\nDevice IP Address:");
    Serial.println(WiFi.localIP());
  }
}

void tcpclientinit()
{
  TCPClientConfig tcpcliconf;

  WiFiClient tcpclient;

  tcpclient.connect(tcpcliconf.host, tcpcliconf.port);

  Serial.println("\nAttempting to connect to specified NET-RMSI server.");
  if (!tcpclient.connected())
  {
    Serial.print("\nFailed to connect to specified NET-RMSI server");
    while(true);
  }
  else
  {
    Serial.print("\nConnected to TCPServer");
  }
}

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
