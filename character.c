// character.c

#include <GLUT/glut.h>
//#include "global.h"
#include "character.h"

//unsigned int goaltimer;
//e_gamestate gamestate;

/*void set_character(s_character *character, double pos_x, double pos_y, e_color color)
{
    character->x = pos_x * 10;
    character->y = pos_y * 10;
    character->z = 0.3;
    character->color = color;
    character->alive = 1;
}*/

void change_color(s_character *character)
{
    character->color = (character->color + 1) % NUM_OF_COLORS;
}

/*void draw_character(s_character *character)
{
    GLfloat color_body[4];
    GLfloat color_eye[4] = {0.6, 0.0, 0.0, 1.0};

    double pos_base[3] = {-0.27, 0.0, 0.27};
    double pos_x, pos_y, pos_z;
    e_color color;
    int i;

    pos_x = character->x / 10.0;
    pos_y = character->y / 10.0;
    pos_z = character->z;
    color = character->color;

    // set color
    color_body[0] = color_val[color][0];
    color_body[1] = color_val[color][1];
    color_body[2] = color_val[color][2];
    color_body[3] = 1.0;

    // start drawing an object
    glPushMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, color_body);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color_body);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_body);
    glMaterialf(GL_FRONT, GL_SHININESS, 80.0);

    // body
    draw_rectangle(0.5, 0.8, 0.3, pos_x + 0.0, pos_y - 0.1, pos_z);
    // head
    draw_rectangle(0.3, 0.3, 0.3, pos_x + 0.0, pos_y + 0.3, 0.2 + pos_z);

    for (i = 0; i < 3; i++) {
        // right
            // baseleg
            draw_rectangle(0.4, 0.07, 0.07, pos_x - 0.2, pos_y + pos_base[i] - 0.1, pos_z);
            // endleg
            draw_rectangle(0.07, 0.07, 0.3, pos_x - 0.4, pos_y + pos_base[i] - 0.1, -0.15 + pos_z);
        // left
            // baseleg
            draw_rectangle(0.4, 0.07, 0.07, pos_x + 0.2, pos_y + pos_base[i] - 0.1, pos_z);
            // endleg
            draw_rectangle(0.07, 0.07, 0.3, pos_x + 0.4, pos_y + pos_base[i] - 0.1, -0.15 + pos_z);
    }

    glMaterialfv(GL_FRONT, GL_AMBIENT, color_eye);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color_eye);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_eye);
    glMaterialf(GL_FRONT, GL_SHININESS, 80.0);

    // eyes
    draw_rectangle(0.05, 0.05, 0.05, pos_x + 0.07, pos_y + 0.45, 0.25 + pos_z);
    draw_rectangle(0.05, 0.05, 0.05, pos_x - 0.07, pos_y + 0.45, 0.25 + pos_z);

    // finish drawing an object
    glPopMatrix();
}*/

/*void timer_callback_func(int value) {
    //printf("#timer_callback_func value=0x%08x\n", value);
    ((s_character *)value)->color = GRAY;
    ((s_character *)value)->alive = 1;
    //glutPostRedisplay();
}*/

/*void move_forward(s_character *character)
{
    int left_x, center_x, right_x, y;

    if (character->alive == 0) {
        return;
    }
    left_x = (character->x - 5) / 10;
    center_x = character->x / 10;
    right_x = (character->x + 4) / 10;
    y = (character->y + 5) / 10;
    if (map[y][left_x] == VACANT && map[y][center_x] == VACANT && map[y][right_x] == VACANT) {
        character->y++;
    } else if (map[y][left_x] == BLOCK || map[y][center_x] == BLOCK || map[y][right_x] == BLOCK) {
        //printf("Collide with block! character=0x%08x\n", character);
        character->alive = 0;
        character->color = RED;
        glutTimerFunc(3000, timer_callback_func, (int)character);
    } else {
        //printf("GOAL!!\n");
        //gamestate = GOAL;
        character->alive = 0;
        goal_anime((int)&spider);
        init_shower();
    }
}*/

/*void move_backward(s_character *character)
{
    int left_x, center_x, right_x, y;

    if (character->alive == 0) {
        return;
    }
    left_x = (character->x - 5) / 10;
    center_x = character->x / 10;
    right_x = (character->x + 4) / 10;
    y = (character->y - 6) / 10;
    if (map[y][left_x] == VACANT && map[y][center_x] == VACANT && map[y][right_x] == VACANT) {
        character->y--;
    } else if (map[y][left_x] == BLOCK || map[y][center_x] == BLOCK || map[y][right_x] == BLOCK) {
        //printf("Collide with block! character=0x%08x\n", character);
        character->alive = 0;
        character->color = RED;
        glutTimerFunc(3000, timer_callback_func, (int)character);
    }
}*/

/*void move_right(s_character *character)
{
    int x, up_y, center_y, down_y;

    if (character->alive == 0) {
        return;
    }
    x = (character->x + 5) / 10;
    up_y = (character->y + 4) / 10;
    center_y = character->y / 10;
    down_y = (character->y - 5) / 10;
    if (map[up_y][x] == VACANT && map[center_y][x] == VACANT && map[down_y][x] == VACANT) {
        character->x++;
    } else if (map[up_y][x] == BLOCK || map[center_y][x] == BLOCK || map[down_y][x] == BLOCK) {
        //printf("Collide with block! character=0x%08x\n", character);
        character->alive = 0;
        character->color = RED;
        glutTimerFunc(3000, timer_callback_func, (int)character);
    }
}*/

