/******************************************************
Hue Pedal
by Tim Bartlet & Enthusiastic Electrons, October 2019

Color mixing toy with a potentiometer shifting hue
on a single NeoPixel. Uses ATTiny85.
******************************************************/

#include <FastLED.h>
#define DATA_PIN 0
#define NUM_LEDS 1

CRGB leds[NUM_LEDS];
uint8_t knob = A1;
uint8_t lightAddress = 0;
uint8_t lightHue = 0;

void setup() {
  for (int p = 0; p < 5; p++){
    pinMode(p, INPUT);
  }
  pinMode(knob, INPUT);
  pinMode(DATA_PIN, OUTPUT);

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(35); // 0-255 - adjust so it's not blinding
  leds[lightAddress].setHSV(0, 255, 255);
  FastLED.show();
}

void loop() {
  uint16_t knobNow = analogRead(knob);
  uint16_t scaledKnob = map(knobNow, 0, 1023, 0, 255);
  if (scaledKnob != lightHue){
    lightHue = scaledKnob;
    leds[lightAddress].setHue(lightHue);
    FastLED.show();
  }
  FastLED.delay(10); 
}
