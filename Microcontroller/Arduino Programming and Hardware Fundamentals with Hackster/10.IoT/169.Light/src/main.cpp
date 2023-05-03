//**************************************************************//
//  Name    : Internet-Controlled Light Switch            
//  Author  : Jose Luis Figueroa                                
//  Date    : 19 May, 2021 
//  Board   : NodeMCU 8266
//  Version : 1.0                                               
//  Notes   : Turn on and off the light of the dressing room                        
//**************************************************************//
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Button.h>

//Pins Assignment
const uint8_t BTN1_PIN = D1;
const uint8_t BTN2_PIN = D2;

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
const String IFTTT_TRIGGER_ON = "Light_On";
const String IFTTT_TRIGGER_OFF = "Light_Off";
const String IFTTT_KEY = "j-KcedrI19PNQDzWjin7Bz7fCSbMyfR-pbdrcG2XUQr";
//Server, file, and port
const char HOSTNAME[] = "maker.ifttt.com";
const String URI_ON = "/trigger/" + IFTTT_TRIGGER_ON + "/with/key/"
+ IFTTT_KEY;
const String URI_OFF = "/trigger/" + IFTTT_TRIGGER_OFF + "/with/key/"
+ IFTTT_KEY;
const uint8_t PORT = 80;

//WiFiclient object
WiFiClient client;

//instances
Button button_on(BTN1_PIN);
Button button_off(BTN2_PIN);


void setup() 
{
  //Initialize Serial
  Serial.begin(BAUD);
  delay(D_300ms);
  //Connect to WiFi
  Serial.print("Connecting to ");
  Serial.print(SSID);
  //Connect to the network
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
  //Push the botton to turn on the dressing room light
  if (button_on.push() == HIGH)
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

    //Construct HTTP request
    String req = "POST " + URI_ON + " HTTP/1.1\r\n" + "Host: " +
    HOSTNAME + "\r\n" + "Connection: close\r\n" + "\r\n";

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
  }
  
  //Push the botton to turn off the dressing room light
  if(button_off.push() == HIGH)
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
    
    //Construct HTTP request
    String req = "POST " + URI_OFF + " HTTP/1.1\r\n" + "Host: " +
    HOSTNAME + "\r\n" + "Connection: close\r\n" + "\r\n";

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
  }

}