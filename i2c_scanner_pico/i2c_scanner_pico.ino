/*
 * I2C Scanner for Raspberry Pi Pico (Arduino IDE)
 * Scans addresses 0x08 - 0x77 and reports any device that ACKs.
 *
 * Default Wire pins on Pico (Arduino-Pico core):
 *   SDA = GP4
 *   SCL = GP5
 * Change below with Wire.setSDA()/setSCL() if you're wired differently.
 */

#include <Wire.h>

void setup() {
  // Uncomment and edit if you're using non-default pins:
  // Wire.setSDA(4);
  // Wire.setSCL(5);

  Wire.begin();
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }
  delay(1000);
  Serial.println("\nI2C Scanner starting...");
}

void loop() {
  byte error, address;
  int devicesFound = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");
      devicesFound++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (devicesFound == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.print(devicesFound);
    Serial.println(" device(s) found\n");
  }

  delay(3000); // wait 3 seconds before scanning again
}
