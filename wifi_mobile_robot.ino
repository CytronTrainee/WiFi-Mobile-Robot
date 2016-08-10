#include <CytronWiFiShield.h>
#include <CytronWiFiServer.h>
#include <SoftwareSerial.h>
#define WiFi wifi
 
const char ssid[] = "CytronESPShield";  // your network SSID (name)
const char pass[] = "RobotHeadToToe";   // your network password
int keyIndex = 0;    // your network key Index number (needed only for WEP)
 
 int RightEn  = 5;
 int RightDir = 4;
 int LeftEn   = 6;
 int LeftDir  = 7;
 
ESP8266Server server(80);
bool status = false;
 
void setup() {
Serial.begin(115200); // initialize serial communication 
 
 //Motor Driver Pin Setup
 pinMode(RightEn,OUTPUT);
 pinMode(RightDir,OUTPUT);
 pinMode(LeftEn,OUTPUT);
 pinMode(LeftDir,OUTPUT);
 
 // check for the presence of the shield:
 if (!WiFi.begin(2, 3)) {
 Serial.println("WiFi shield not present");
 while (true); // don't continue
 }
 
 String fv = WiFi.firmwareVersion();
 Serial.println(fv);
 
 // attempt to connect to Wifi network:
 WiFi.setMode(WIFI_AP);
 if(!WiFi.softAP(ssid, pass))
 //if(!WiFi.softAP(ssid, pass, 5, WPA_PSK)) // use WPA encryption
 Serial.println("Setting softAP failed");
 Serial.println(WiFi.softAPIP());
 server.begin(); // start the web server on port 80
}
 
void loop() {
 ESP8266Client client = server.available(); // listen for incoming clients
 
 while(client.available())
 {
 if (client.connected()) //if client is present and connected
 {
 char c = client.read(); // reads the http request
 
 if(c=='F')
 {
 c==8;
 c==0;
 Serial.println("FORWARD");
 
 digitalWrite(RightDir,HIGH);
 digitalWrite(LeftDir,LOW);
 analogWrite(RightEn, 255); //PWM Speed Control
 analogWrite(LeftEn, 255);  //PWM Speed Control
 }
 
 else if(c=='B')
 {
 c==8;
 c==0;
 Serial.println("REVERSE");
 
 digitalWrite(RightDir,LOW);
 digitalWrite(LeftDir,HIGH);
 analogWrite(RightEn, 200); //PWM Speed Control
 analogWrite(LeftEn, 200);  //PWM Speed Control
 } 
 
 else if(c=='L')
 {
 c==4;
 c==0;
 Serial.println("LEFT");
 
 digitalWrite(RightDir,HIGH);
 digitalWrite(LeftDir,LOW);
 analogWrite(RightEn, 0);   //PWM Speed Control
 analogWrite(LeftEn, 255);  //PWM Speed Control
 } 
 
 else if(c=='R')
 {
 c==4;
 c==0;
 Serial.println("RIGHT");
 
 digitalWrite(RightDir,HIGH);
 digitalWrite(LeftDir,LOW);
 analogWrite(RightEn,255);  //PWM Speed Control
 analogWrite(LeftEn, 0);    //PWM Speed Control
 } 
 
 else if(c=='S')
 {
 c==0;
 digitalWrite(RightEn,0);   //PWM Speed Control
 digitalWrite(LeftEn, 0);   //PWM Speed Control
 }
 }
 }
}
