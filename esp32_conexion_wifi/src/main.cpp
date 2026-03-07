#include <WiFi.h>
#include <Arduino.h>
#include <U8g2lib.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

constexpr const char* ssid = "After_School_Wff_24G";
constexpr const char* password = "@nM1Pk93m$";

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

void page() {
  u8g2.setFont(u8g2_font_timR10_tf);
  u8g2.setFontPosTop();
  
  u8g2.setCursor(0, 0);
  u8g2.print("WiFi conectado");

  u8g2.setCursor(0, 20);
  u8g2.print("IP: ");
  
  u8g2.setCursor(0, 35);
  u8g2.print(WiFi.localIP());
}

void setup() {

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Conectando a Wifi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("¡WiFi Conectado!");
  Serial.print("IP: ");
  Serial.print(WiFi.localIP());

  u8g2.setI2CAddress(0x3C*2);
  u8g2.begin();
  u8g2.enableUTF8Print();

}


void loop() {

  u8g2.firstPage();
  do {
    page();
  } while (u8g2.nextPage());
  
}