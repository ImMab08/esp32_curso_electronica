#include <Arduino.h>

// Leds
const int ledAmarillo = 19;
const int ledAzul = 21;
const int ledVerde = 18;
const int ledRojo = 5;

// Sensor de humedad
int sensorHumedad = 4;
int readSensorHumedad = 0;

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

	readSensorHumedad = analogRead(sensorHumedad);
	Serial.print("SENTOR: ");
	Serial.println(readSensorHumedad);
	delay(1000);

	if (readSensorHumedad >= 4000 && readSensorHumedad < 4095)
	{
		digitalWrite(ledRojo, HIGH);
		digitalWrite(ledVerde, LOW);
		digitalWrite(ledAzul, LOW);
		digitalWrite(ledAmarillo, LOW);
	}
	else if (readSensorHumedad >= 3000 && readSensorHumedad <= 4000)
	{
		digitalWrite(ledRojo, HIGH);
		digitalWrite(ledVerde, HIGH);
		digitalWrite(ledAzul, LOW);
		digitalWrite(ledAmarillo, LOW);
	}
	else if (readSensorHumedad >= 2000 && readSensorHumedad <= 3000)
	{
		digitalWrite(ledRojo, HIGH);
		digitalWrite(ledVerde, HIGH);
		digitalWrite(ledAzul, HIGH);
		digitalWrite(ledAmarillo, LOW);
	}
	else if (readSensorHumedad >= 0 && readSensorHumedad <= 2000)
	{
		digitalWrite(ledRojo, HIGH);
		digitalWrite(ledVerde, HIGH);
		digitalWrite(ledAzul, HIGH);
		digitalWrite(ledAmarillo, HIGH);
	}
	else
	{
		digitalWrite(ledRojo, LOW);
		digitalWrite(ledVerde, LOW);
		digitalWrite(ledAzul, LOW);
		digitalWrite(ledAmarillo, LOW);
	}
}