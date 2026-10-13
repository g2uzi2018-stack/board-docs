// Print Flash / PSRAM sizes to verify module variant (N8R8 / N16R8; verify silk if odd)
void setup() {
  Serial.begin(115200);
  delay(800);
  Serial.println();
  Serial.println("=== ESP32-S3 memory check ===");
  Serial.printf("Chip model : %s rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
  Serial.printf("CPU freq   : %u MHz\n", ESP.getCpuFreqMHz());
  Serial.printf("Flash size : %u bytes (%.2f MB)\n",
                ESP.getFlashChipSize(), ESP.getFlashChipSize() / (1024.0 * 1024.0));
  Serial.printf("Sketch     : %u bytes\n", ESP.getSketchSize());
  Serial.printf("Free heap  : %u bytes\n", ESP.getFreeHeap());

#if defined(BOARD_HAS_PSRAM) || defined(CONFIG_SPIRAM)
  Serial.printf("PSRAM size : %u bytes (%.2f MB)\n",
                ESP.getPsramSize(), ESP.getPsramSize() / (1024.0 * 1024.0));
  Serial.printf("Free PSRAM : %u bytes\n", ESP.getFreePsram());
#else
  // Still try getters; returns 0 if PSRAM not enabled in board options
  Serial.printf("PSRAM size : %u bytes (%.2f MB) — enable OPI/Octal PSRAM in board options if 0\n",
                ESP.getPsramSize(), ESP.getPsramSize() / (1024.0 * 1024.0));
#endif

  Serial.println();
  Serial.println("Naming hint:");
  Serial.println("  ~8MB flash + ~8MB PSRAM  => N8R8");
  Serial.println("  ~16MB flash + ~8MB PSRAM => N16R8 (common YD SKU)");
  Serial.println("  ~8MB flash + ~16MB PSRAM => N8R16 (rare / verify silk)");
}

void loop() {}
