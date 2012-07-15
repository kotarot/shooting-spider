// letter.c

#include <stdio.h>
#include <GL/glut.h>
#include "letter.h"
#include "global.h"

int width;
int height;

int score;

void disp_score()
{
    char str[64];
    void *font = GLUT_BITMAP_HELVETICA_18;

    // �Q�l�T�C�g: http://wiki.livedoor.jp/mikk_ni3_92/d/%b4%f0%cb%dc%ca%d417%3a%3abitmap%a5%d5%a5%a9%a5%f3%a5%c8
    glPushMatrix();
    glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();

            glLoadIdentity();
            gluOrtho2D(0, width, 0, height);
            //��������`��
            glPushAttrib(GL_CURRENT_BIT | GL_DEPTH_BUFFER_BIT);
            glDisable(GL_DEPTH_TEST);
            glColor3d(0.0, 0.0, 0.0);
            sprintf(str, "SCORE: %d", score);
            draw_string(str ,font, 4.0, 8.0);
            glPopAttrib();

    glPopMatrix(); 
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void draw_string(const char *str, void *font, double x, double y)
{
    //printf("debug\n");
    //glRasterPos3d(x, y, z);
    glRasterPos2d(x, y); //���������_
    for (;*str != '\0'; str++) {
        glutBitmapCharacter(font, *str);
    }
}

