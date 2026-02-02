#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include <ESPAsyncWebServer.h>

void setupNetwork() {
  // Red de internet.
  const char* ssid = "After_School_Wff_24G";
  const char* password = "@nM1Pk93m$";

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("\nWiFi conectado: ");
  Serial.print(WiFi.localIP());
};

const char index_html[] PROGMEM = R"rawliteral(
  <html>
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <title>ESP32 Control</title>      
    </head>

    <body 
      style="
        padding: 0;
        margin: 0;
        box-sizing: border-box;
      "
    >
      <div
        style="
          width: 100%;
          height: 100%;
          display: flex;
          justify-content: center;
          align-items: center;
          flex-direction: column;
        "
      >
          
        <h1>Simón dice</h1>
        <divx
          style="
            width: 100%;
            height: 100%;
            display: flex;
            justify-content: center;
            align-items: center;
            gap: 10px;
          "
        >
          <button 
            onmousedown="send('amarillo:on')" 
            onmouseup="send('amarillo:off')"
            ontouchstart="send('amarillo:on')"
            ontouchend="send('amarillo:off')"
            style="
              width: 50px;
              height: 50px;
              border-radius: 50%;
              background-color: yellow;
              border: none;
            "
          >
          </button>
          <button 
            onmousedown="send('azul:on')" 
            onmouseup="send('azul:off')"
            ontouchstart="send('azul:on')"
            ontouchend="send('azul:off')"
            style="
              width: 50px;
              height: 50px;
              border-radius: 50%;
              background-color: blue;
              border: none;
            "
          >
          </button>
          <button 
            onmousedown="send('verde:on')" 
            onmouseup="send('verde:off')"
            ontouchstart="send('verde:on')"
            ontouchend="send('verde:off')"
            style="
              width: 50px;
              height: 50px;
              border-radius: 50%;
              background-color: green;
              border: none;
            "
          >
          </button>
          <button 
            onmousedown="send('rojo:on')" 
            onmouseup="send('rojo:off')"
            ontouchstart="send('rojo:on')"
            ontouchend="send('rojo:off')"
            style="
              width: 50px;
              height: 50px;
              border-radius: 50%;
              background-color: red;
              border: none;
            "
          >
          </button>
        </divx>      
      </div>

      <script>
        const ws = new WebSocket(`ws://${location.host}/ws`);
        function send(msg) {
          ws.send(msg);
        }
      </script>

    </body>
  </html>
)rawliteral";

#endif