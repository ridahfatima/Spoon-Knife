
 #include <DHT.h>  
 #include <ESP8266WiFi.h>  
 #include <WiFiClient.h>  
 #include <ThingSpeak.h>    
 const char* ssid = "Nope.";  // SSID
 const char* password = "ayesha12";  // Password
 WiFiClient client;  
 unsigned long myChannelNumber = 448106; // your Channel ID 
 const char * myWriteAPIKey = "VAXYL5PYXIQV5LWL";  // Your API Key 
 void setup()  
 {  
  Serial.begin(9600);  
    
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
 }  
 void loop()   
 {  
   int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(50);     
   ThingSpeak.writeField(myChannelNumber, 1, sensorValue, myWriteAPIKey);  
   delay(300);
 }  

