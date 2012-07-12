// stage.c

#include <GLUT/glut.h>
#include "stage.h"
#include "util.h"

void init_stage(void)
{
    //int i, j;

    //for (i = 0; i <= ROW + 1; i++) {
        //for (j = 0; j <= COLUMN + 1; j++) {
            //if (i == 0 || i == ROW + 1 || j == 0 || j == COLUMN + 1) {
                //map[i][j] = CLIFF;
            //} else {
                //map[i][j] = VACANT;
            //}
        //}
    //}
}

void disp_stage(void)
{
    int i;
    GLfloat color_stage[4] = {0.1, 0.1, 0.0, 1.0};
    GLfloat color_wall[4] = {0.2, 0.2, 0.2, 1.0};

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
		WIDTH_STAGE,100,THICK,
		0,DISTANCE_STAGE / 2,-THICK
		);
	/*
	//roof
	draw_rectangle(
		WIDTH_STAGE,100,10,
		0,DISTANCE_STAGE / 2,HEIGHT_STAGE * 5
		);
	*/
    glPopMatrix();


    /*int i, j, k;

    glDisable(GL_LIGHTING);
    glPushMatrix();

    // draw one grid
    for (i = 1; i <= ROW; i++) { // row
        for (j = 1; j <= COLUMN; j++) { // column
            if ((i + j) % 2 == 1) { // when (i + j) is odd
                glColor3d(0, 0.71, 0.43); // black
//               glColor3d(0.6, 0.6, 0.6); // black
            } else { // when (i + j) is even
                glColor3d(0.9, 0.6, 0.6); // red
            }
            glBegin(GL_POLYGON);
                glVertex3d(j + 0.0, i + 0.0, 0.0);
                glVertex3d(j + 0.0, i + 1.0, 0.0);
                glVertex3d(j + 1.0, i + 1.0, 0.0);
                glVertex3d(j + 1.0, i + 0.0, 0.0);
            glEnd();
        }
    }*/

    // stage作成
    /*for (k = 0; k < 3; k++) {
		glColor3d(0.5, 0.5, 0.5); // red

         glBegin(GL_POLYGON);
         //上面
         glVertex3d(-WINDTH_STAGE / 2, DISTANCE_STAGE, k * HIGHT_STAGE);
         glVertex3d(-WINDTH_STAGE / 2, DISTANCE_STAGE + DEPTH_STAGE, k * HIGHT_STAGE);
         glVertex3d(WINDTH_STAGE / 2, DISTANCE_STAGE + DEPTH_STAGE, k * HIGHT_STAGE);
         glVertex3d(WINDTH_STAGE / 2, DISTANCE_STAGE, k * HIGHT_STAGE);
         //下面
         glVertex3d(-WINDTH_STAGE / 2, DISTANCE_STAGE, k * HIGHT_STAGE - THICK);
         glVertex3d(-WINDTH_STAGE / 2, DISTANCE_STAGE + DEPTH_STAGE, k * HIGHT_STAGE - THICK);
         glVertex3d(WINDTH_STAGE / 2, DISTANCE_STAGE + DEPTH_STAGE, k * HIGHT_STAGE - THICK);
         glVertex3d(WINDTH_STAGE / 2, DISTANCE_STAGE, k * HIGHT_STAGE - THICK);
         //正面
         glVertex3d(-WINDTH_STAGE / 2, DISTANCE_STAGE, k * HIGHT_STAGE );
         glVertex3d(-WINDTH_STAGE / 2, DISTANCE_STAGE, k * HIGHT_STAGE - THICK);
         glVertex3d(WINDTH_STAGE / 2, DISTANCE_STAGE, k * HIGHT_STAGE - THICK);
         glVertex3d(WINDTH_STAGE / 2, DISTANCE_STAGE, k * HIGHT_STAGE);
         //後面
         glVertex3d(-WINDTH_STAGE / 2, DISTANCE_STAGE + DEPTH_STAGE, k * HIGHT_STAGE );
         glVertex3d(-WINDTH_STAGE / 2, DISTANCE_STAGE + DEPTH_STAGE, k * HIGHT_STAGE - THICK);
         glVertex3d(WINDTH_STAGE / 2, DISTANCE_STAGE + DEPTH_STAGE, k * HIGHT_STAGE - THICK);
         glVertex3d(WINDTH_STAGE / 2, DISTANCE_STAGE + DEPTH_STAGE, k * HIGHT_STAGE);
         //左面
         glVertex3d(-WINDTH_STAGE / 2, DISTANCE_STAGE, k * HIGHT_STAGE );
         glVertex3d(-WINDTH_STAGE / 2, DISTANCE_STAGE + DEPTH_STAGE, k * HIGHT_STAGE);
         glVertex3d(-WINDTH_STAGE / 2, DISTANCE_STAGE + DEPTH_STAGE, k * HIGHT_STAGE - THICK);
         glVertex3d(-WINDTH_STAGE / 2, DISTANCE_STAGE, k * HIGHT_STAGE - THICK);
         //右面
         glVertex3d(WINDTH_STAGE / 2, DISTANCE_STAGE, k * HIGHT_STAGE );
         glVertex3d(WINDTH_STAGE / 2, DISTANCE_STAGE + DEPTH_STAGE, k * HIGHT_STAGE);
         glVertex3d(WINDTH_STAGE / 2, DISTANCE_STAGE + DEPTH_STAGE, k * HIGHT_STAGE - THICK);
         glVertex3d(WINDTH_STAGE / 2, DISTANCE_STAGE, k * HIGHT_STAGE - THICK);

         glEnd();
        }

		/*
        for (i = ROW; i <= ROW_STAGE; i++) { // row
            for (j = 1; j <= COLUMN; j++) { // column
                glColor3d(0.5, 0.5, 0.5); // red

                glBegin(GL_POLYGON);
                //上面
                glVertex3d(j + 0.0, i + 0.0, k * HIGHT_STAGE);
                glVertex3d(j + 0.0, i + 1.0, k * HIGHT_STAGE);
                glVertex3d(j + 1.0, i + 1.0, k * HIGHT_STAGE);
                glVertex3d(j + 1.0, i + 0.0, k * HIGHT_STAGE);
                //下面
                glVertex3d(j + 0.0, i + 0.0, k * HIGHT_STAGE - THICK);
                glVertex3d(j + 0.0, i + 1.0, k * HIGHT_STAGE - THICK);
                glVertex3d(j + 1.0, i + 1.0, k * HIGHT_STAGE - THICK);
                glVertex3d(j + 1.0, i + 0.0, k * HIGHT_STAGE - THICK);
                //正面
                glVertex3d(j + 0.0, i + 0.0, k * HIGHT_STAGE );
                glVertex3d(j + 0.0, i + 0.0, k * HIGHT_STAGE - THICK);
                glVertex3d(j + 1.0, i + 0.0, k * HIGHT_STAGE - THICK);
                glVertex3d(j + 1.0, i + 0.0, k * HIGHT_STAGE);
                //後面
                glVertex3d(j + 0.0, i + 1.0, k * HIGHT_STAGE );
                glVertex3d(j + 0.0, i + 1.0, k * HIGHT_STAGE - THICK);
                glVertex3d(j + 1.0, i + 1.0, k * HIGHT_STAGE - THICK);
                glVertex3d(j + 1.0, i + 1.0, k * HIGHT_STAGE);
                //左面
                glVertex3d(j + 0.0, i + 0.0, k * HIGHT_STAGE );
                glVertex3d(j + 0.0, i + 1.0, k * HIGHT_STAGE);
                glVertex3d(j + 0.0, i + 1.0, k * HIGHT_STAGE - THICK);
                glVertex3d(j + 0.0, i + 0.0, k * HIGHT_STAGE - THICK);
                //右面
                glVertex3d(j + 1.0, i + 0.0, k * HIGHT_STAGE );
                glVertex3d(j + 1.0, i + 1.0, k * HIGHT_STAGE);
                glVertex3d(j + 1.0, i + 1.0, k * HIGHT_STAGE - THICK);
                glVertex3d(j + 1.0, i + 0.0, k * HIGHT_STAGE - THICK);

                glEnd();
            }
        }
    }
		*/

    /*glPopMatrix();
    glEnable(GL_LIGHTING);*/
}
