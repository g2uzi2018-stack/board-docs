// YD-ESP32-S3 — onboard WS2812 on GPIO48
// Library: Tools → Manage Libraries → "Adafruit NeoPixel"
#include <Adafruit_NeoPixel.h>

#define LED_PIN 48
#define LED_COUNT 1

Adafruit_NeoPixel pixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  pixel.begin();
  pixel.setBrightness(32);  // keep low
  pixel.show();
  Serial.println("RGB GPIO48 ready");
}

void loop() {
  pixel.setPixelColor(0, pixel.Color(32, 0, 0));
  pixel.show();
  delay(400);
  pixel.setPixelColor(0, pixel.Color(0, 32, 0));
  pixel.show();
  delay(400);
  pixel.setPixelColor(0, pixel.Color(0, 0, 32));
  pixel.show();
  delay(400);
  pixel.clear();
  pixel.show();
  delay(400);
}
