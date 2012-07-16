// input.c
// キーボード入力

#include "switch.h"

#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "input.h"
#include "shot.h"
#include "stage.h"

extern void init(void);

// キーボード（文字キー）
void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        // change view
        //case 'v':
        //    visual_mode = (visual_mode + 1) % NUM_OF_VMODE;
        //    break;
        // new game
        case 'n':
            init();
            break;
		case ' ': // SHOOT (ロウきゅーぶ！じゃないよ)
            {
                double a0, a1;
                a0 = atan(cursor_z / DISTANCE_STAGE);
                a1 = atan(cursor_x / DISTANCE_STAGE);
                //printf("a0=%lf (%lf)  a1=%lf (%lf)\n", a0, a0 * 180 / PI, a1, a1 * 180 / PI);
		        new_shot(0.05, a0 * 2.0 + 0.4/* この辺マジックナンバーすぎるｗ */, a1);
            }
            break;
		case 'l':
		//15がよかった <- なにが？
			eye_y += 0.5;
			break;
		case 'L':
			eye_y -= 0.5;
			break;
        // quit
        case 'q':
            exit(0);
    }
}

// キーボード（矢印キー）
void s_keyboard(int key, int x, int y)
{
    switch(key) {
        case GLUT_KEY_UP: // 上
			//eye_z += 0.5;
            // ここで目標を上に動かす関数を呼ぶ
            cursor_up();
            break;
        case GLUT_KEY_DOWN: // 下
			//eye_z -= 0.5;
            // ここで目標を下に動かす関数を呼ぶ
            cursor_down();
            break;
        case GLUT_KEY_RIGHT: // 右
			//eye_x += 0.5;
            // ここで目標を右に動かす関数を呼ぶ
            cursor_right();
            break;
        case GLUT_KEY_LEFT: // 左
			//eye_x -= 0.5;
            // ここで目標を左に動かす関数を呼ぶ
            cursor_left();
            break;
    }
}
