// UNIVERSAL SETUP

#include <Adafruit_NeoPixel.h>
#include <LightConfig.h>
#include <Colors.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LIGHTS, PIN_NUMBER, NEO_GRB + NEO_KHZ800);

// PROGRAM-SPECIFIC VARIABLE DEFINITIONS

#define num_elements(x)  (sizeof(x) / sizeof((x)[0]))
#define START_LED 0
#define END_LED 0


// PROGRAM

void setup() {
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  for (int i = 0; i < NUM_LIGHTS; i++) {
    strip.setPixelColor(i, SKY);
    strip.show();
    delay(100);
  }
}
