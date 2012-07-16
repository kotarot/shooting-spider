// color.c

#include "switch.h"

#ifdef MAC
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif
#include "color.h"

void init_color(void)
{
    int i, j;
    double p_color[NUM_OF_COLORS][3] = {
        {0.3, 0.3, 0.3}, // gray
        {0.6, 0.6, 0.6}, // blue
        {1.0, 0.0, 1.0}, // purple
        {0.0, 0.0, 1.0}, // blue
        {0.0, 1.0, 1.0}, // cyan
        {0.0, 1.0, 0.0}, // green
        {1.0, 1.0, 0.0}, // yellow
        {1.0, 0.5, 0.0}, // orange
        {1.0, 0.0, 0.0}, // red
    };

    for (i = 0; i < NUM_OF_COLORS; i++) {
        for (j = 0; j < 3; j++) {
            color_val[i][j] = p_color[i][j];
        }
    }
}
