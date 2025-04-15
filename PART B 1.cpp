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

  // Mostrar text al display
  display.setTextSize(3);               
  display.setTextColor(SSD1306_WHITE);  
  display.setCursor(10, 10);            
  display.println("Ana i Txell");      

  // Mostrar la pantalla
  display.display();
}

void loop() {
  // No cal fer res a loop en aquest exemple
}
