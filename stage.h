//stage.h

#ifndef __MY_STAGE__
#define __MY_STAGE__

#define DISTANCE_STAGE 25.0
#define WIDTH_STAGE    20.0
#define DEPTH_STAGE    5.0
#define HEIGHT_STAGE   2.8
#define THICK          0.3

//#define COLUMN 40
//#define ROW 20
//#define ROW_STAGE 25

/*typedef enum T_MAPFIELD {
    VACANT,
    CLIFF,
    BLOCK
} e_mapfield;*/
// information of path
//extern e_mapfield map[ROW + 2][COLUMN + 2];

void init_stage(void);
void disp_stage(void);

#endif
