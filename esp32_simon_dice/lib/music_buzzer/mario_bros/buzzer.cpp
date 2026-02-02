#include <Arduino.h>

#include "buzzer.h"
#include "melody_mario_bros.h"

#define BUZZER_PIN 23
#define CANAL 0

void playTone(int freq, int duration) {
  if (freq == 0) {
    ledcWriteTone(CANAL, 0);
  } else {
    ledcWriteTone(CANAL, freq);
  }
  delay(duration);
  ledcWriteTone(CANAL, 0);
}

void playMelody() {
  int tempo = 900;

  for (int i = 0; i < melodySize; i++) {
    int noteDuration = tempo / noteDurations[i];
    playTone(melody[i], noteDuration);
    delay(noteDuration * 0.3);
  }
}
