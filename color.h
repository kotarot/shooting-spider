// color.h

#ifndef __MY_COLOR__
#define __MY_COLOR__

typedef enum T_COLOR {
    GRAY,
    LIGHTGRAY,
    PURPLE,
    BLUE,
    CYAN,
    GREEN,
    YELLOW,
    ORANGE,
    RED,
    NUM_OF_COLORS
} e_color;

extern GLfloat color_val[NUM_OF_COLORS][3];

void init_color(void);

#endif
