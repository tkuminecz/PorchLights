// Main application file
// libraries to include
#include "GEColorEffects.h"
#include "Time.h"

#define outPin 13  //Arduino pin #


static uint16_t c;

GEColorEffects lights(outPin, lightCount);  //Constructor



void setup() {
  randomSeed(analogRead(3));
  lights.enumerate();  //Enumerate lights on string to enable individual bulb addressing
  lights.set_string_colors(COLOR_PURPLE, COLOR_ORANGE, COLOR_GREEN);

}

int program = 0;
int max_progs = 2;
time_t t = now();
time_t curr;
int duration = 75;  

int i;
int n_strobes;
color_t color_array[6]={COLOR_WHITE,COLOR_WHITE,COLOR_WHITE,COLOR_RED,COLOR_PURPLE,COLOR_GREEN};

void loop() {
  lights.strobeToColor(COLOR_GREEN,COLOR_ORANGE,COLOR_PURPLE);
  delay(random(30000,120000));
  

}          
/*    case 1:
        lights.fill_color(0, lightCount, 0, 0);
        delay(1000);
        n_strobes = random(3, 7);
        for (i = 0; i < n_strobes; i++) {
          lights.strobe(color_array[random(0,6)]);
        }
        lights.fill_color(0, lightCount, 0, 0);
        delay(500);
        break;
  }
}*/
