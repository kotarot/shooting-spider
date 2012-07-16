// character.c
/*
キャラクターの生成
最初に10匹
やっつけた後に1匹
端までいったら左から出現

*/

#include <GL/glut.h>
#include "global.h"
#include "character.h"
#include "stage.h"
#include "color.h"

GLfloat color_val[NUM_OF_COLORS][3];

// 初期化 全部ポジション０で赤色、死んでる <- 死んでるだけでいいや 死んでたら何もしないし
void init_character(void)
{
    int i;

    p_character = 0;
    for (i = 0; i < NUM_OF_CHARS; i++) {
        character[i].alive = 0;
    }
}

// キャラクター生成、（とりあえず）呼ぶと適当な位置に半径１で設定、生きてる
void new_character(void)
{
    int direction, type; // drectionは進む向き、typeはキャラクターのタイプ
    int p = p_character++ % NUM_OF_CHARS;  // キャラクターリストの添字

    direction = get_rand(0, 1);  // 0か1の乱数生成 (右向きか左向きか)
    type = get_rand(0, 4); // 0から4の乱数 (普通キャラかスーパーキャラか)

    if (type == 0) { // 5分の1の確率でスーパーキャラ
        character[p].speed = 0.4;
        character[p].score = 50;
        character[p].color = YELLOW;
    } else {
        character[p].speed = 0.1;
        character[p].score = 10;
        character[p].color = GRAY;
    }

    if (direction == 0) { // 右向き
        character[p].x = -WIDTH_STAGE * 0.5; // 左端
    } else { // 左向き
        character[p].x = WIDTH_STAGE * 0.5; // 右端
        character[p].speed *= -1.0; // 向きを反転
    }

    // 共通の設定
    character[p].y = DISTANCE_STAGE + DEPTH_STAGE * 0.5;
    character[p].z = get_rand(0, 2) * HEIGHT_STAGE + 0.3/* この0.3ってキャラクターの高さだっけ？ */;
    character[p].r = 1.0;
    character[p].alive = 1;

}

void update_character(void)
{
    int i;

    // なんか効率悪そうだけどどっち動いていいかの判定
    // ←構造体にspeedって属性持たせてその数だけ動かすようにしよう
    // speedが正のときは右、負のときは左に動く
    for (i = 0; i < NUM_OF_CHARS; i++) {
        if (character[i].alive) {
            // スピード分だけすすめる
            character[i].x += character[i].speed;

            // 壁にあたったら消す
            if (character[i].x < -WIDTH_STAGE * 0.5 || WIDTH_STAGE * 0.5 < character[i].x) {
                character[i].alive = 0;
            }
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

    glTranslatef(pos_x, pos_y, pos_z);

    // 動いてる向きに回転させる
    if (character->speed < 0) {
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f); 
    } else {
        glRotatef(-90.0f, 0.0f, 0.0f, 1.0f); 
    }

    // body
    draw_rectangle(0.5, 0.8, 0.3, 0.0, -0.1, 0.0);
    // head
    draw_rectangle(0.3, 0.3, 0.3, 0.0, 0.3, 0.2);

    for (i = 0; i < 3; i++) {
        // right
            // baseleg
            draw_rectangle(0.4, 0.07, 0.07, -0.2, pos_base[i] - 0.1, 0.0);
            // endleg
            draw_rectangle(0.07, 0.07, 0.3, -0.4, pos_base[i] - 0.1, -0.15);
        // left
            // baseleg
            draw_rectangle(0.4, 0.07, 0.07, 0.2, pos_base[i] - 0.1, 0.0);
            // endleg
            draw_rectangle(0.07, 0.07, 0.3, 0.4, pos_base[i] - 0.1, -0.15);
    }

    glMaterialfv(GL_FRONT, GL_AMBIENT, color_eye);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color_eye);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_eye);
    glMaterialf(GL_FRONT, GL_SHININESS, 80.0);

    // eyes
    draw_rectangle(0.05, 0.05, 0.05, 0.07, 0.45, 0.25);
    draw_rectangle(0.05, 0.05, 0.05, -0.07, 0.45, 0.25);

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
