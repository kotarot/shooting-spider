// character.c
/*
キャラクターの生成
最初に10匹
やっつけた後に1匹
端までいったら左から出現

*/

#include <GLUT/glut.h>
//#include "global.h"
#include "character.h"
#include "stage.h"

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
	character[p].x = get_rand(-WIDTH_STAGE / 2, WIDTH_STAGE / 2) ;
	/*
	if (get_rand(0,1)) {
		character[p].x = -WIDTH_STAGE / 2 ;
	} else {
		character[p].x = WIDTH_STAGE / 2;
	}
	*/
    character[p].y     =  DISTANCE_STAGE + DEPTH_STAGE / 2.0;
    character[p].z     = get_rand(0, 2) * HEIGHT_STAGE + 0.3;
    character[p].r     = 1.0;
	if (character->x < 0) {
    	character[p].speed = 0.1;
	} else {
    	character[p].speed = -0.1;
	}
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
		//場外にいった場合
		if (character[i].x > WIDTH_STAGE / 2 || character[i].x < -WIDTH_STAGE / 2) {
			renew_character(&character[i]);
		}
    }

    // 衝突判定によってaliveを0か1に変えるのをここにかかなきゃならんがまだ書いてない
}
void renew_character(s_character *character){
	if (get_rand(0,1)) {
		character->x = -WIDTH_STAGE / 2 ;
	} else {
		character->x = WIDTH_STAGE / 2 ;
	}
    //character->y     =get_rand(DISTANCE_STAGE, DISTANCE_STAGE + DEPTH_STAGE) + 0.0;
    character->y     = DISTANCE_STAGE + DEPTH_STAGE / 2.0;
    character->z     = get_rand(0, 2) * HEIGHT_STAGE + 0.3;
    character->r     = 1.0;
 //   character->speed = 0.1;
	if (character->x < 0) {
    	character->speed = 0.1;
	} else {
    	character->speed = -0.1;
	}
    character->score = 10;
    //character->color = GRAY;
    character->color = get_rand(0,NUM_OF_COLORS - 1);
    character->alive = 1;
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
	if (character->speed < 0) {
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f); 
	} else {
		glRotatef(-90.0f, 0.0f, 0.0f, 1.0f); 
	}


    // body
    draw_rectangle(0.5, 0.8, 0.3, 0.0, - 0.1, 0.0 );
    // head
    draw_rectangle(0.3, 0.3, 0.3, 0.0, 0.3, 0.2 );

    for (i = 0; i < 3; i++) {
        // right
            // baseleg
            draw_rectangle(0.4, 0.07, 0.07, -0.2, pos_base[i] - 0.1, 0.0  );
            // endleg
            draw_rectangle(0.07, 0.07, 0.3, -0.4, pos_base[i] - 0.1, -0.15 );
        // left
            // baseleg
            draw_rectangle(0.4, 0.07, 0.07, 0.2, pos_base[i] - 0.1, 0.0 );
            // endleg
            draw_rectangle(0.07, 0.07, 0.3, 0.4, pos_base[i] - 0.1, -0.15 );
    }

    glMaterialfv(GL_FRONT, GL_AMBIENT, color_eye);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color_eye);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_eye);
    glMaterialf(GL_FRONT, GL_SHININESS, 80.0);

    // eyes
    draw_rectangle(0.05, 0.05, 0.05, 0.07, 0.45, 0.25 );
    draw_rectangle(0.05, 0.05, 0.05, - 0.07, 0.45, 0.25 );

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
