#include "WiFi.h"
#include "WifiConfig.h"
#include "TCPClientConfig.h"
#include "WiFiMulti.h"
#include "string.h"

  TCPClientConfig tcpcliconf;
  WifiConfig wc;
void wifiinit()
{
  
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
    serverclientidentif(tcpclient);

    
}

void serverclientidentif(WiFiClient tcpclient)
{

  tcpclient.println(tcpcliconf.controlledcli);

    String recvidentif = tcpclient.readString();

    if (recvidentif == "Current")
    {
      Serial.print("\nClient-Server versioning the same");
    }
    else
    {
      Serial.print("\nDisconnecting from server");
      Serial.println("\nClient version: " + tcpcliconf.controlledcli);
      Serial.print("Outdated client version please update, ensure server and client are on the same major version");
      tcpclient.stop();

      tcpclientinit();
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


