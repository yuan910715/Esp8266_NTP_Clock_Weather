#include <DS18B20.h>

DS18B20 ds(2);

void setup() {
  Serial.begin(9600);
  Serial.print("Devices: ");
  Serial.println(ds.getNumberOfDevices());
  Serial.println();
}

void loop() {
  while (ds.selectNext()) {
    switch (ds.getFamilyCode()) {
      case MODEL_DS18S20:
        Serial.println("Model: DS18S20/DS1820");
        break;
      case MODEL_DS1822:
        Serial.println("Model: DS1822");
        break;
      case MODEL_DS18B20:
        Serial.println("Model: DS18B20");
        break;
      default:
        Serial.println("Unrecognized Device");
        break;
    }

    uint8_t address[8];
    ds.getAddress(address);

    Serial.print("Address:");
    for (uint8_t i = 0; i < 8; i++) {
      Serial.print(" ");
      Serial.print(address[i]);
    }
    Serial.println();

    Serial.print("Resolution: ");
    Serial.println(ds.getResolution());

    Serial.print("Power Mode: ");
    if (ds.getPowerMode()) {
      Serial.println("External");
    } else {
      Serial.println("Parasite");
    }

    Serial.print("Temperature: ");
    Serial.print(ds.getTempC());
    Serial.print(" C / ");
    Serial.print(ds.getTempF());
    Serial.println(" F");
    Serial.println();
  }

  delay(10000);
}
