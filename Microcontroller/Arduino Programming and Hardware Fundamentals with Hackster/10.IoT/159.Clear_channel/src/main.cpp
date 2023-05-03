//**************************************************************//
//  Name    : Clear a channel             
//  Author  : Jose Luis Figueroa                                
//  Date    : 14 May, 2021 
//  Board   : NodeMCU 8266
//  Version : 1.0                                               
//  Notes   : Clear the data of one channel.                            
//**************************************************************//
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

//Constant 
#define BAUD 9600
//Delays
#define D_300ms 300
#define D_500ms 500
#define D_30s 30000

//Wifi config
const char SSID[] = "INFINITUM5A0D_2.4";
const char PASSWORD[] = "ouVbHu4TJi";
//ThingSpeak config
const String CHANNEL_ID = "1390190";
const String USER_API_KEY = "X2IPU1KNCPPU00HV";

//Serve, file and port
const char HOSTNAME[] = "api.thingspeak.com";
const String URI = "/channels/" + CHANNEL_ID + "/feeds?api_key="
+ USER_API_KEY;
const uint8_t PORT = 80;
//WiFi cliente object
WiFiClient client;

void setup() 
{
  //Initialize serial 
  Serial.begin(BAUD);
  delay(D_300ms);

  //Connect to WiFi
  Serial.print("Connecting to ");
  Serial.println(SSID);
  //Conect to the given network and password
  WiFi.begin(SSID, PASSWORD);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(D_500ms);
  }
  Serial.print("Connected to ");
  Serial.println(WiFi.localIP());

  //Connect to ThingSpeak
  ThingSpeak.begin(client);
}

void loop() 
{
  //Connect to server (Stablish TPC connection with the server)
  Serial.print("Connecting to ");
  Serial.println(HOSTNAME);
  //Connect to the IP address and port specified in the constructor
  if(client.connect(HOSTNAME, PORT) == 1)
  {
    Serial.println("Successful connection");
  }
  else
  {
    Serial.println("Connection failed");
  }

  //Delete a channel
  // Send request for file from server
  client.print("DELETE " + URI + " HTTP/1.1\r\n" + "Host: " + 
  HOSTNAME + "\r\n" + "Connection: close\r\n\r\n");
  delay(500);

  while(client.available())
  {
    String ln = client.readStringUntil('\r');
    Serial.print(ln);
  }

  //Close TPC connection
  client.stop();
  Serial.println();
  Serial.println("Connection closed");
  delay(D_30s);

}