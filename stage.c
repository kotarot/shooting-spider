// stage.c

#include <GLUT/glut.h>
#include "stage.h"
#include "util.h"

// ここやることないｗ
void init_stage(void)
{
    
}

void disp_stage(void)
{
    int i;
    GLfloat color_stage[4] = {0.6, 0.6, 0.0, 1.0};
    GLfloat color_wall[4] = {0.4, 1.0, 0.4, 1.0};

	//stage
    glPushMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, color_stage);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color_stage);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_stage);
    glMaterialf(GL_FRONT, GL_SHININESS, 80.0);

    for (i = 0; i < 3; i++) {
        draw_rectangle(
            WIDTH_STAGE, DEPTH_STAGE, THICK,
            0.0, DISTANCE_STAGE + DEPTH_STAGE * 0.5, i * HEIGHT_STAGE - THICK * 0.5
        );
    }

    glPopMatrix();
	//wall
    glPushMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, color_wall);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color_wall);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_wall);
    glMaterialf(GL_FRONT, GL_SHININESS, 80.0);

	//left
	draw_rectangle(
		THICK,100,20,
		WIDTH_STAGE / 2,DISTANCE_STAGE,0
		);

	//right
	draw_rectangle(
		THICK,100,20,
		-WIDTH_STAGE / 2,DISTANCE_STAGE,0
		);

    glPopMatrix();

	//floor
    glPushMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, color_wall);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color_wall);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_wall);
    glMaterialf(GL_FRONT, GL_SHININESS, 80.0);

	//floor
	draw_rectangle(
		WIDTH_STAGE,100,10,
		0,DISTANCE_STAGE / 2,-10
		);
	/*
	//roof
	draw_rectangle(
		WIDTH_STAGE,100,10,
		0,DISTANCE_STAGE / 2,HEIGHT_STAGE * 5
		);
	*/
    glPopMatrix();
}
