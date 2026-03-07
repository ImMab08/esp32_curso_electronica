#include <WiFi.h>
#include <Arduino.h>
#include <WebServer.h>

#include <page.h>

constexpr const char *ssid = "After_School_Wff_24G";
constexpr const char *password = "@nM1Pk93m$";

WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", index_html );
}

void setup() {

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Conectando...");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.begin();
}

void loop() {

  server.handleClient();

}