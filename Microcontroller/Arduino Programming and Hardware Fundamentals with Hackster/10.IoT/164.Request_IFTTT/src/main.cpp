//**************************************************************//
//  Name    : Making requests to IFTTT               
//  Author  : Jose Luis Figueroa                                
//  Date    : 5 May, 2021 
//  Board   : NodeMCU 8266
//  Version : 1.0                                               
//  Notes   : Make a request to IFTTT to send a email each minute                                  
//**************************************************************//
#include <Arduino.h>
#include <ESP8266WiFi.h>

//Constants
#define BAUD 9600
//Delays
#define D_300ms 300
#define D_500ms 500
#define D_60s 60000

//WiFi Config
const char SSID[] = "INFINITUM5A0D_2.4";
const char PASSWORD[] = "ouVbHu4TJi";

//IFTTT config
const String IFTTT_TRIGGER = "my_reminder";
const String IFTTT_KEY = "j-KcedrI19PNQDzWjin7Bz7fCSbMyfR-pbdrcG2XUQr";
//Server, file, and port
const char HOSTNAME[] = "maker.ifttt.com";
const String URI = "/trigger/" + IFTTT_TRIGGER + "/with/key/"
+ IFTTT_KEY;
const uint8_t PORT = 80;

//WiFiclient object
WiFiClient client;


void setup()
 {
  //Initialize serial
  Serial.begin(BAUD);
  delay(D_300ms);
  //Connect to WiFi
  Serial.print("Connecting to ");
  Serial.print(SSID);
  //Connecto to the given network
  WiFi.begin(SSID, PASSWORD);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(D_500ms);
  }
  Serial.print("connected to ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  //Construct HTTP request
  String req = "POST " + URI + " HTTP/1.1\r\n" + "Host: " +
  HOSTNAME + "\r\n" + "Connection: close\r\n" + "\r\n";

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

  //Send request for file (Send the email)
  client.print(req);
  delay(D_500ms);

  //Print reply from server
  while(client.available())
  {
    String ln = client.readStringUntil('\r');
    Serial.print(ln);
  }

  //Close TCP connection
  client.stop();
  Serial.println();
  Serial.println("Connection closed");

  delay(D_60s);
}