// input.c
// キーボード入力

#include <GL/glut.h>
#include "input.h"

// キーボード（文字キー）
void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        // change view
        //case 'v':
        //    visual_mode = (visual_mode + 1) % NUM_OF_VMODE;
        //    break;
        // new game
        //case 'n':
        //    init();
        //    break;
        // quit
        case 'q':
            exit(0);
    }
    //glutPostRedisplay(); // 再描画する
}

// キーボード（矢印キー）
void s_keyboard(int key, int x, int y)
{
    switch(key) {
        case GLUT_KEY_UP: // 上
            // ここで目標を上に動かす関数を呼ぶ
            break;
        case GLUT_KEY_DOWN: // 下
            // ここで目標を下に動かす関数を呼ぶ
            break;
        case GLUT_KEY_RIGHT: // 右
            // ここで目標を右に動かす関数を呼ぶ
            break;
        case GLUT_KEY_LEFT: // 左
            // ここで目標を左に動かす関数を呼ぶ
            break;
    }
    //glutPostRedisplay(); // 再描画する
}
