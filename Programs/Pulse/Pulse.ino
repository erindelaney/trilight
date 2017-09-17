// UNIVERSAL SETUP

#include <Adafruit_NeoPixel.h>
#include <LightConfig.h>
#include <Colors.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LIGHTS, PIN_NUMBER, NEO_GRB + NEO_KHZ800);


// PROGRAM-SPECIFIC VARIABLE DEFINITIONS

#define DELAY_MS  100
#define num_elements(x)  (sizeof(x) / sizeof((x)[0]))

char lip_location[NUM_LIGHTS] = {};

int outer_left[] = {48, 69};
int outer_right[] = {70, 91};
int inner_right[] = {140, 159};
int inner_left[] = {280, 299};
int lips_start_index[] = {48, 70, 140, 280};
int lips_end_index[] = {69, 91, 159, 299};




// PROGRAM

void setup() {
    for (int lip = 0; lip < 4; lip += 1) {
      int lip_start = lips_start_index[lip];
      int lip_end = lips_end_index[lip];
      
      for (int j = lip_start; j < lip_end; j++) {
        lip_location[j] = 19;
      }
  }
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.clear();
  strip.show(); // Initialize all pixels to 'off'
}


void loop() {
  int k = 0;
  for (int a = 0; a < 3; a++) {
    
  
  if (k < 3) {
  for (int light = 0; light < NUM_LIGHTS; light++) {
    if (lip_location[light] > 0) {
    uint32_t light_color = BERRY;
    uint32_t fade_color;
      if (lip_location[light] > 10) {
      fade_color = LinearColorFade(BLACK, light_color, pow(((20 - lip_location[light])) / 12.0, 1));
      }
      else {
      fade_color = LinearColorFade(BLACK, light_color, pow(lip_location[light] / 10.0, 0.95));
      }
    strip.setPixelColor(light, fade_color);
      if (lip_location[light] == 1) {
      lip_location[light] = 19;
      }
      else {
      lip_location[light] -= 1;
      }
    }
    else {
    strip.setPixelColor(light, BLACK);
    }
  }
strip.show();
delay(DELAY_MS);
}

else {
  for (int m = 0; m < NUM_LIGHTS; m++) {
    strip.setPixelColor(m, WHITE);
  }
  strip.show();
  k = 0;
}

}
}




//  for (int f = 0; f < 300; f++) {
//    if (f >= lips_start && f<= lips_end) {
//    strip.setPixelColor(f, RED);
//    strip.show();


//  strip.clear();

//    delay(DELAY_MS);
//    strip.clear();

// Return colors that is a blend of a and b.
// a * (1 - percent) + b * (percent);
//
uint32_t LinearColorFade(uint32_t color_a, uint32_t color_b, float percent) {
  uint32_t r_a = (uint8_t)(color_a >> 16);
  uint32_t r_b = (uint8_t)(color_b >> 16);
  int16_t r_diff = r_b - r_a;

  uint32_t g_a = (uint8_t)(color_a >> 8);
  uint32_t g_b = (uint8_t)(color_b >> 8);
  int16_t g_diff = g_b - g_a;

  uint32_t b_a = (uint8_t)(color_a);
  uint32_t b_b = (uint8_t)(color_b);
  int16_t b_diff = b_b - b_a;

  int16_t new_r = round(r_a + r_diff * percent);
  int16_t new_g = round(g_a + g_diff * percent);
  int16_t new_b = round(b_a + b_diff * percent);

  return Adafruit_NeoPixel::Color(new_r, new_g, new_b);
}
