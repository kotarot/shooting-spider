// character.h

#ifndef __MY_CHARACTER__
#define __MY_CHARACTER__

//#include <GL/glut.h>
#include "color.h"
#include "stage.h"
#include "util.h"

GLfloat color_val[NUM_OF_COLORS][3];

#define NUM_OF_CHARS 16

// キャラクター構造体
typedef struct T_CHARACTER {
    double x;       // x座標
    double y;       // y座標
    double z;       // z座標
    double r;       // キャラクターの半径（衝突判定よう）
    double speed;   // 移動速度
    int score;      // 倒したときに獲得するスコアポイント
    int alive;      // 生きてるかどうか
    e_color color;  // 色
    char padding[4];
    //int move;
} s_character;

// キャラクターリスト
s_character character[NUM_OF_CHARS];
int p_character;

void set_character(s_character *character, double pos_x, double pos_y, e_color color);
void change_color(s_character *character);
//void draw_character(s_character *character);
//void timer_callback_func(int value);
//void move_forward(s_character *character);
//void move_backward(s_character *character);
//void move_right(s_character *character);
//void move_left(s_character *character);
//void goal_anime(int value);

void init_character(void);
void new_character(void);
void update_character(void);
void renew_character(s_character *character);
void disp_character(void);
void draw_one_character(s_character *character);

#endif
