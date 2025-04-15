#include <Arduino.h>
#include <Wire.h>

#define SDA_PIN  8  // Tria el pin SDA que prefereixis
#define SCL_PIN  9  // Tria el pin SCL que prefereixis

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN); // Configura els pins SDA i SCL triats
  Serial.begin(115200);
  while (!Serial); // Espera que s'obri el port sèrie
  Serial.println("\nEscàner I2C");
}

void loop() {
  byte error, address;
  int nDevices;
  Serial.println("Escanejant...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("Dispositiu I2C trobat a l'adreça 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    } else if (error == 4) {
      Serial.print("Error desconegut a l'adreça 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No s'han trobat dispositius I2C");
  } else {
    Serial.println("fet");
  }
  delay(5000); // Espera 5 segons abans del següent escaneig
}
