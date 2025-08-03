#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define BUTTON_PIN 8

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

unsigned long timeSinceLastPress = 0.0;
int count = 0;
unsigned long currentMillis;
String strin;

void updateDisplay(int &count);
void updateCount(int &count);

void setup(void) {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  pinMode(BUTTON_PIN, INPUT);
  u8g2.begin();
}

void loop() {
  currentMillis = millis();
  if (currentMillis - timeSinceLastPress > 10000) {
    count = 0;
    timeSinceLastPress = 0.0;
  }
  updateCount(count);
  updateDisplay(count);
}

void updateDisplay(int &count) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  strin = "Count: " + String(count).c_str() + "; CPS = " + String(count / 10.0, 2).c_str();
  u8g2.drawStr(0, 10, strin);
  u8g2.sendBuffer();
}

void updateCount(int &count) {
  if (digitalRead(BUTTON_PIN) == HIGH) {

  }
}

