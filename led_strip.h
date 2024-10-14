
#ifndef LED_STRIP_H_
#define LED_STRIP_H_

#include <Adafruit_NeoPixel.h>

// the data pin for the NeoPixels
#define LED_PIN     D1

// How many NeoPixels we will be using, charge accordingly
#define LED_COUNT   60

// Instatiate the NeoPixel from the ibrary
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Global RGB values, change to suit your needs
bool changed = true;
uint32_t color = strip.Color(255, 255, 255);
int brightness = 50;

void led_setup() {
  strip.begin();  // initialize the strip
  strip.show();   // make sure it is visible
  strip.clear();  // Initialize all pixels to 'off'
}

void led_set(int r, int g, int b) {
  color = strip.Color(r, g, b);
  changed = true;
}

void led_on() {
  changed = true;
}

void led_off() {
  strip.clear();
  strip.show();
}

void led_loop() {
  if (!changed) return;
  changed = false;

  // set the colors for the strip
  strip.fill(color, 0, strip.numPixels());
  strip.setBrightness(brightness);  

  // show all pixels  
  strip.show();
}

#endif /* LED_STRIP_H_ */
