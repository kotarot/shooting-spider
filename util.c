// util.c
// いろいろ関数

#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "util.h"

void init_rand(void)
{
    srand((unsigned)time(NULL));
    //srand(0x12345678);
}

// get random number form ... to ... (from以上to以下の乱数)
int get_rand(int from, int to)
{
    return from + (int)(rand() * (to - from + 1.0) / (1.0 + RAND_MAX));
}

void draw_rectangle(double len_x, double len_y, double len_z, double pos_x, double pos_y, double pos_z)
{
    double hlen_x = len_x * 0.5, hlen_y = len_y * 0.5, hlen_z = len_z * 0.5;

    glPushMatrix();

    glTranslated(pos_x, pos_y, pos_z);

    // face1
    glNormal3d(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3d(hlen_x/* + pos_x*/,  hlen_y/* + pos_y*/,  hlen_z/* + pos_z*/);
        glVertex3d(hlen_x/* + pos_x*/, -hlen_y/* + pos_y*/,  hlen_z/* + pos_z*/);
        glVertex3d(hlen_x/* + pos_x*/, -hlen_y/* + pos_y*/, -hlen_z/* + pos_z*/);
        glVertex3d(hlen_x/* + pos_x*/,  hlen_y/* + pos_y*/, -hlen_z/* + pos_z*/);
    glEnd();
    // face2
    glNormal3d(-1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3d(-hlen_x/* + pos_x*/,  hlen_y/* + pos_y*/,  hlen_z/* + pos_z*/);
        glVertex3d(-hlen_x/* + pos_x*/,  hlen_y/* + pos_y*/, -hlen_z/* + pos_z*/);
        glVertex3d(-hlen_x/* + pos_x*/, -hlen_y/* + pos_y*/, -hlen_z/* + pos_z*/);
        glVertex3d(-hlen_x/* + pos_x*/, -hlen_y/* + pos_y*/,  hlen_z/* + pos_z*/);
    glEnd();
    // face3
    glNormal3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3d( hlen_x/* + pos_x*/, hlen_y/* + pos_y*/,  hlen_z/* + pos_z*/);
        glVertex3d( hlen_x/* + pos_x*/, hlen_y/* + pos_y*/, -hlen_z/* + pos_z*/);
        glVertex3d(-hlen_x/* + pos_x*/, hlen_y/* + pos_y*/, -hlen_z/* + pos_z*/);
        glVertex3d(-hlen_x/* + pos_x*/, hlen_y/* + pos_y*/,  hlen_z/* + pos_z*/);
    glEnd();
    // face4
    glNormal3d(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3d( hlen_x/* + pos_x*/,  hlen_y/* + pos_y*/, hlen_z/* + pos_z*/);
        glVertex3d(-hlen_x/* + pos_x*/,  hlen_y/* + pos_y*/, hlen_z/* + pos_z*/);
        glVertex3d(-hlen_x/* + pos_x*/, -hlen_y/* + pos_y*/, hlen_z/* + pos_z*/);
        glVertex3d( hlen_x/* + pos_x*/, -hlen_y/* + pos_y*/, hlen_z/* + pos_z*/);
    glEnd();
    // face5
    glNormal3d(0.0, -1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3d( hlen_x/* + pos_x*/, -hlen_y/* + pos_y*/,  hlen_z/* + pos_z*/);
        glVertex3d(-hlen_x/* + pos_x*/, -hlen_y/* + pos_y*/,  hlen_z/* + pos_z*/);
        glVertex3d(-hlen_x/* + pos_x*/, -hlen_y/* + pos_y*/, -hlen_z/* + pos_z*/);
        glVertex3d( hlen_x/* + pos_x*/, -hlen_y/* + pos_y*/, -hlen_z/* + pos_z*/);
    glEnd();
    // face6
    glNormal3d(0.0, 0.0, -1.0);
    glBegin(GL_POLYGON);
        glVertex3d( hlen_x/* + pos_x*/,  hlen_y/* + pos_y*/, -hlen_z/* + pos_z*/);
        glVertex3d( hlen_x/* + pos_x*/, -hlen_y/* + pos_y*/, -hlen_z/* + pos_z*/);
        glVertex3d(-hlen_x/* + pos_x*/, -hlen_y/* + pos_y*/, -hlen_z/* + pos_z*/);
        glVertex3d(-hlen_x/* + pos_x*/,  hlen_y/* + pos_y*/, -hlen_z/* + pos_z*/);
    glEnd();

    glPopMatrix();
}
/*
void init_shower()
{
    int i;

    for (i = 0; i < NUM_OF_PARTICLES; i++) {
        particle[i].pos_x = get_rand(0, COLUMN * 10) * 0.1;
        particle[i].pos_y = get_rand(ROW * 10 - 30, ROW * 10 + 30) * 0.1;
        particle[i].pos_z = get_rand(50, 150) * 0.1;
        particle[i].color = get_rand(0, NUM_OF_COLORS);
    }
    glutTimerFunc(50, showertimer_func, 0);
}

void showertimer_func(int value)
{
    int i;

    for (i = 0; i < NUM_OF_PARTICLES; i++) {
        particle[i].pos_z -= 0.1;
        if (particle[i].pos_z < 0) {
            particle[i].pos_z = get_rand(50, 150) * 0.1;
        }
    }
    glutTimerFunc(50, showertimer_func, 0);
}

void draw_shower()
{
    int i;

    for (i = 0; i < NUM_OF_PARTICLES; i++) {
        glDisable(GL_LIGHTING);
        glPushMatrix();

        glColor3d(
            color_val[particle[i].color][0],
            color_val[particle[i].color][1],
            color_val[particle[i].color][2]
        );
        glBegin(GL_POLYGON);
            glVertex3d(particle[i].pos_x + 0.1, particle[i].pos_y, particle[i].pos_z + 0.1);
            glVertex3d(particle[i].pos_x - 0.1, particle[i].pos_y, particle[i].pos_z + 0.1);
            glVertex3d(particle[i].pos_x - 0.1, particle[i].pos_y, particle[i].pos_z - 0.1);
            glVertex3d(particle[i].pos_x + 0.1, particle[i].pos_y, particle[i].pos_z - 0.1);
        glEnd();
        glPopMatrix();
        glEnable(GL_LIGHTING);
    }
    glutPostRedisplay();
}
*/
