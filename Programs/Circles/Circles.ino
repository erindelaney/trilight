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

int getIndexFromOrigin(int circle_num , int i){
  int origin_index;
  int start_index; 
  if (circle_num == 1){
    origin_index = 85;
    start_index = 70;
  } else if (circle_num == 2){
    origin_index = 185;
    start_index = 170;
  } else if (circle_num == 0){
    origin_index = 52;
    start_index = 1;
  }
  
  if (i + origin_index > start_index + 68){
     return i + origin_index - 68;
    } else {
      return i + origin_index;
    }
}


void loop() {
  for (int i = 0; i < 69; i++) {
    strip.setPixelColor(getIndexFromOrigin(1, i), SKY);
    strip.setPixelColor(getIndexFromOrigin(0, i), SKY);
    strip.setPixelColor(getIndexFromOrigin(2, i), SKY);

    strip.show();
    delay(50);
    strip.setPixelColor(getIndexFromOrigin(0, i), BLACK);
    strip.setPixelColor(getIndexFromOrigin(1, i), BLACK);
    strip.setPixelColor(getIndexFromOrigin(2, i), BLACK);
  }
}
