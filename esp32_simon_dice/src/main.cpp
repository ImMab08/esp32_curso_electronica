#include <Arduino.h>

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "hardware/hardware.h"
#include "web_server/web_server.h"

// Server + WebSocket
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void onWebSocketEvent(
  AsyncWebSocket *server,
  AsyncWebSocketClient *client,
  AwsEventType type,
  void *arg,
  uint8_t *data,
  size_t len
) {
  if (type == WS_EVT_DATA) {
    String msg = "";

    for (size_t i = 0; i < len; i++) {
      msg += (char)data[i];
    };

    handleLEDs(msg);
  }
}

void setup() {
  Serial.begin(115200);

  // setupHardware();
  // setupNetwork();

  randomSeed(analogRead(0));

  ws.onEvent(onWebSocketEvent);
  server.addHandler(&ws);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/html", index_html);
  });

  server.begin();
}

void loop() {};