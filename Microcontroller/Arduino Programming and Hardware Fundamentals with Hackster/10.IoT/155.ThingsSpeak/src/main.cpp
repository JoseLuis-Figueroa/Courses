//**************************************************************//
//  Name    : Posting to ThingSpeak               
//  Author  : Jose Luis Figueroa                                
//  Date    : 13 May, 2021 
//  Board   : NodeMCU 8266
//  Version : 1.0                                               
//  Notes   : send random number to the ThingSpeak to be stored                                 
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
const uint32_t CHANNEL_ID = 1389183;
const char WRITE_API_KEY[] = "YPE4G53QZ1286VG5";
//WiFi cliente object
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
  Serial.print("Connecting to");
  Serial.println(WiFi.localIP());

  //Connect to ThingSpeak
  ThingSpeak.begin(client);
  //Initializes the pseudo-random number generator
  randomSeed(micros());
}

void loop() 
{
  //Generate random number 1 to 100
  uint8_t rando = random(1, 100);

  //Write values to our ThingSpeak channel
  Serial.println("Posting " + String(rando) + " to ThingSpeak");
  //Set the value of a single field
  ThingSpeak.setField(1, rando);
  //Write to API key associated with the channel
  ThingSpeak.writeFields(CHANNEL_ID, WRITE_API_KEY);

  delay(D_30s);
}