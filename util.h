// util.h

#ifndef __MY_UTIL__
#define __MY_UTIL__

#include "color.h"

#define NUM_OF_PARTICLES 100

typedef struct T_PARTICLE {
    double pos_x;
    double pos_y;
    double pos_z;
    e_color color;
    char padding[4];
} s_particle;

s_particle particle[NUM_OF_PARTICLES];

void init_rand(void);
int get_rand(int from, int to);

void draw_rectangle(double len_x, double len_y, double len_z, double pos_x, double pos_y, double pos_z);

void init_shower(void);
void showertimer_func(int value);
void draw_shower(void);

#endif
