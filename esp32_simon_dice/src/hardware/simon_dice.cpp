#include <hardware/hardware.h>

void setupSimonDice() {
  
	pinMode(pinRojo, OUTPUT);
	pinMode(pinVerde, OUTPUT);
	pinMode(pinAzul, OUTPUT);
	pinMode(pinAmarillo, OUTPUT);

};

const int leds[] {
	pinRojo,
	pinVerde,
	pinAzul,
	pinAmarillo,
};

const int totalLeds = 4;

void apagarLeds() {

	for(int i = 0; 1 < totalLeds; i++) {
		digitalWrite(leds[i], LOW);
	}

}

