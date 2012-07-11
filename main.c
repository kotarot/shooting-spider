// main.c
//メインファイル

#include <stdio.h>
#include <GL/glut.h>
#include "character.h"
#include "color.h"
#include "global.h"
#include "input.h"
#include "shot.h"
#include "stage.h"
#include "util.h"

#define FPS 10
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600


double aspect;
//e_vmode visual_mode;
//e_gamestate gamestate;
//e_mapfield map[ROW + 2][COLUMN + 2];

// この関数が呼ばれたら描画
void display(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, aspect, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0.0, -10.0, 5.0, 0.0, 20.0, 0.0, 0.0, 0.0, 1.0);

    /*
    switch (visual_mode) {
        case FOLLOW:
            gluLookAt(
                      spider.pos_x10 / 10.0,
                      spider.pos_y10 / 10.0 - 6.0,
                      spider.height + 3.0,
                      spider.pos_x10 / 10.0,
                      spider.pos_y10 / 10.0 + 4.0,
                      spider.height,
                      0.0,
                      0.0,
                      1.0
                      );
            break;
        case FIXED:
            gluLookAt(5.5, -10.0, 5.0, 5.5, 20.0, 0.0, 0.0, 0.0, 1.0);
            break;
    }
    */
    //draw_path(); // draw the path
    disp_character();
    disp_shot();
    disp_stage(); // display the stage
    //draw_character(&spider); // draw the main character
    //draw_allblocks(); // draw blocks
    //if (gamestate == GOAL) {
    //    draw_shower();
    //}

    glutSwapBuffers();
}

void init(void)
{
	int i;
    glClearColor(1.0, 1.0, 1.0, 1.0);  // set background color

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    // いろいろ初期化の関数はここで呼ぶ 
    game_time = 0;
    init_rand();
    init_character();
	for (i=0;i<5;i++) {
    	new_character();
	}
    init_shot();
    init_stage();
    //visual_mode = FOLLOW;
    //gamestate = PLAY;
    //init_color();
    // init_map();
    //set_character(&spider, 5.5, 1.5, GRAY);
    //set_blocks();
}

void resize(int w, int h)
{
    GLfloat pos_light[4] = {50.0, 50.0, 100.0, 1.0};

    glViewport(0, 0, w, h);
    aspect = (double)w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, aspect, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLightfv(GL_LIGHT0, GL_POSITION, pos_light);
}

/* (1/FPS)秒ごとに呼ばれる */
void timer(int value)
{
    printf("game_time = %d\n", game_time);
    //disp_character();
    //disp_Shot();
    //disp_stage();
    update_character();
    display();
    game_time++;
    glutTimerFunc(1000 / FPS, timer, 0);
}

int main(int argc, char *argv[])
{
    int width = WINDOW_WIDTH, height = WINDOW_HEIGHT;
    aspect = (double)width / height;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Shooting Spider");
    init();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutTimerFunc(1000 / FPS, timer, 0);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(s_keyboard);
    glutMainLoop();

    return 0;
}
