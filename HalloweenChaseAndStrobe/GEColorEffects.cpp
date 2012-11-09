/*
   GEColorEffects.cpp - Library for driving GE Color Effects
   LED Holiday Lights with an Arduino

   Created by Paul Martis, October 1, 2011.
   http://www.digitalmisery.com

   Based on Christmas Light Control by Robert Quattlebaum <darco@deepdarc.com>
   (http://www.deepdarc.com/2010/11/27/hacking-christmas-lights)
   and Arduino adaptation by Scott Harris <scottrharris@gmail.com>
   http://scottrharris.blogspot.com/2010/12/controlling-ge-color-effects-lights.html
*/

#include "Arduino.h"
#include "GEColorEffects.h"

GEColorEffects::GEColorEffects(int pin, int light_count)
{
   pinMode(pin, OUTPUT);
   _pin = pin;
   _light_count = light_count;
}

//The timings below have been hand-tuned. Adjust if necessary.
void GEColorEffects::begin()
{
   digitalWrite(_pin, HIGH);  
   delayMicroseconds(6);  //Output should be ~ 10uS long 
   digitalWrite(_pin, LOW); 
}

void GEColorEffects::one()
{
   digitalWrite(_pin, LOW);  
   delayMicroseconds(12); //Output should be ~ 20uS long 
   digitalWrite(_pin, HIGH);  
   delayMicroseconds(6);  //Output should be ~ 10uS long 
   digitalWrite(_pin, LOW);
}

void GEColorEffects::zero()
{
   digitalWrite(_pin, LOW);  
   delayMicroseconds(2);  //Output should be ~ 10uS long
   digitalWrite(_pin, HIGH);  
   delayMicroseconds(17); //Output should be ~ 20uS long  
   digitalWrite(_pin, LOW);
}

void GEColorEffects::end()
{
   digitalWrite(_pin, LOW);  
   delayMicroseconds(30); //Quiet time should be ~ 30us long
}

//Turn on a specific LED with a color and brightness
void GEColorEffects::set_color(uint8_t led, uint8_t intensity, color_t color)
{  
   led = led % lightCount;
   uint8_t i;  
   begin();  
   for(i=6;i;i--,(led<<=1))  
      if(led&(1<<5))  
         one();  
      else  
         zero();
  
   for(i=8;i;i--,(intensity<<=1))  
      if(intensity&(1<<7))  
         one();  
      else  
         zero();
  
   for(i=12;i;i--,(color<<=1))  
      if(color&(1<<11))  
         one();  
      else  
         zero();  
   end();  
}

//Returns 12-bit color from red, green, and blue components
color_t GEColorEffects::color(uint8_t r, uint8_t g, uint8_t b)
{  
   return COLOR(r,g,b);  
}

//Returns primary hue colors
color_t GEColorEffects::color_hue(uint8_t h)
{  
   switch(h>>4)
   {  
      case 0:     h-=0; return color(h,CHANNEL_MAX,0);  
      case 1:     h-=16; return color(CHANNEL_MAX,(CHANNEL_MAX-h),0);  
      case 2:     h-=32; return color(CHANNEL_MAX,0,h);  
      case 3:     h-=48; return color((CHANNEL_MAX-h),0,CHANNEL_MAX);  
      case 4:     h-=64; return color(0,h,CHANNEL_MAX);  
      case 5:     h-=80; return color(0,CHANNEL_MAX,(CHANNEL_MAX-h));  
   }   
}

//Make all LEDs the same color starting at specified beginning LED
void GEColorEffects::fill_color(uint8_t begin, uint8_t count, uint8_t intensity, color_t color)
{
   while(count--)  
   {  
      set_color(begin++, intensity, color);  
   }
}

//Make all LEDs the same color
void GEColorEffects::fill_color_same(uint8_t begin, uint8_t count, uint8_t intensity, color_t color)
{
   while(count--)
   {  
      set_color(count, intensity, color);
   }
}

// sets 
void GEColorEffects::set_n_color(int n, uint8_t begin, uint8_t intensity, color_t color)
{
  int i;
  for (i = 0; i < n; i++) {
    set_color((uint8_t)begin + i, intensity, color);
  }
}

void GEColorEffects::set_n_color_blended(int n, uint8_t begin, uint8_t intensity, color_t color_l, color_t color, color_t color_r)
{
  set_color(begin, intensity, color_l);
  set_color(begin + 1, intensity, blend(color_l, color, 0.5));
  set_color(begin + 2, intensity, color);
  set_color(begin + 3, intensity, blend(color, color_r, 0.5));
  set_color(begin + 4, intensity, color_r);
}

// strobe effect
void GEColorEffects::strobe(color_t color)
{
  int min_group_size = 4;
  int max_group_size = 40;
  int min_num_strobes = 10;
  int max_num_strobes = 30;
  int min_delay = 10;
  int max_delay = 40;
  
  int start_pos = random(0, lightCount);
  int group_size = random(min_group_size, max_group_size);
  int strobe_count = random(min_num_strobes, max_num_strobes);
  int tdelay = random(min_delay, max_delay);
  
  for (int i = 0; i < strobe_count; i++)
  {
    // strobe on
    fill_color(start_pos, group_size, DEFAULT_INTENSITY, color);
    delay(tdelay);
  
    // strobe off
    fill_color(start_pos, group_size, 0, 0);
    delay(tdelay);
  }
}

// blends two colors
color_t GEColorEffects::blend(color_t ca, color_t cb, float weight = 0.5)
{
  int ra, ga, ba, rb, gb, bb, r, g, b;
  ra = ca | 0xf00;
  ga = (ca | 0x0f0) << 4;
  ba = (ca | 0xf) << 8;
  rb = cb | 0xf00;
  gb = (cb | 0x0f0) << 4;
  bb = (cb | 0xf) << 8;
  
  r = (weight * rb) + ((1-weight) * ra);
  g = (weight * gb) + ((1-weight) * ga);
  b = (weight * bb) + ((1-weight) * ba);
  
  return COLOR(r, g, b);
}

// does the chase animation with 3 colors
void GEColorEffects::chase3colors(uint8_t begin, uint8_t count, uint8_t intensity, color_t color1, color_t color2, color_t color3, int duration)
{
  color_t colors[3] = {color1, color2, color3};
  color_t temp;
  int i = begin;
  int c, prev_c, next_c;
  int j = 0;
  int start_pos = 0;
  int n_sets = 0;
  int group_size = 5;
  int max_sets = lightCount / group_size;
  
  while (j++ < duration)
  {
    i = start_pos++;
    c = 0;
    prev_c = 2;
    next_c = 1;
    
    n_sets = 0;
    while (n_sets++ < max_sets)
    {
      set_n_color(group_size, i, intensity, colors[c]);
      i += group_size;
      
      // move to next color
      c = (c + 1) % 3;
      prev_c = (prev_c + 1) % 3;
      next_c = (next_c + 1) % 3;
    }
    
    delay(10);
  }
}

//Initialize string for individual bulb addressing
void GEColorEffects::enumerate()
{
   uint8_t i;

   while(i < _light_count)
   {
      fill_color(0, _light_count, DEFAULT_INTENSITY, COLOR_BLACK);  
      i++;
   }
}
