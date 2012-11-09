// Main application file
// libraries to include
#include "GEColorEffects.h"
#include "Time.h"

#define outPin 13  //Arduino pin #


static uint16_t c;

GEColorEffects lights(outPin, lightCount);  //Constructor


void setup() {
  lights.enumerate();  //Enumerate lights on string to enable individual bulb addressing

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

  if (program == 0 && now() > t + duration) // switch away from chase program after specified time
  {
    program = (program + 1) % max_progs;
    t = now();
  }
  else if (program == 1)
  {
    program = (program + 1) % max_progs;
    t = now();
  }
  
  
  switch (program) {
    case 0:
        lights.chase3colors(0, lightCount, 195, COLOR_ORANGE, COLOR_PURPLE, COLOR_GREEN, 15);
        break;
        
    case 1:
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
}
