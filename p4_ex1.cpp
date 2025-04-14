#include <Arduino.h>
#include <Wire.h>

#define SDA_PIN  8  // Elige el pin SDA que prefieras
#define SCL_PIN  9 // Elige el pin SCL que prefieras

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN); // Configura los pines SDA y SCL elegidos
  Serial.begin(115200);
  while (!Serial); // Espera a que se abra el puerto serial
  Serial.println("\nI2C Scanner");
}

void loop() {
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found");
  } else {
    Serial.println("done");
  }
  delay(5000); // Espera 5 segundos para el siguiente escaneo
}
