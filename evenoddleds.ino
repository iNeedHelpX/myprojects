/*this program will play even numbers of leds in an array as
(204, 12, 156) and odd numbers as (110, 231, 58). Loop will repeat 5 times then go to a rainbow */
 
#include <FastLED.h>

#define PIN 9
#define NUM_LEDS 23 //my strip has 23 leds total
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
int fadeAmount = 5;
int brightness = 0;

CRGB leds[NUM_LEDS]; //this is the array of leds

void setup() {
 delay(1000); //1000 millisecond delay
 FastLED.addLeds<WS2812B, PIN, COLOR_ORDER> (leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

}

void loop() { 
  
//evenOdd
//rainbow
}
}

//Even odd leds playing
void evenOdd{
   
for (int i = 0; i < NUM_LEDS*3; i++) //I want this loop to run 3 times
{
  if (i % 2 == 0)
  {
    leds[i].setRGB(12,223,156); //even numbers play this color
    leds[i].fadeLightBy(brightness); //this is what makes the lights fade
  } 
  else
  {
    leds[i].setRGB(110,231,58); //odd numbers play this color
    leds[i].fadeLightBy(brightness); 
  }
   FastLED.show();
   brightness = brightness + fadeAmount;
   
   //reverses  direction  of fade 
  if(brightness == 0 || brightness == 255)
  {
    fadeAmount = -fadeAmount ; 
  } 
  delay(15);
}
}
//fill rainbow loop
void movingRainbow(){
  
float ihue=0;
float istep= 0.01;
int idelay = 0;
int numStops = round (255/NUM_LEDS);


for (int i= 0; i<NUM_LEDS; i++){
  ledsA[i]= CHSV (i*numStops +ihue, 255,255);
  ihue +=istep;
  if (ihue>=255){
    ihue=0;
  }
}
delay(idelay);
FastLED.show();
}
}

