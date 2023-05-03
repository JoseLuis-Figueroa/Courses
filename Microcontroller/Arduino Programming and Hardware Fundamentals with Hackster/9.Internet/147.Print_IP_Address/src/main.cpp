//**************************************************************//
//  Name    : Print IP address                 
//  Author  : Jose Luis Figueroa                                
//  Date    : 26 April, 2021 
//  Board   : NodeMCU 8266
//  Version : 1.0                                               
//  Notes   : Print the IP address (Web page)                                    
//**************************************************************//
#include <Arduino.h>
#include <ESP8266WiFi.h>

//Constants
#define BAUD 9600
//Delays
#define D_300ms 300
#define D_500ms 500
#define D_10s 10000

//WiFi Config
const char SSID[] = "INFINITUM5A0D_2.4";
const char PASSWORD[] = "ouVbHu4TJi";
//Server, file, and port
const char HOSTNAME[] = "example.com";
const String URI = "/index.html";
const int PORT = 80;
//WiFi client(Initialize the Ethernet client library)
WiFiClient client;


void setup() 
{
  //Initialize Serial 
  Serial.begin(BAUD);
  delay(D_300ms);

  //Connect to WiFi
  Serial.print("Connecting to ");
  Serial.print(SSID);
  //Connect to the given network and password
  WiFi.begin(SSID, PASSWORD);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(D_500ms);
    Serial.print(".");
  }
  Serial.print(" Connected to ");
  Serial.println(WiFi.localIP());
}


void loop() 
{
  //Connect to server (Stablish TPC conection with the server)
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

  //Send request for file
  client.print("GET " + URI + " HTTP/1.1\r\n" + "Host: " +
   HOSTNAME + "\r\n" + "Connection: close\r\n" + "\r\n");
  delay(D_500ms);
  //If there are incoming bytes available from the server
  //read them and print them
  while(client.available())
  {
    //Reads characters from server until the caracter is detected 
    //('\r') or it times out
    String ln = client.readStringUntil('\r');
    Serial.print(ln);
  }

  //Close TPC connection
  client.stop();
  Serial.println();
  Serial.println("Connection closed");
  delay(D_10s);
}