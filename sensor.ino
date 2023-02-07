#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

#define HTTP_PORT 2301
ESP8266WebServer server(HTTP_PORT);

const char* ssid = "your-ssid";
const char* password = "your-pw";

int sensorValue = 0;

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println("");

    while (WiFi.status() != WL_CONNECTED) {
      Serial.print("."); 
      delay(500);
    }

    if (MDNS.begin("esp8266")) {
      Serial.println("MDNS responder started");
    }

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    
    handleServerRouting();
    server.begin();
}
void loop() {
    sensorValue = analogRead(A0);
    delay(500);
    server.handleClient();
}

void handleServerRouting() {
  server.on("/", HTTP_GET, []() {
      String response = "";
      response += "{\"d\":\"" + String(sensorValue) + " \"}";
      server.send(200, F("application/json"), response);
  });
}
