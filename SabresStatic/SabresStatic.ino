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

  lights.fill_color(0, 5, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.fill_color(5, 5, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.fill_color(10, 5, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.fill_color(15, 5, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.fill_color(20, 5, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.fill_color(25, 5, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.fill_color(30, 5, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.fill_color(35, 5, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.fill_color(40, 5, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.fill_color(45, 5, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.fill_color(50, 5, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.fill_color(55, 5, DEFAULT_INTENSITY, COLOR_YELLOW);
  delay(300000);
  
  
}
