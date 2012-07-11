// stage.c

#include <GL/glut.h>
#include "stage.h"

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
    int i, j, k;

    glDisable(GL_LIGHTING);
    glPushMatrix();

    /*// draw one grid
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
    for (k = 0; k < 3; k++) {
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

    glPopMatrix();
    glEnable(GL_LIGHTING);
}
