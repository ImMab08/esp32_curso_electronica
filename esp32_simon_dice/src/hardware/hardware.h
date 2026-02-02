#ifndef HARDWARE_H
#define HARDWARE_H

#include <Arduino.h>

// Definición de pines.
const int pinRojo = 5;
const int pinAmarillo = 19;
const int pinVerde = 18;
const int pinAzul = 21;
const int pinBuzzer = 23;

const int buzzerChannel = 0;

// Frecuencias.
#define TONE_ROJO     1000
#define TONE_VERDE     800
#define TONE_AMARILLO  600
#define TONE_AZUL      400

// Funciones.
void playTone(int freq);
void stopTone();
void setupHardware();
void handleLEDs(String msg);

#endif