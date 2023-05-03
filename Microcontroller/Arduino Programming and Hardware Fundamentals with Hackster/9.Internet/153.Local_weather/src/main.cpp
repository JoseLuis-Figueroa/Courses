//**************************************************************//
//  Name    : Local weather               
//  Author  : Jose Luis Figueroa                                
//  Date    : 7 May, 2021 
//  Board   : NodeMCU 8266
//  Version : 1.0                                               
//  Notes   :                                   
//**************************************************************//
#include <Arduino.h>
#include<ESP8266WiFi.h>

//Constant
#define BAUD 9600
//Delays
#define D_300ms 300
#define D_500ms 500
#define D_10s 10000

//Wifi config
const char SSID[] = "INFINITUM5A0D_2.4";
const char PASSWORD[] = "ouVbHu4TJi";
//Server, file, and port
const char HOSTNAME[] = "api.openweathermap.org";
const String URI = "/data/2.5/weather?q=Aguascalientes&units=metric&appid=1a37e9efefc37a0c2b7659e0d6429d22";
const uint8_t PORT = 80;
//Wifi client(Initialize the Ethernet client library)
WiFiClient client;


void setup() 
{
  //Initialize serial
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
  Serial.print("Connecting to");
  Serial.println(HOSTNAME);
  //Connect to the IP adreess and port specified in the constructor
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

  //Store the data in the serial receive buffer if there are 
  //incoming bytes available from the server.
  while(client.available())
  {
    //Reads data from the serial buffer until description":"" 
    //is found. "\" is used to avoid error using "" by the 
    //compiler 
    if(client.find("description\":\""))
    {
      String weather = client.readStringUntil('"');
      Serial.print("Weather: ");
      Serial.println(weather);
    }

    //Reads data from the serial buffer until temp": is found
    //"\" is used to avoid error by the compiler 
    if(client.find("temp\":"))
    {
      //Print the ambient temperature
      String temp = client.readStringUntil(',');
      Serial.print("Ambient Temperature: ");
      Serial.print(temp);
      Serial.println("°C");
    }
  }

  //Close TPC connection
  client.stop();
  Serial.println();
  Serial.println("Connection closed");
  delay(D_10s);
}