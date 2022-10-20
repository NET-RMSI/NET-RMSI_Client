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

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
    
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

  tcpclient.connect(tcpcliconf.host, tcpcliconf.port);

  Serial.println("\nAttempting to connect to specified NET-RMSI server.");
  while (!tcpclient.connected())
  {

    tcpclient.connect(tcpcliconf.host, tcpcliconf.port);
    Serial.print("\nRetrying in 5 seconds");
    delay(5000);

  }
    Serial.print("\nConnected to TCPServer");

    tcpclient.println(tcpcliconf.controlledcli);
    char recvidentif = tcpclient.read();

    if (tcpcliconf.controlledcli == recvidentif)
    {
      
    }
    else
    {
      Serial.print("Disconnecting");
      tcpclient.stop();
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
