//**************************************************************//
//  Name    : Print parts of the a web page                
//  Author  : Jose Luis Figueroa                                
//  Date    : 5 May, 2021 
//  Board   : NodeMCU 8266
//  Version : 1.0                                               
//  Notes   :                                   
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
const char HOSTNAME[] = "wifitest.adafruit.com";
const String URI = "/testwifi/index.html";
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
    Serial.print(".");
    delay(D_500ms);
  }
  Serial.print("Connected to ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  //Connect to server (Stablish TPC connection with the server)
  Serial.print("Connecting to ");
  Serial.println(HOSTNAME);
  //Connect to the IP address and port specified in the constructor
  if(client.connect(HOSTNAME, PORT) == 1)
  {
    Serial.println("Connection Successful");
  }
  else
  {
    Serial.println("Connection failed");
  }
  //Send request for file
  client.print("GET " + URI + " HTTP/1.1\r\n" + "Host: " +
   HOSTNAME + "\r\n" + "Connection: close\r\n" + "\r\n");
  delay(D_500ms);
  //Look for "this, " and store whatever comes next
  String string = "Not found";
  for(unsigned long i=0; i<=500; i++)
  {
    //Reads data from the serial buffer until the target is found
    if(client.find("this, "))
    {
      string = client.readStringUntil('\n');
      //Continue reading while there are bytes availables
      while(client.available())
      {
        client.read();
      }
      break;
    }
  }
  //Print the string
  Serial.println(string);

  //Close TPC connection
  client.stop();
  Serial.println();
  Serial.println("Connection closed");
  delay(D_10s);
}