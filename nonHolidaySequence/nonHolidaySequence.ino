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
color_t color_array[6]={COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE};

void loop() {

  lights.fill_color(0, lightCount, DEFAULT_INTENSITY, COLOR_GREEN);
  delay(900000);
  lights.fill_color(0, lightCount, DEFAULT_INTENSITY, COLOR_CYAN);
  delay(900000);
  lights.fill_color(0, lightCount, DEFAULT_INTENSITY, COLOR_BLUE);
  delay(900000);
  
}
