
#include <Arduino.h>

void setup()
{
  // LEDs
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);

  // Botones (pull-up interno)
  // pinMode(botonRojo, INPUT_PULLUP);
  pinMode(botonAmarillo, INPUT_PULLUP);
  pinMode(botonVerde, INPUT_PULLUP);
  pinMode(botonAzul, INPUT_PULLUP);

  ledcSetup(0, 2000, 8);
  ledcAttachPin(23, 0);
}

void loop()
{
  // digitalWrite(pinRojo, digitalRead(botonRojo) == LOW);
  digitalWrite(pinAmarillo, digitalRead(botonAmarillo) == LOW);
  digitalWrite(pinVerde, digitalRead(botonVerde) == LOW);
  digitalWrite(pinAzul, digitalRead(botonAzul) == LOW);

  playMelody();
  delay(500);
}


const int pinRojo = 5;
const int pinVerde = 18;
const int pinAmarillo = 19;
const int pinAzul= 21;

void setup() {
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinAzul, OUTPUT);
}

void loop() {
  digitalWrite(pinRojo, HIGH);
  delay(500);
  digitalWrite(pinAmarillo, HIGH);
  delay(500);
  digitalWrite(pinVerde, HIGH);
  delay(500);
  digitalWrite(pinAzul, HIGH);
  delay(500);

  digitalWrite(pinRojo, LOW);
  delay(500);
  digitalWrite(pinAmarillo, LOW);
  delay(500);
  digitalWrite(pinVerde, LOW);
  delay(500);
  digitalWrite(pinAzul, LOW);
  delay(500);
}

#include <Arduino.h>

const int buzzerPin = 5;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(buzzerPin, HIGH);
  delay(500);
  digitalWrite(buzzerPin, LOW);
  delay(500);
}