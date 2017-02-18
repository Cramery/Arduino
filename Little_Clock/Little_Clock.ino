#include "FastLED.h"

// How many leds are in the strip?
#define NUM_LEDS 36

// Data pin that led data will be written out over
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  int MinutesR[5] = {255, 255, 255, 255, 255};
  int MinutesG[5] = {255, 255, 215, 127,0 };
  int MinutesB[5] = {255,0, 0, 36, 0};
  
  int BothR[5] = {255, 191, 127, 0, 0};
  int BothG[5] = {20, 62, 255, 245, 0};
  int BothB[5] = {147, 255, 212, 255, 255};
  
  int Stufe = 0;
  int hour = 1;
  
  for(int z = hour; z <= 12; z++){
    //Laempchen z --> an
  
    delay(60000);
  
    for(int i = 1; i < 60; i++){
      if ( ((i - 1) % 5) == 0){
        if ( ((i + 1) / 5) > z){
          //nächstes Laempchen Weiss: (i / 5) + 1 = Minutes[0][0][0];
        }else{
          //nächstes Laempchen Pink: (i / 5 ) + 1 = Both[0][0][0]
        }
        
      }else{
        Stufe = ((i - 1) % 5);
        if ( (i / 5) > z){
          leds[i / 5].red = MinutesR[Stufe];
          leds[i / 5].green = MinutesG[Stufe];
          leds[i / 5].blue = MinutesB[Stufe];
        }else{
          leds[i / 5].red = BothR[Stufe];
          leds[i / 5].green = BothG[Stufe];
          leds[i / 5].blue = BothB[Stufe];
        }
      }
      delay(60000);
        
    }
    //Alle Minuten abschalten
    //Naechstes in Gruen bzw. Stunden
    for(int c = 1; c <= 12; c++){
      //L�mpchen c aus
    }
    for(int c = 1; c <= z; c++){
      //L�mpchen c gruen
    }
  
  }
  
  for(int c = 1; c <= 12; c++ ){
    //Laempchen c aus.
  }

}
