#include "WiFi.h"
#include "WifiConfig.h"
#include "TCPClientConfig.h"
#include "WiFiMulti.h"
#include "string.h"

void(* resetclient) (void) = 0;

TCPClientConfig tcpcliconf;
WifiConfig wc;

WiFiClient tcpclient;

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
  Serial.print("\nSSID: " + WiFi.SSID() + "\nDevice IP: " + WiFi.localIP());
}

void tcpclientinit()
{

  tcpclient.connect(tcpcliconf.host, tcpcliconf.port);

  Serial.println("\nAttempting to connect to specified NET-RMSI server at: " + String(tcpcliconf.host));
  while (!tcpclient.connected())
  {

    tcpclient.connect(tcpcliconf.host, tcpcliconf.port);
    Serial.print("\nRetrying in 5 seconds");
    delay(5000);

  }
  Serial.print("\nConnected to TCPServer");
  while (true)
  {
   
   
    tcpclient.println(tcpcliconf.controlledcli);

    String recvidentif = tcpclient.readString();
       
    
  if (recvidentif == "valid")
  {
    Serial.print("\nClient-Server versioning the same");
    break;

  }
  else if (recvidentif == "invalid")
  {
    Serial.print("\nDisconnecting from server");
    Serial.println("\nCurrent controller version: " + tcpcliconf.controlledcli);
    Serial.print("client-server versioning mismatch please update, ensure server and client are on the same version");
    tcpclient.stop();
    resetclient();
  }
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
  String recv = tcpclient.readString();
  Serial.println("Recieved: " + recv);


  if (recv == "0")
  {
    /* Relay control code here */
  }
  else if (recv == "1")
  {
    /* Relay control code here */
  }

}
