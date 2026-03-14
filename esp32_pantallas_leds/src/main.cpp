#include <Arduino.h>
#include <U8g2lib.h>

#define SCREEN_WIDTH 128;
#define SCREEN_HEIGHT 64;

U8G2_SSD1306_128X64_NONAME_F_HW_I2C pantalla(U8G2_R0, U8X8_PIN_NONE);

void setup() {
  Serial.begin(115200);
  pantalla.begin();
}

void loop() {

  pantalla.setFont(u8g2_font_04b_03_tr);
  pantalla.drawStr(0, 10, "Hola mundo");
  
  pantalla.drawFrame(0, 20, 128, 44);

  pantalla.sendBuffer();
  delay(5000);


  pantalla.clearBuffer();
  pantalla.drawStr(20, 20, "Alexis pollo");

  pantalla.sendBuffer();

}