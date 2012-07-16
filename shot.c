﻿// shot.c

#include <GLUT/glut.h>
#include <math.h>
#include "shot.h"
#include "color.h"
#include "stage.h"
#include "global.h"
#include "letter.h"

#define G 0.0007	// 重力加速度は適当な値に
#define shot_r 0.5	//弾の半径(これも適当な値に)

// *** これはglobal.hに入れた方が良い？ <- いやここでいいよ
GLfloat shot_color[4]= {0.0, 0.0, 0.0, 1.0};  // 弾の色(黒色)

int score;

// 弾の初期化関数
void init_shot(void)
{
	int i;

	// 全ての弾を初期化する
	// 弾を生成するときに座標とかその他もろもろの情報を決めるだろうから
	// ここでは弾の生死のみを全て「死」状態にしておけばいいかな、程度に
	for (i = 0; i < NUM_OF_SHOTS; i++){
		// 弾をすべて殺す
		shot[i].alive = 0;
	}

	// 弾リストのポインタを最初に戻す。
	p_shot= 0;
}

// 弾生成関数
void new_shot(double v0, double angle0, double angle1)
{
	// 弾リストのポインタ
	int p = p_shot++ % NUM_OF_SHOTS;

	// 与えられた引数や現在時間から、新たに打ち出された弾の値をセット
	shot[p].x = 0.0;
    shot[p].y = 0.0;
    shot[p].z = 0.0;
	shot[p].t = game_time;
	shot[p].v0 = v0;
	shot[p].angle0 = angle0;
	shot[p].angle1 = angle1;
    shot[p].v_x= v0 * cos(angle0/* * PI / 180*/) * sin(angle1/* * PI / 180*/);
	shot[p].v_y= v0 * cos(angle0/* * PI / 180*/) * cos(angle1/* * PI / 180*/);
    shot[p].v_z = 0.0;
	shot[p].alive = 1;
}

// 弾情報更新
void update_shot(void)
{
	int i, j;

	// 全ての弾について、現在位置を更新した後
	// 衝突判定を行い、衝突している弾を殺す。
	// *** 弾が当たっている場合は、何かフラグでも立てた方がいいかな？(得点計算的に)
	// *** 描画関数は呼び出さなくていいんだよね？ <- いいよ
	calcShotPosAll();
	for(i=0; i<NUM_OF_SHOTS; i++){
		// 衝突判定は、生きている弾についてのみ行う
		if(shot[i].alive != 0){
			for(j=0; j<p_character; j++){
				if(isHit(&shot[i], &character[j]) == 1 && character[j].alive){
                    score += character[j].score;
                    //printf("HIT!!!  score = %d\n", score);
                    character[j].alive = 0;
					shot[i].alive= 0;
				}
			}
		}
	}

}

// 弾描画関数
void disp_shot(void)
{
    int i;

    for (i = 0; i < NUM_OF_SHOTS; i++) {
        if (shot[i].alive) {
            disp_one_shot(&shot[i]);
        }
    }
}

void disp_one_shot(s_shot *s)
{
	// 弾の描画にはglutSolidSphere関数を使用
	glPushMatrix();
	glTranslated(s->x, s->y, s->z);
	//glScalef(shot_r, shot_r, shot_r);

	// 照光処理
	glMaterialfv(GL_FRONT, GL_AMBIENT, shot_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, shot_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, shot_color);
	glMaterialf(GL_FRONT, GL_SHININESS, 60.0);

	// Scalefを使わずに、SolidSphereの1つ目の引数にshot_rを指定しても良い。
	//glutSolidSphere(1.0, 40, 40);
	glutSolidSphere(shot_r, 10, 10);
	glPopMatrix();
}

// 弾の衝突判定関数
int isHit(s_shot *s, s_character *c)
{
	double x_dis, y_dis, z_dis;//, dis;

	// 距離の計算
	x_dis= (s->x - c->x) * (s->x - c->x);
	y_dis= (s->y - c->y) * (s->y - c->y);
	z_dis= (s->z - c->z) * (s->z - c->z);
	//dis= sqrt(x_dis + y_dis + z_dis);  // <- ルートの計算重いから

	// 衝突判定
	if((x_dis + y_dis + z_dis) <= (c->r * c->r)){  // 2乗同士で比べた方がいい
		return 1;
	} else {
		return 0;
	}
}

// 弾の座標を計算する関数
void calcShotPos(s_shot *s)
{
	// 時間はtではなく、(現在の時間) - t。
	unsigned int live_t= game_time - s->t;

	// 各速度の計算
	s->v_z= s->v0 * sin(s->angle0/* * PI / 180*/) - G * live_t;

    //printf("vx=%lf vy=%lf vz=%lf\n", s->v_x, s->v_y, s->v_z);

	// 各座標の計算
	s->x= s->x + s->v_x * live_t;
	s->y= s->y + s->v_y * live_t;
	s->z= s->z + s->v_z * live_t - G * live_t * live_t * 0.5;

    // z座標が負になってたら殺す
    if (s->z < 0) {
        s->alive = 0;
    }

    //s->z = 0;

    //printf("x=%lf y=%lf z=%lf\n", s->x, s->y, s->z);
}

// 全ての生きている弾の座標を計算する関数
void calcShotPosAll(void)
{
	int i;

	for (i = 0; i < NUM_OF_SHOTS; i++) {
		//生きている弾について、座標を計算する。
		if (shot[i].alive == 1) {
			calcShotPos(&shot[i]);
		}
	}
}


// 以下カーソル関連
void init_cursor()
{
    cursor_x = 0.0;
    cursor_z = HEIGHT_STAGE;
}

void cursor_up()
{
    if (cursor_z < HEIGHT_STAGE * 3.0) {
        cursor_z += CURSOR_SPEED;
    }
}

void cursor_down()
{
    if (0 < cursor_z) {
        //cursor_z -= 0.1;
        cursor_z -= CURSOR_SPEED;
    }
}

void cursor_right()
{
    if (cursor_x < WIDTH_STAGE * 0.5) {
        //cursor_x += 0.1;
        cursor_x += CURSOR_SPEED;
    }
}

void cursor_left()
{
    if (-WIDTH_STAGE * 0.5 < cursor_x) {
        //cursor_x -= 0.1;
        cursor_x -= CURSOR_SPEED;
    }
}

void disp_cursor()
{
    glDisable(GL_LIGHTING);
    glPushMatrix();

    glColor3d(0.9, 0.0, 0.0); // red
    glBegin(GL_POLYGON);
        glVertex3d(cursor_x + 0.5, DISTANCE_STAGE - 1.0, cursor_z + 0.05);
        glVertex3d(cursor_x + 0.5, DISTANCE_STAGE - 1.0, cursor_z - 0.05);
        glVertex3d(cursor_x - 0.5, DISTANCE_STAGE - 1.0, cursor_z - 0.05);
        glVertex3d(cursor_x - 0.5, DISTANCE_STAGE - 1.0, cursor_z + 0.05);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3d(cursor_x + 0.05, DISTANCE_STAGE - 1.0, cursor_z + 0.5);
        glVertex3d(cursor_x + 0.05, DISTANCE_STAGE - 1.0, cursor_z - 0.5);
        glVertex3d(cursor_x - 0.05, DISTANCE_STAGE - 1.0, cursor_z - 0.5);
        glVertex3d(cursor_x - 0.05, DISTANCE_STAGE - 1.0, cursor_z + 0.5);
    glEnd();

    glPopMatrix();
    glEnable(GL_LIGHTING);
}
