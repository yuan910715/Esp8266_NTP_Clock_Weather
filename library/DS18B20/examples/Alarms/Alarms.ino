#include <DS18B20.h>

#define LOW_ALARM 20
#define HIGH_ALARM 25

DS18B20 ds(2);

void setup() {
  Serial.begin(9600);

  while (ds.selectNext()) {
    ds.setAlarms(LOW_ALARM, HIGH_ALARM);
  }
}

void loop() {
  ds.doConversion();

  while (ds.selectNextAlarm()) {
    Serial.print("Alarm Low: ");
    Serial.print(ds.getAlarmLow());
    Serial.println(" C");
    Serial.print("Alarm High: ");
    Serial.print(ds.getAlarmHigh());
    Serial.println(" C");
    Serial.print("Temperature: ");
    Serial.print(ds.getTempC());
    Serial.println(" C\n");
  }

  delay(10000);
}
