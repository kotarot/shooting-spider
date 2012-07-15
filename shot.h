// shot.h

#ifndef __MY_SHOT__
#define __MY_SHOT__

#define NUM_OF_SHOTS 16 // 弾の数

unsigned int game_time;

// 弾の構造体
typedef struct T_SHOT {
    double x; // 現在のx座標
    double y; // 現在のy座標
    double z; // 現在のz座標
    double v_x; // 現在の速度 x成分
    double v_y; // 現在の速度 y成分
    double v_z; // 現在の速度 z成分
    double v0; // 初速の大きさ
    double angle0; // 上方向の角度（1周360度法） -90~+90 xy平面と水平になる角度が0
    double angle1; // 横方向の角度 0~180 x軸方向が0
    unsigned int t; // 発射された時間
    int alive; // 弾の生死(0:死 1(0以外):生)
} s_shot;

// list(array) of shot
s_shot shot[NUM_OF_SHOTS];
int p_shot;

// 初期化
void init_shot(void);

// 弾生成
void new_shot(double v0, double angle0, double angle1);

// 弾更新
void update_shot(void);

// 弾描画
void disp_shot(void);
void disp_one_shot(s_shot *s);

// 衝突判定
int isHit(s_shot *s, s_character *c);

// 弾の位置計算
void calcShotPos(s_shot *s);

// 全ての弾の位置計算
void calcShotPosAll(void);

#endif
