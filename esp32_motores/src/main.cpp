#include <Arduino.h>
#include <BluetoothSerial.h>
#include "DHT.h"

// Bluetooth
// Objeto
BluetoothSerial btSerial;

// Led
constexpr int LED_PIN = 19;
constexpr int DHT_PIN = 21;
constexpr int DHT_TYPE = DHT11;

// Función para definir el pin
// de señal 
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  
  Serial.begin(115200);
  btSerial.begin("Alexis_pollo");
  Serial.println("Bluetooth iniciado: Listo para emparejar");

  // pinMode(LED_PIN, OUTPUT);
  // dht.begin();

}

void loop() {

  btSerial.println("Hola mundo desde ESP32");
  
//   float temp = dht.readTemperature();
//   if ( temp >= 30) {
//     digitalWrite(LED_PIN, HIGH);
//   } else {
//     digitalWrite(LED_PIN, LOW);
//   }

//   Serial.println(temp);
//   delay(2000);

}