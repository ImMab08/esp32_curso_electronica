#include <Arduino.h>
#include <NewPing.h>

constexpr int PIN_ECHO = 21;
constexpr int PIN_TRIG = 19;
constexpr int BUZZER = 18;

constexpr int MAX_DISTANCE = 200; // cm
constexpr int DISTANCIA_MAX = 50; // cm

NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);

void beep(int delayTime) {
  digitalWrite(BUZZER, HIGH);
  delay(50);
  digitalWrite(BUZZER, LOW);
  delay(delayTime);
}

void setup() {

  Serial.begin(115200);
  pinMode(BUZZER, OUTPUT);

}

void loop() {

  delay(500);
  int distance = sonar.ping_cm();

  if (distance == 0)
  {
    Serial.println("Fuera de rango");
    digitalWrite(BUZZER, LOW);
    return;
  }

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 3)
  {
    // Pitido constante (muy cerca)
    digitalWrite(BUZZER, HIGH);
  }
  else if (distance <= 10)
  {
    // Muy rápido
    beep(50);
  }
  else if (distance <= 20)
  {
    // Rápido
    beep(150);
  }
  else if (distance <= 35)
  {
    // Medio
    beep(300);
  }
  else if (distance <= DISTANCIA_MAX)
  {
    // Lento
    beep(600);
  }
  else
  {
    // Lejos → silencio
    digitalWrite(BUZZER, LOW);
    delay(100);
  }
}