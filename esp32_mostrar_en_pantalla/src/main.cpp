#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <NewPing.h>
#include <SPI.h>

// Definir pines - Sensor
constexpr int PIN_TRIG = 12; // Envia un ultrasonido
constexpr int PIN_ECHO = 13; // Recibe al sensor

constexpr int MAX_DISTANCE = 200; // cm
constexpr int DISTANCE_MAX = 50;  // cm

// Crear objeto para medir distancia
NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);

// Definir los pines - Pantalla
constexpr int TFT_CS = 5;
constexpr int TFT_DC = 2;
constexpr int TFT_RES = 4;
constexpr int TFT_SDA = 23;
constexpr int TFT_SCL = 18;

// Crear objeto en pantalla
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RES);

// Control de tiempo
unsigned long lastUpdate = 0;
const unsigned long interval = 150;

void dibujarBarrita(int distancia)
{
    if (distancia > DISTANCE_MAX)
        distancia = DISTANCE_MAX;

    int anchoBarrita = map(distancia, 0, DISTANCE_MAX, 140, 0);

    // Color según próximidad
    uint16_t color;
    if (distancia < 10)
        color = ST77XX_RED;
    else if (distancia < 25)
        color = ST77XX_YELLOW;
    else
        color = ST77XX_GREEN;

    // Fondo de la barra (marco)
    tft.drawRect(10, 70, 140, 20, ST77XX_BLACK);

    // Limpiar inferior
    tft.fillRect(11, 71, 138, 18, ST77XX_WHITE);

    // Dibujar barra dinamica
    tft.fillRect(11, 71, anchoBarrita, 18, color);
}

void setup()
{

    Serial.begin(115200);
    
    pinMode(PIN_TRIG, OUTPUT);
    pinMode(PIN_ECHO, INPUT);
    
    SPI.begin(18, -1, 23, TFT_CS);

    // Inicializar pantalla
    tft.initR(INITR_BLACKTAB);
    
    // Limpiar pantalla
    tft.setRotation(1);
    tft.fillScreen(ST77XX_WHITE);

    // Configurar texto
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.println("Distancia: ");
}

void loop()
{

    unsigned long currentMililis = millis();

    if (currentMililis - lastUpdate >= interval)
    {
        lastUpdate = currentMililis;
        delay(500);
        int distancia = sonar.ping_cm();

        if (distancia == 0)
            distancia = MAX_DISTANCE;

        Serial.print("Distancia: ");
        Serial.println(distancia);

        // Limpiar zona del número
        tft.fillRect(10, 20, 140, 30, ST77XX_BLACK);

        tft.setCursor(10, 10);
        tft.setTextColor(ST77XX_WHITE);
        tft.setTextSize(2);
        tft.print(distancia);
        tft.print(" cm");

        dibujarBarrita(distancia);
    }
}