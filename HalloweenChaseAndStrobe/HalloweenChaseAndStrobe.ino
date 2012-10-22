#include "GEColorEffects.h"
#include "Time.h"

#define outPin 13  //Arduino pin #


static uint16_t c;

GEColorEffects lights(outPin, lightCount);  //Constructor

void setup() {
  lights.enumerate();  //Enumerate lights on string to enable individual bulb addressing
  Serial.begin(9600);
}

int program = 0;
int max_progs = 2;
time_t t = now();
time_t curr;
int chase_length = 60;

int i;
int n_strobes;

void loop() {
  
  if (program == 0 && now() > t + chase_length) // switch away from chase program after specified time
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
        n_strobes = random(1, 5);
        for (i = 0; i < n_strobes; i++) {
          lights.strobe();
        }
        lights.fill_color(0, lightCount, 0, 0);
        delay(500);
        break;
  }
}
