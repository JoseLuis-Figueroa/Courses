//**************************************************************//
//  Name    : Connecting to WIFI                    
//  Author  : Jose Luis Figueroa                                
//  Date    : 26 April, 2021 
//  Board   : NodeMCU 8266
//  Version : 1.0                                               
//  Notes   : ESP8266 is connected to the WIFI network                                    
//**************************************************************//
#include <Arduino.h>
#include <ESP8266WiFi.h>

//Constants
#define BAUD 9600
//Delays
#define D_300ms 300
#define D_500ms 500

//WiFi Config
const char ssid[] = "INFINITUM5A0D_2.4";
const char password[] = "ouVbHu4TJi";

void setup() 
{
  //Initialize Serial 
  Serial.begin(BAUD);
  delay(D_300ms);

  //Connect to WiFi
  Serial.print("Connecting to ");
  Serial.print(ssid);
  //Connect to the given network and password 
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(D_500ms);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected");
}

void loop() 
{
  // put your main code here, to run repeatedly:
}