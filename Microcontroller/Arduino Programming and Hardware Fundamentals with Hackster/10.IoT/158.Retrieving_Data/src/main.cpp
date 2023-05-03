//**************************************************************//
//  Name    : Retrieving data from ThingSpeak               
//  Author  : Jose Luis Figueroa                                
//  Date    : 13 May, 2021 
//  Board   : NodeMCU 8266
//  Version : 1.0                                               
//  Notes   : Get and print the last number of the field from 
//          : ThingSpeak page                               
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
#define field 1

//Wifi config
const char SSID[] = "INFINITUM5A0D_2.4";
const char PASSWORD[] = "ouVbHu4TJi";
//ThingSpeak config
const uint32_t CHANNEL_ID = 1389183;
const char WRITE_API_KEY[] = "YPE4G53QZ1286VG5";
const char READ_API_KEY[] = "8BU058MJYPK62F42";
//WiFi cliente object
WiFiClient client;

void setup() 
{ //Initialize serial
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
  Serial.print("Connecting to");
  Serial.println(WiFi.localIP());

  //Connect to ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  //Get lastet number from field
  uint32_t number = ThingSpeak.readIntField(CHANNEL_ID, field, READ_API_KEY);
  Serial.print("Number: ");
  Serial.println(number);

  delay(D_30s);
}