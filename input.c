// input.c
// キーボード入力

#include <stdlib.h>
#include <GL/glut.h>
#include "input.h"
#include "shot.h"

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
		case 's':
		    new_shot(0.1, 90.0, 45.0);
            break;
		case 'l':
		//15がよかった
			eye_y += 0.5;
			break;
		case 'L':
			eye_y -= 0.5;
			break;
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
			eye_z += 0.5;
            // ここで目標を上に動かす関数を呼ぶ
            break;
        case GLUT_KEY_DOWN: // 下
			eye_z -= 0.5;
            // ここで目標を下に動かす関数を呼ぶ
            break;
        case GLUT_KEY_RIGHT: // 右
			eye_x += 0.5;
            // ここで目標を右に動かす関数を呼ぶ
            break;
        case GLUT_KEY_LEFT: // 左
			eye_x -= 0.5;
            // ここで目標を左に動かす関数を呼ぶ
            break;
    }
    //glutPostRedisplay(); // 再描画する
}
