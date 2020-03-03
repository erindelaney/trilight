// UNIVERSAL SETUP

#include <Adafruit_NeoPixel.h>
#include <LightConfig.h>
#include <Colors.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LIGHTS, PIN_NUMBER, NEO_GRB + NEO_KHZ800);

// PROGRAM-SPECIFIC VARIABLE DEFINITIONS

#define num_elements(x)  (sizeof(x) / sizeof((x)[0]))
#define START_LED 0
#define END_LED 0



int spark_location[4] = {};

int circles [] = { 0, 1, 2 };
int num_circles = 3; 
int start_index [] = {1, 70, 170};
int origin_index [] = {51, 85, 186};

// TO DO
// 1. switch to using arrays in direction functions
// 2. use global vars for start and origin indicies


// PROGRAM

void setup() {
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
 
  
  for (int ii = 0; ii < 4; ii++) {
    spark_location[ii] = 10*ii;

}
}

int forwardCircleOrigin(int s , int i){
    if (i + origin_index[s] > start_index[s] + 68){
       return i + origin_index[s] - 68;
      } else {
        return i + origin_index[s];
      }
}

int reverseCircleOrigin(int s , int i){
    if (origin_index[s] - i < start_index[s]){
       return origin_index[s] - i + 68;
    } else {
      return origin_index[s] - i;
    }
}





void loop() {
//  uint32_t random = rand() % 3;
  for (int i = 0; i < 35; i++) {
    for (int a = 0; a < num_circles; a++) {
        for (int ii = 0; ii < 4; ii++) {
        
        strip.setPixelColor(forwardCircleOrigin(a, i+spark_location[ii]), SKY);  
        strip.setPixelColor(reverseCircleOrigin(a, i), BERRY); 
    }
    }
      strip.show();
        delay(100); 
    for (int b = 0; b < circles; b++) {
        strip.setPixelColor(forwardCircleOrigin(b, i), BLACK);
        strip.setPixelColor(reverseCircleOrigin(b, i), BLACK); 
    }
  }

}
