// YD-ESP32-S3 — minimal UART hello via CH343
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println();
  Serial.println("YD-ESP32-S3 hello");
  Serial.printf("Chip: %s, cores: %d\n", ESP.getChipModel(), ESP.getChipCores());
}

void loop() {
  Serial.printf("uptime_ms=%lu\n", millis());
  delay(1000);
}
