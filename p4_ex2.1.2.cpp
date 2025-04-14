#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definició de pins I2C per a ESP32-S3
#define SDA_PIN 8
#define SCL_PIN 9

// Configuració del display OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // No cal reset físic
#define SCREEN_ADDRESS 0x3C  // Adreça I2C del display

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Definició de la imatge bitmap (32x32 píxels)
static const unsigned char PROGMEM logo_bmp[] = {
  B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000,
  B00011000, B00011000, B00011000, B00011000,
  B00011000, B00011000, B00011000, B00011000,
  B00011100, B00111100, B00111100, B00111100,
  B00011100, B00011100, B00011100, B00011100,
  B00011000, B00011000, B00011000, B00011000,
  B00000000, B00000000, B00000000, B00000000
};

// Declaració de la funció testdrawbitmap()
void testdrawbitmap(void);

void setup() {
  // Inicialitzar comunicació I2C
  Wire.begin(SDA_PIN, SCL_PIN);

  // Inicialitzar Serial per depuració
  Serial.begin(115200);
  Serial.println("Iniciant OLED...");

  // Inicialitzar display OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("Error: No s'ha trobat el display SSD1306!");
    while (true); // Atura execució si no detecta el display
  }

  Serial.println("OLED inicialitzat correctament.");

  // Esborra la pantalla
  display.clearDisplay();
  
  // Espera 2 segons abans de mostrar la imatge
  delay(2000);  

  // Cridar la funció per mostrar la imatge
  testdrawbitmap();
}

void loop() {
  // No cal fer res a loop en aquest exemple
}

// Funció per mostrar la imatge bitmap
void testdrawbitmap(void) {
  display.clearDisplay();  // Esborra la pantalla abans de dibuixar la imatge
  // Dibuixar la imatge bitmap centrada a la pantalla
  display.drawBitmap(
    (display.width() - 32) / 2, // X: centrat per a 32 píxels
    (display.height() - 32) / 2, // Y: centrat per a 32 píxels
    logo_bmp,                    // El bitmap a dibuixar
    32,                          // Amplada de la imatge en píxels
    32,                          // Altura de la imatge en píxels
    SSD1306_WHITE                // Color de la imatge (blanc)
  );
  display.display();  // Mostrar la imatge a la pantalla
}
