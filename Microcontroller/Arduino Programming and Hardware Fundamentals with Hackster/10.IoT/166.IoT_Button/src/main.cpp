//**************************************************************//
//  Name    : IoT Button              
//  Author  : Jose Luis Figueroa                                
//  Date    : 19 May, 2021 
//  Board   : NodeMCU 8266
//  Version : 1.0                                               
//  Notes   : Push a button and send a email with a message                          
//**************************************************************//
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Button.h>

//Pins Assignment
const uint8_t BTN_PIN = D1;

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
//HTTP post body
const String body = "{\"value1\":\"You must turn the lights off\"}";
//Server, file, and port
const char HOSTNAME[] = "maker.ifttt.com";
const String URI = "/trigger/" + IFTTT_TRIGGER + "/with/key/"
+ IFTTT_KEY;
const uint8_t PORT = 80;

//WiFiclient object
WiFiClient client;

//Instance object
Button button(BTN_PIN);


void setup() 
{
  //Initialize serial
  Serial.begin(BAUD);
  delay(D_300ms);

  //Connect to the WiFi
  Serial.print("Connecting to: ");
  Serial.println(SSID);
  //Stablish connection with the WiFi
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() == WL_CONNECTED)
  {
    Serial.print('.');
    delay(D_500ms);
  }
  Serial.print("Connected to ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  //I will receive a email when the button is pushed 
  if(button.push() == HIGH)
  {
    //Message to be sent
    String req = "POST " + URI + " HTTP/1.1\r\n" + "Host: " + HOSTNAME 
    + "\r\n" + "Content-Type: application/json\r\n" + "Content-Length: " 
    + body.length() + "\r\n" + "Connection: close\r\n" + "\r\n" +
    body + "\r\n";

    //Connect to server (Stablish TPC connection with the server)
    if(client.connect(HOSTNAME, PORT) == 1)
    {
      Serial.println("Connection successful");
    }
    else
    {
      Serial.println("Connection failed");
    }

    //Send the information to IFTTT to send the email
    client.print(req);
    delay(D_500ms);
    //Print reply from server
    while(client.available())
    {
      String ln = client.readStringUntil('\r');
      Serial.print(ln);
    }

    //Close TPC connection
    client.stop();
    Serial.println();
    Serial.println("Connection closed");
  }

}