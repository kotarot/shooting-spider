// global.h
// グローバル変数置き場
// extern付ける

#ifndef __MY_GLOBAL__
#define __MY_GLOBAL__

extern double aspect;
extern int width; // ウィンドウ幅
extern int height; // ウィンドウ高さ

typedef enum T_MODE {
    PLAYING,
    FINISHED
} e_mode;

extern unsigned int game_time; // ゲーム始まってからのタイム
extern e_mode game_mode;
extern int score;

#endif
