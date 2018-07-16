#include <Adafruit_NeoPixel.h>

#define PIN 6

#define NUM_LEDS 8

#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int startingValue;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();//initial all pixels to 'off'

 Serial.begin(9600);
 startingValue=100;


}

void loop() {
  // put your main code here, to run repeatedly:
  for (int n = 0; n <= 7; n++) {
    setLEDs(100*n+100);
     delay(500);
     Serial.println(100*n+100);
  }
 
}

void setLEDs(int noiseLevel) {
  int nL = noiseLevel;//noise level from microphone

  ///////////////////////////////////////////////////////////////
  // <100
  if (nL <= startingValue) {//1st led green, others off
    strip.setPixelColor(0, 0, 255, 0);
    for (int n = 1; n <= 7; n++) {
      strip.setPixelColor(n, 0, 0, 0);
    }
    strip.show();
  }

  ///////////////////////////////////////////////////////////////
  // 100<200
  else if (nL > startingValue && nL <= startingValue+100) {
    strip.setPixelColor(0, 0, 255, 0);
    strip.setPixelColor(1, 0, 255, 0);
    for (int n = 2; n <= 7; n++) {
      strip.setPixelColor(n, 0, 0, 0);
    }
    strip.show();
  }

  ///////////////////////////////////////////////////////////////
  // 200<300
  else if (nL > startingValue+100 && nL <= startingValue+200) {
    for (int n = 0; n <= 2; n++) {
      strip.setPixelColor(n, 0, 255, 0);
    }
    for (int n = 3; n <= 7; n++) {
      strip.setPixelColor(n, 0, 0, 0);
    }
    strip.show();
  }

  ///////////////////////////////////////////////////////////////
  // 300<400

  else if (nL > startingValue+200 && nL <= startingValue+300) {
    for (int n = 0; n <= 3; n++) {
      strip.setPixelColor(n, 255, 200, 0);
    }
    for (int n = 4; n <= 7; n++) {
      strip.setPixelColor(n, 0, 0, 0);
    }
    strip.show();
  }
  ///////////////////////////////////////////////////////////////
  // 400<500
  else if (nL > startingValue+300 && nL <= startingValue+400) {
    for (int n = 0; n <= 4; n++) {
      strip.setPixelColor(n, 255, 200, 0);
    }
    for (int n = 5; n <= 7; n++) {
      strip.setPixelColor(n, 0, 0, 0);
    }
    strip.show();
  }

  ///////////////////////////////////////////////////////////////
  // 500<600

  else if (nL > startingValue+400 && nL <= startingValue+500) {
    for (int n = 0; n <= 5; n++) {
      strip.setPixelColor(n, 255, 200, 0);
    }
    for (int n = 6; n <= 7; n++) {
      strip.setPixelColor(n, 0, 0, 0);
    }
    strip.show();
  } ///////////////////////////////////////////////////////////////
  // 600<700
  
  else if (nL > startingValue+500 && nL <= startingValue+600) {
    for (int n = 0; n <= 6; n++) {
      strip.setPixelColor(n, 255, 0, 0);
    }

    strip.setPixelColor(7, 0, 0, 0);

    strip.show();
  }

  ///////////////////////////////////////////////////////////////
  // >700

  else if (nL > startingValue+600) {
    for (int n = 0; n <= 7; n++) {
      strip.setPixelColor(n, 255, 0, 0);
    }

    strip.show();
  }



}
