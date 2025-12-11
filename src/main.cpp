#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // Reset pin není potřeba při I²C

// Standardní I²C adresy pro většinu 128x64 OLEDů: 0x3C nebo 0x3D
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Zkus nejdřív adresu 0x3C (nejčastější)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    // Pokud selže, zkus 0x3D
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) {
      Serial.println(F("OLED nenalezen! Zkontroluj zapojení."));
      for(;;); // zastav program
    }
  }

  display.clearDisplay();
  display.setTextSize(2);             // velikost textu
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15, 20);          // x, y
  display.println(F("Arduino"));

  display.setTextSize(1);
  display.setCursor(28, 50);
  display.println(F("PlatformIO"));

  display.display();                  // teprve teď se zobrazí na displeji
}

void loop() {
  // tady můžeš později přidat animace, čidla atd.
  // prozatím nic – statický text
}