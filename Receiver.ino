#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
RF24 radio(9, 10);
const byte address[5] = { 0x12, 0x23, 0x45, 0x67, 0x89 };
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
float list[3];
int b_int = 1;
const unsigned char MarilynMonroe0[] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x30, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x01, 0x80, 0x10, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x80, 0x10, 0x89, 0x06, 0x04, 0x0c, 0x1e, 0x10, 0x38, 0x21, 0x91, 0x8f, 0x10,
  0x89, 0x0f, 0x0f, 0x1e, 0x1f, 0x30, 0x3c, 0x31, 0xb1, 0x8f, 0x90, 0x89, 0x1b, 0x1b, 0x1b, 0x18, 0x30, 0x36, 0x31, 0xf1, 0x83,
  0x10, 0x89, 0x1b, 0x18, 0x18, 0x18, 0x30, 0x36, 0x31, 0xf1, 0x83, 0x10, 0x8f, 0x1b, 0x0e, 0x1f, 0x1c, 0x30, 0x36, 0x31, 0xf1,
  0x86, 0x10, 0x8f, 0x1b, 0x07, 0x1f, 0x1c, 0x30, 0x36, 0x31, 0xf1, 0x86, 0x10, 0x89, 0x1b, 0x0b, 0x1b, 0x18, 0x30, 0x36, 0x31,
  0xf1, 0x8e, 0x10, 0x89, 0x0f, 0x1f, 0x1f, 0x1e, 0x3e, 0x3c, 0x31, 0xb1, 0x8f, 0x10, 0x89, 0x06, 0x0e, 0x0e, 0x1e, 0x1e, 0x3c,
  0x21, 0xb0, 0x87, 0x10, 0x80, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x10, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xf0
};
const unsigned char MarilynMonroe[] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x30, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x60, 0x06, 0x01, 0x00, 0x0c, 0x02, 0x10, 0x00, 0x10, 0x80, 0x00, 0x70, 0x1f, 0x83, 0x80,
  0x1c, 0x07, 0x38, 0x00, 0x10, 0x80, 0x00, 0xf0, 0x3f, 0x83, 0x80, 0x1e, 0x07, 0xb8, 0x00, 0x10, 0x80, 0x00, 0xf0, 0x39, 0x83,
  0x80, 0x1e, 0x07, 0xb8, 0x00, 0x10, 0x80, 0x00, 0xf8, 0x39, 0x83, 0x80, 0x3e, 0x07, 0xb8, 0x00, 0x10, 0x80, 0x00, 0xf8, 0x1c,
  0x03, 0x80, 0x3e, 0x07, 0xf8, 0x00, 0x10, 0x80, 0x01, 0xd8, 0x1f, 0x03, 0x80, 0x37, 0x07, 0xf8, 0x00, 0x10, 0x80, 0x01, 0xd8,
  0x07, 0x83, 0x80, 0x37, 0x07, 0xf8, 0x00, 0x10, 0x80, 0x01, 0xdc, 0x03, 0x83, 0x80, 0x77, 0x07, 0xf8, 0x00, 0x10, 0x80, 0x01,
  0xfc, 0x19, 0x83, 0x80, 0x7f, 0x07, 0x78, 0x00, 0x10, 0x80, 0x03, 0xfc, 0x3f, 0x83, 0xf0, 0x7f, 0x07, 0x78, 0x00, 0x10, 0x80,
  0x03, 0x9c, 0x1f, 0x83, 0xf8, 0x73, 0x87, 0x78, 0x00, 0x10, 0x80, 0x03, 0x8c, 0x0f, 0x03, 0xf0, 0x63, 0x86, 0x38, 0x00, 0x10,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x10, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x10, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xfc, 0x10, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x10, 0x82, 0x43, 0x21, 0x90, 0xd8,
  0x70, 0x38, 0x3c, 0x30, 0x32, 0x10, 0x83, 0xc3, 0x61, 0xf0, 0xd8, 0x78, 0x7c, 0x3c, 0x30, 0x36, 0x10, 0x83, 0xc3, 0x61, 0xf0,
  0xd8, 0xf8, 0x6c, 0x36, 0x30, 0x36, 0x10, 0x83, 0xc3, 0x61, 0xf0, 0xd8, 0x60, 0x6c, 0x70, 0x30, 0x36, 0x10, 0x81, 0x83, 0x61,
  0xf0, 0xd8, 0x70, 0x6c, 0x7e, 0x30, 0x36, 0x10, 0x81, 0x83, 0x61, 0xf0, 0xd8, 0x38, 0x6c, 0x7e, 0x30, 0x36, 0x10, 0x81, 0x83,
  0x61, 0xf0, 0xd8, 0x5c, 0x6c, 0x36, 0x30, 0x36, 0x10, 0x81, 0x83, 0xe1, 0xb0, 0xf8, 0x78, 0x7c, 0x3e, 0x30, 0x3e, 0x10, 0x81,
  0x81, 0xe1, 0xb0, 0x70, 0x78, 0x78, 0x3c, 0x3e, 0x1c, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x10, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xf0
};
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setChannel(0x76);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  radio.enableDynamicPayloads();
  radio.powerUp();
  display.begin();
  display.setContrast(57);
  display.clearDisplay();
}
void loop() {
  if (radio.available()) {
    if (b_int == 1) {
      int b_time = millis();
      do {
        display.display();
        display.clearDisplay();
        display.drawBitmap(0, 0, MarilynMonroe, 84, 48, BLACK);
        display.setTextColor(BLACK);
        display.setCursor(0, 0);
        display.println("Alexander Kibarov");
        display.setTextColor(BLACK);
        display.setCursor(0, 8);
        display.println("Welcome To The Back");
      } while (millis() - b_time < 5000);
      b_time = millis();
      do {
        display.display();
        display.clearDisplay();
        display.drawBitmap(0, 0, MarilynMonroe0, 84, 48, BLACK);
        display.setTextSize(1);
        display.setTextColor(BLACK);
        display.setCursor(0, 0);
        display.println("Alexander Kibarov");
        display.setTextColor(BLACK);
        display.setCursor(0, 8);
        display.println("Welcome To The Back");
        * /
      } while (millis() - b_time < 3000);
      b_int = 5;
    }
    radio.read(list, sizeof(list));
    int okunan = analogRead(A0);
    Serial.println(list[0]);
    Serial.println(list[1]);
    Serial.println(list[2]);
    if (okunan < 512) {
      display.display();
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(BLACK);
      display.setCursor(0, 0);
      display.println("Long: ");
      display.setTextColor(BLACK);
      display.setCursor(0, 8);
      display.println(list[0], 6);
      display.setTextColor(BLACK);
      display.setCursor(0, 16);
      display.println("Lat: ");
      display.setTextColor(BLACK);
      display.setCursor(0, 24);
      display.println(list[1], 6);
      display.display();
      display.clearDisplay();
    } else {
      display.display();
      display.clearDisplay();
      while (okunan >= 512) {
        for (int i = 84; i >= 0; i--) {
          okunan = analogRead(A0);
          radio.read(list, sizeof(list));
          if (list[2] >= 500) {
            list[2] = 500;
          }
          if (list[2] <= 20) {
            list[2] = 0;
          }
          list[2] = map(list[2], 0, 500, 0, 48);
          for (int j = 0; j <= 48; j++) {
            if (j < list[2]) {
              display.setTextSize(1);
              display.setTextColor(BLACK);
              display.setCursor(i, j);
              display.println(".");
              display.display();
            } else {
              display.setTextSize(1);
              display.setTextColor(WHITE);
              display.setCursor(i, j);
              display.println(".");
              display.display();
            }
          }
        }
        display.clearDisplay();
      }
      display.display();
      display.clearDisplay();
    }
  } else {
    display.display();
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0, 0);
    display.println("No signal");
    display.display();
    display.clearDisplay();
  }
}
