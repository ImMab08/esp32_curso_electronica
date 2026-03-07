#pragma once

const char index_html[] PROGMEM = R"rawliteral(

  <!DOCTYPE html>
  <html lang="es">

    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>ESP32 Control Panel</title>

      <style>

        *{
          box-sizing:border-box;
        }

        body{
          margin:0;
          font-family:Arial, Helvetica, sans-serif;
          background:#0f172a;
          color:white;
          display:flex;
          justify-content:center;
          align-items:center;
          height:100vh;
        }

        .container{
          text-align:center;
          background:#1e293b;
          padding:40px;
          border-radius:12px;
          width:320px;
          box-shadow:0 10px 30px rgba(0,0,0,0.4);
        }

        h1{
          margin-top:0;
        }

        .status{
          margin:15px 0;
          font-size:14px;
          color:#94a3b8;
        }

        .buttons{
          display:flex;
          justify-content:center;
          gap:15px;
          margin-top:20px;
        }

        button{
          border:none;
          padding:12px 18px;
          border-radius:8px;
          font-size:14px;
          cursor:pointer;
          color:white;
          transition:0.2s;
        }

        button:hover{
          transform:scale(1.05);
        }

        .btn-on{
          background:#16a34a;
        }

        .btn-off{
          background:#dc2626;
        }

        .footer{
          margin-top:25px;
          font-size:12px;
          color:#64748b;
        }

      </style>

    </head>

    <body>

      <div class="container">
        <h1>ESP32 Web Server</h1>

        <p class="status">
          Proyecto IoT con ESP32<br>
          Pantalla OLED + WiFi + WebSocket
        </p>

        <div class="buttons">
          <button class="btn-on" onclick="send('led:on')">Encender</button>
          <button class="btn-off" onclick="send('led:off')">Apagar</button>
        </div>

        <div class="footer">
          ESP32 funcionando correctamente
        </div>
      </div>

      <script>
        const ws = new WebSocket(`ws://${location.host}/ws`);

        function send(msg){
          ws.send(msg);
        }

        ws.onopen = () =>{
          console.log("WebSocket conectado");
        }

        ws.onclose = () =>{
          console.log("WebSocket desconectado");
        }
      </script>

    </body>

  </html>

)rawliteral";