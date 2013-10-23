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

  lights.set_color(0, DEFAULT_INTENSITY, COLOR_RED);
  lights.set_color(1, DEFAULT_INTENSITY, COLOR_ORANGE);
  lights.set_color(2, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.set_color(3, DEFAULT_INTENSITY, COLOR_GREEN);
  lights.set_color(4, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.set_color(5, DEFAULT_INTENSITY, COLOR_PURPLE);
  lights.set_color(6, DEFAULT_INTENSITY, COLOR_RED);
  lights.set_color(7, DEFAULT_INTENSITY, COLOR_ORANGE);
  lights.set_color(8, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.set_color(9, DEFAULT_INTENSITY, COLOR_GREEN);
  lights.set_color(10, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.set_color(11, DEFAULT_INTENSITY, COLOR_PURPLE);
  lights.set_color(12, DEFAULT_INTENSITY, COLOR_RED);
  lights.set_color(13, DEFAULT_INTENSITY, COLOR_ORANGE);
  lights.set_color(14, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.set_color(15, DEFAULT_INTENSITY, COLOR_GREEN);
  lights.set_color(16, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.set_color(17, DEFAULT_INTENSITY, COLOR_PURPLE);
  lights.set_color(18, DEFAULT_INTENSITY, COLOR_RED);
  lights.set_color(19, DEFAULT_INTENSITY, COLOR_ORANGE);
  lights.set_color(20, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.set_color(21, DEFAULT_INTENSITY, COLOR_GREEN);
  lights.set_color(22, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.set_color(23, DEFAULT_INTENSITY, COLOR_PURPLE);
  lights.set_color(24, DEFAULT_INTENSITY, COLOR_RED);
  lights.set_color(25, DEFAULT_INTENSITY, COLOR_ORANGE);
  lights.set_color(26, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.set_color(27, DEFAULT_INTENSITY, COLOR_GREEN);
  lights.set_color(28, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.set_color(29, DEFAULT_INTENSITY, COLOR_PURPLE);
  lights.set_color(30, DEFAULT_INTENSITY, COLOR_RED);
  lights.set_color(31, DEFAULT_INTENSITY, COLOR_ORANGE);
  lights.set_color(32, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.set_color(33, DEFAULT_INTENSITY, COLOR_GREEN);
  lights.set_color(34, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.set_color(35, DEFAULT_INTENSITY, COLOR_PURPLE);
  lights.set_color(36, DEFAULT_INTENSITY, COLOR_RED);
  lights.set_color(37, DEFAULT_INTENSITY, COLOR_ORANGE);
  lights.set_color(38, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.set_color(39, DEFAULT_INTENSITY, COLOR_GREEN);
  lights.set_color(40, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.set_color(41, DEFAULT_INTENSITY, COLOR_PURPLE);
  lights.set_color(42, DEFAULT_INTENSITY, COLOR_RED);
  lights.set_color(43, DEFAULT_INTENSITY, COLOR_ORANGE);
  lights.set_color(44, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.set_color(45, DEFAULT_INTENSITY, COLOR_GREEN);
  lights.set_color(46, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.set_color(47, DEFAULT_INTENSITY, COLOR_PURPLE);
  lights.set_color(48, DEFAULT_INTENSITY, COLOR_RED);
  lights.set_color(49, DEFAULT_INTENSITY, COLOR_ORANGE);
  lights.set_color(50, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.set_color(51, DEFAULT_INTENSITY, COLOR_GREEN);
  lights.set_color(52, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.set_color(53, DEFAULT_INTENSITY, COLOR_PURPLE);
  lights.set_color(54, DEFAULT_INTENSITY, COLOR_RED);
  lights.set_color(55, DEFAULT_INTENSITY, COLOR_ORANGE);
  lights.set_color(56, DEFAULT_INTENSITY, COLOR_YELLOW);
  lights.set_color(57, DEFAULT_INTENSITY, COLOR_GREEN);
  lights.set_color(58, DEFAULT_INTENSITY, COLOR_BLUE);
  lights.set_color(59, DEFAULT_INTENSITY, COLOR_PURPLE);
  
  delay(300000);
  
  
}