/*void move_left(s_character *character)
{
    int x, up_y, center_y, down_y;

    if (character->alive == 0) {
        return;
    }
    x = (character->x - 6) / 10;
    up_y = (character->y + 4) / 10;
    center_y = character->y / 10;
    down_y = (character->y - 5) / 10;
    if (map[up_y][x] == VACANT && map[center_y][x] == VACANT && map[down_y][x] == VACANT) {
        character->x--;
    } else if (map[up_y][x] == BLOCK || map[center_y][x] == BLOCK || map[down_y][x] == BLOCK) {
        //printf("Collide with block! character=0x%08x\n", character);
        character->alive = 0;
        character->color = RED;
        glutTimerFunc(3000, timer_callback_func, (int)character);
    }
}*/

/*void goal_anime(int value)
{
    //goaltimer++;
    //if (100 <= goaltimer) {
    //    goaltimer = 0;
    //}
    //((s_character *)value)->z = -0.0008 * goaltimer * goaltimer + 0.08 * goaltimer;
    //if (gamestate == GOAL) {
    //    ((s_character *)value)->color = (((s_character *)value)->color + 1) % NUM_OF_COLORS;
    //    glutTimerFunc(200, goal_anime, (int)value);
    //}
}*/

// 初期化 全部ポジション０で赤色、死んでる <- 死んでるだけでいいや 死んでたら何もしないし
void init_character(void)
{
    int i;

    p_character = 0;
    for (i = 0; i < NUM_OF_CHARS; i++) {
        /*character[i].x = 0.0;
        character[i].y = 0.0;
        character[i].z = 0.0;
        character[i].r = 0.0;
        character[i].speed = 0.0;
        character[i].score = 0;
        character[i].color = RED;*/
        character[i].alive = 0;
        //character[i].move = 0;
    }
}

// キャラクター生成、（とりあえず）呼ぶと適当な位置に半径１で設定、生きてる
void new_character(void)
{
    int p = p_character++ % NUM_OF_CHARS;  // キャラクターリストの添字

    character[p].x     = get_rand(1, 11) + 0.0;
    character[p].y     = get_rand(20, 25) + 0.0;
    character[p].z     = get_rand(0, 2) + 0.0;
    character[p].r     = 1.0;
    character[p].speed = 0.1;
    character[p].score = 10;
    character[p].color = GRAY;
    character[p].alive = 1;
}

void update_character(void)
{
    int i;

    // なんか効率悪そうだけどどっち動いていいかの判定
    // ←構造体にspeedって属性持たせてその数だけ動かすようにしよう
    // speedが正のときは右、負のときは左に動く
    /*for (i = 0; i < NUM_OF_CHARS; i++) {
        if (character[i].x <= 1.0) {
            character[i].move = 1;
        } else if(character[i].x >= 11.0) {
            character[i].move = 0;
        }

        // 0.1ずつx軸方向に移動
        if (character[i].move) {
            character[i].x = character[i].x + 0.1;
        } else {
            character[i].x = character[i].x - 0.1;
        }
    }*/
    for (i = 0; i < NUM_OF_CHARS; i++) {
        if (character[i].alive) {
            character[i].x += character[i].speed;
        }
    }

    // 衝突判定によってaliveを0か1に変えるのをここにかかなきゃならんがまだ書いてない
}

// draw_characterを改変して使ってみる
void draw_one_character(s_character *character)
{
    GLfloat color_body[4];
    GLfloat color_eye[4] = {0.6, 0.0, 0.0, 1.0};

    double pos_base[3] = {-0.27, 0.0, 0.27};
    double pos_x, pos_y, pos_z;
    e_color color;
    int i;

    //ここだけ変えた
    pos_x = character->x;
    pos_y = character->y;
    pos_z = character->z;
    color = character->color;

    // set color
    color_body[0] = color_val[color][0];
    color_body[1] = color_val[color][1];
    color_body[2] = color_val[color][2];
    color_body[3] = 1.0;

    // start drawing an object
    glPushMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, color_body);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color_body);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_body);
    glMaterialf(GL_FRONT, GL_SHININESS, 80.0);

    // body
    draw_rectangle(0.5, 0.8, 0.3, pos_x + 0.0, pos_y - 0.1, pos_z);
    // head
    draw_rectangle(0.3, 0.3, 0.3, pos_x + 0.0, pos_y + 0.3, 0.2 + pos_z);

    for (i = 0; i < 3; i++) {
        // right
            // baseleg
            draw_rectangle(0.4, 0.07, 0.07, pos_x - 0.2, pos_y + pos_base[i] - 0.1, pos_z);
            // endleg
            draw_rectangle(0.07, 0.07, 0.3, pos_x - 0.4, pos_y + pos_base[i] - 0.1, -0.15 + pos_z);
        // left
            // baseleg
            draw_rectangle(0.4, 0.07, 0.07, pos_x + 0.2, pos_y + pos_base[i] - 0.1, pos_z);
            // endleg
            draw_rectangle(0.07, 0.07, 0.3, pos_x + 0.4, pos_y + pos_base[i] - 0.1, -0.15 + pos_z);
    }

    glMaterialfv(GL_FRONT, GL_AMBIENT, color_eye);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color_eye);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_eye);
    glMaterialf(GL_FRONT, GL_SHININESS, 80.0);

    // eyes
    draw_rectangle(0.05, 0.05, 0.05, pos_x + 0.07, pos_y + 0.45, 0.25 + pos_z);
    draw_rectangle(0.05, 0.05, 0.05, pos_x - 0.07, pos_y + 0.45, 0.25 + pos_z);

    // finish drawing an object
    glPopMatrix();
}

//描画
void disp_character(void)
{
    int i;
    for (i = 0; i < NUM_OF_CHARS; i++) {
        if (character[i].alive) {
            draw_one_character(&character[i]);
        }
    }
}
