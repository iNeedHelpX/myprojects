
#include <FastLED.h>
#define NUM_LEDS 100
#define COLORORDER GRB
#define TYPE WS2811
#define PIN 4

CRGB leds[NUM_LEDS];

float   iHue  =0;
float  iSteps = .01;
int  iDelay = 5;
int  numStops = round(255/NUM_LEDS);

void setup() {
delay (1000);
LEDS.setBrightness (200);
LEDS.addLeds<TYPE, PIN, COLORORDER> (leds, NUM_LEDS);

}

void loop() {


  for (int i; i < NUM_LEDS; i++)
    {
      leds[i] = CHSV (i*numStops + iHue, 255, 199);
      iHue += iSteps;
      if (iHue >= 255)
        {
          iHue = 0;
        }
       
    }
  delay(iDelay);
  LEDS.show();
}




