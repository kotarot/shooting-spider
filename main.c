// main.c
//メインファイル

#include <stdio.h>
#include <GLUT/glut.h>
#include "character.h"
#include "color.h"
#include "global.h"
#include "input.h"
#include "shot.h"
#include "stage.h"
#include "util.h"
#include "letter.h"

#define FPS 15
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

double aspect;
int width;
int height;

unsigned int game_time;
int score;
int used_shots;

e_mode game_mode;

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

    gluLookAt(eye_x, eye_y, 6.0 + eye_z , 0.0, 40.0, 2.5, 0.0, 0.0, 1.0);

    disp_cursor();
    disp_character();
    disp_shot();
    disp_stage();
    
    if (game_mode == PLAYING) {
        disp_info();
    } else {
        draw_shower();
        disp_result();
    }

    glutSwapBuffers();
}

void timer(void);

void init(void)
{
	//eye_x=0.0;//作業用に視点を動かせるように
	//eye_y=0.0;//作業用に視点を動かせるように
	//eye_z=0.0;//作業用に視点を動かせるように
    glClearColor(1.0, 1.0, 1.0, 1.0);  // set background color

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    // いろいろ初期化の関数はここで呼ぶ 
    game_time = 0;
    score = 0;
    game_mode = PLAYING;
    init_rand();
    init_color();

    //init_stage();  // <- これ呼んでもやる処理ないんだよねｗ
    init_shot();
    init_cursor();
    init_character();

    glutTimerFunc(1000 / FPS, timer, 0);
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

// ゲーム終了時に呼ばれる
void finish(void) {
    //printf("ゲーム終了\n");
    game_mode = FINISHED;
    init_shower();
    draw_shower();
}

/* (1/FPS)秒ごとに呼ばれる */
void timer(int value)
{
    int r;

    //printf("game_time = %d\n", game_time);

    // 弾使い切ってたらゲーム終了
    if (NUM_OF_SHOTS <= used_shots) {
        finish();
        return;
    }

    // 一定の確率で新しい敵キャラ生成
    // とりあえず5% 多いかなｗ <- 多かったわ 3%にした
    r = get_rand(0, 100);
    if (r < 3) {
        //printf("generated!\n");
        new_character();
    }

    update_shot();
    update_character();
    display();
    game_time++;
    glutTimerFunc(1000 / FPS, timer, 0);
}

int main(int argc, char *argv[])
{
    width = WINDOW_WIDTH;
    height = WINDOW_HEIGHT;
    aspect = (double)width / height;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Shooting Spider");
    init();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(s_keyboard);
    glutMainLoop();

    return 0;
}
