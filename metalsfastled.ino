//Julia pak 2018
#include <FastLED.h>

#define LED_PIN      4 //pin I'm attaching to
// Information about the LED strip itself
#define NUM_LEDS    144
#define CHIPSET     WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS]; //array declaration
#define BRIGHTNESS  220
#define TEMPERATURE_1 MetalHalide
#define TEMPERATURE_2 MercuryVapor

// How many seconds to show each temperature before switching
#define DISPLAYTIME 3 
#define BLACKTIME   0.0 //no black time


void setup() {
  //nil
  delay(800);
FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalSMD5050 );
  FastLED.setBrightness( BRIGHTNESS );
}

void loop() {
   // draw a generic, no-name rainbow
  static uint8_t starthue = 0;
  fill_rainbow( leds + 0, NUM_LEDS - 0, --starthue, 0);
  // Choose which 'color temperature' profile to enable.
  uint8_t secs = (millis() / 1000) % (DISPLAYTIME * 2);
  if( secs < DISPLAYTIME) {
    FastLED.setTemperature( TEMPERATURE_1 ); // first temperature
    leds[0] = TEMPERATURE_1; // show indicator pixel
  } else {
    FastLED.setTemperature( TEMPERATURE_2 ); // second temperature
    leds[0] = TEMPERATURE_2; // show indicator pixel
  }
  if( (secs % DISPLAYTIME) < BLACKTIME) {
    memset8( leds, 0, NUM_LEDS * sizeof(CRGB));
  }
  
  FastLED.show();
  FastLED.delay(40);
  
}
