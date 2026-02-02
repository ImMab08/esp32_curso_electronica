#include <Arduino.h>

// Leds
const int ledAmarillo = 19;
const int ledAzul = 21;
const int ledVerde = 18;
const int ledRojo = 5;

// Potenciometro
const int potenciometro = 4;
int potenciometroRead = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
}

void loop()
{

  potenciometroRead = analogRead(potenciometro);
  Serial.print("POTENCIOMETRO: ");
  Serial.println(potenciometroRead);
  delay(1000);

  if (potenciometroRead >= 1 && potenciometroRead <= 1023)
  {
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, LOW);
  }
  else if (potenciometroRead >= 1023 && potenciometroRead <= 2046)
  {
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, LOW);
  }
  else if (potenciometroRead >= 2046 && potenciometroRead <= 3069)
  {
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, LOW);
  }
  else if (potenciometroRead >= 3069 && potenciometroRead <= 4095)
  {
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, HIGH);
  }
  else
  {
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, LOW);
  }
}