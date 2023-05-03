//**************************************************************//
//  Name    : Temperature Logger               
//  Author  : Jose Luis Figueroa                                
//  Date    : 13 May, 2021 
//  Board   : NodeMCU 8266
//  Version : 1.0                                               
//  Notes   : ADC reads temperature sensor and store the info
//          : into ThingSpeak.                                    
//**************************************************************//
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

//Pins assignment
#define ADC_PIN A0

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
const uint32_t CHANNEL_ID = 1390190;
const char WRITE_API_KEY[] = "8N4P1BO2ZIPEIOF7";
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
}

void loop() 
{
  //Read the temperature sensor using the ADC
  float voltage = (analogRead(ADC_PIN) * 1.0 / 1023) * 3.0;
  uint16_t temperature = 100.0 * voltage;

  //Write values to our ThingSpeak channel
  Serial.println("Temperature: " + String(temperature));
  //Set the temperature
  ThingSpeak.setField(1, temperature);
  //Write to API key associated with the channel
  ThingSpeak.writeFields(CHANNEL_ID, WRITE_API_KEY);

  delay(D_30s);
}