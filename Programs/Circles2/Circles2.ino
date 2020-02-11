// UNIVERSAL SETUP

#include <Adafruit_NeoPixel.h>
#include <LightConfig.h>
#include <Colors.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LIGHTS, PIN_NUMBER, NEO_GRB + NEO_KHZ800);

// PROGRAM-SPECIFIC VARIABLE DEFINITIONS

#define num_elements(x)  (sizeof(x) / sizeof((x)[0]))
#define START_LED 0
#define END_LED 0

int circles [3] = { 0, 1, 2 };
int start_index [3] = {1, 70, 170};
//int origin_index [3] = {57, 89, 190};
int origin_index [3] = {52, 85, 185};

// TO DO
// 1. switch to using arrays in direction functions
// 2. use global vars for start and origin indicies


// PROGRAM

void setup() {
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

//int forwardCircle(int circle_num , int i){
//  int origin_index;
//  int start_index; 
//  if (circle_num == 1){
//    start_index = 70;
//  } else if (circle_num == 2){
//    start_index = 170;
//  } else if (circle_num == 0){
//    start_index = 1;
//  }
// 
//  if (i + start_index > start_index + 68){
//     return i + start_index - 68;
//    } else {
//      return i + start_index;
//    }
//}
//
//int reverseCircle(int circle_num , int i){
//  int origin_index;
//  int start_index; 
//  if (circle_num == 0){
//    start_index = 1;
//  } else if (circle_num == 1){
//    start_index = 70;
//  }  else if (circle_num == 2){
//    start_index = 170;
//  }
//
//  if (i + start_index > 298){
//     return 0;
//    } else {
//      return start_index + 68 - i;
//    }
//}


int forwardCircleOrigin(int circle_num , int i){
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



int reverseCircleOrigin(int circle_num , int i){
  int origin_index;
  int start_index; 
  if (circle_num == 1){
    origin_index = 85;
    start_index = 70;
  } 
  
  else if (circle_num == 2){
    origin_index = 185;
    start_index = 170;
  } 
  
  else if (circle_num == 0){
    origin_index = 52;
    start_index = 1;
  }

  if (origin_index - i < start_index){
     return origin_index - i + 68;
    } else {
      return origin_index - i;
    }
}




void loop() {
  for (int i = 0; i < 69; i++) {
    for (int a = 0; a < circles; a++) {
        strip.setPixelColor(forwardCircleOrigin(a, i), SKY);  
        strip.setPixelColor(reverseCircleOrigin(a, i), BERRY);  
    }
    strip.show();
    delay(50);
    for (int b = 0; b < circles; b++) {
        strip.setPixelColor(forwardCircleOrigin(b, i), BLACK);
        strip.setPixelColor(reverseCircleOrigin(b, i), BLACK); 
    }
  }

}
