#include <hardware/hardware.h>

// Protoboard.
void setupHardware() {

  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinAzul, OUTPUT);

  ledcSetup(buzzerChannel, 2000, 8);
  ledcAttachPin(pinBuzzer, buzzerChannel);

}

// Funciones para el zumbador.
void playTone(int freq) {
  ledcWriteTone(buzzerChannel, freq);
}

void stopTone() {
  ledcWriteTone(buzzerChannel, 0);
}

// Oprimir los botones.
void handleLEDs(String msg) {
  if (msg == "rojo:on") {
    digitalWrite(pinRojo, HIGH);
    playTone(TONE_ROJO);
  }

  else if (msg == "rojo:off") {
    digitalWrite(pinRojo, LOW);
    stopTone();
  }

  else if (msg == "verde:on") {
    digitalWrite(pinVerde, HIGH);
    playTone(TONE_VERDE);
  }

  else if (msg == "verde:off") {
    digitalWrite(pinVerde, LOW);
    stopTone();
  }

  else if (msg == "amarillo:on") {
    digitalWrite(pinAmarillo, HIGH);
    playTone(TONE_AMARILLO);
  }

  else if (msg == "amarillo:off") {
    digitalWrite(pinAmarillo, LOW);
    stopTone();
  }

  else if (msg == "azul:on") {
    digitalWrite(pinAzul, HIGH);
    playTone(TONE_AZUL);
  }

  else if (msg == "azul:off") {
    digitalWrite(pinAzul, LOW);
    stopTone();
  }
}