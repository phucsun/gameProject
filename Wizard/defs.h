#ifndef _DEFS__H
#define _DEFS__H

#define WINDOW_TITLE "WIZARD!"


#define SCREEN_WIDTH 1550
#define SCREEN_HEIGHT 810

#define UP_STATE 8
#define DOWN_STATE 5
#define TURN_STATE  6
#define BACK_STATE  4
#define ATTACK_STATE 9
#define STAND_STATE 0
#define SKILL_2_STATE 1
#define SKILL_3_STATE -2

#define MAX_ENEMIES 10

#define SKILL_W 180
#define SKILL_H 50
#define LIVE_STATE 0
#define DIE_STATE -1

#define BOOM_SPEED 15
#define BOOM_HEIGHT 53
#define BOOM_WIDTH 36

#define BULLET_TURN 0
#define BULLET_BACK 1

#define PLAYER_SPEED          8
#define PLAYER_BULLET_SPEED   16
#define PLAYER_RELOAD          20
#define MAX_KEYBOARD_KEYS 350
#define MAX_MOUSE_BUTTONS 3
#define SKILL_STATE 3

#define MENU_STATE 1
#define PLAY_STATE 2
#define END_STATE 0
#define HELP_STATE 3
#define ANIMATION_STATE 4
#define PAUSE_STATE 11

#define SIDE_PLAYER 0
#define SIDE_ALIEN  1

#define POS_X 100
#define POS_Y 600

#define FRAME_PER_SECOND 60

#define ENEMY_BULLET_SPEED    6

const int die_CLIPS[][4]={
    {20, 0, 97, 114},
    {180 , 0, 97, 114},
    {330, 0, 107, 114},
    {510, 0, 179, 114},
    };

const int die_FRAMES = sizeof(die_CLIPS)/sizeof(int)/4;

const int e_CLIPS[][4]={
    {1180, 10, 132, 132},
    {1040 , 0, 131, 138},
    {890, 0, 133, 169},
    {750, 0, 137, 186},
    {600, 0, 141, 175},
    {450, 0, 137, 139},
    {310, 0, 136, 130},
    {155, 0, 141, 131},
    {10, 0, 137, 131}

    };
const int e_FRAMES = sizeof(e_CLIPS)/sizeof(int)/4;

const int SKILL_4_CLIPS[][4]={
    {0, 0, 230, 230},
    {310 , 0, 231, 234},
    {630, 0, 224, 237},
    {960, 0, 221, 236},
    {1280, 0, 225, 232},

    };

const int SKILL_4_FRAMES = sizeof(SKILL_4_CLIPS)/sizeof(int)/4;

const int E_CLIPS[][4] ={
    {1650, 0, 80, 127},
    {1550 , 0, 85, 122},
    {1445, 0, 89, 125},
    {1355, 0, 84, 126},
    {1260, 0, 87, 125},
    {1170, 0, 89, 123},
    {1080, 0, 87, 126},
    {980, 0, 84, 131},
    {870, 0, 90, 130},
    {770, 0, 100, 130},
    {640, 0, 114, 129},
    {520, 0, 115, 129},
    {350, 0, 148, 127},
    {200, 0, 142, 126},
    {55, 0, 136, 130},

    };

const int E_FRAMES = sizeof(E_CLIPS)/sizeof(int)/4;

const int SKILL_2_CLIPS[][4] = {
    {  20, 20, 100, 140},
    {190 , 20, 106, 125},
    {355, 20, 126, 126},
    {530, 20, 153, 130},
    {525, 19, 172, 126},
    {700, 19, 332, 125}};

const int SKILL_2_FRAMES = sizeof(SKILL_2_CLIPS)/sizeof(int)/4;

const int SKILL_2B_CLIPS[][4] = {
    {  860, 0, 100, 129},
    {680 , 0, 115, 129},
    {500, 0, 124, 126},
    {300, 0, 154, 127},
    {0, 0, 278, 129}};

const int SKILL_2B_FRAMES = sizeof(SKILL_2B_CLIPS)/sizeof(int)/4;

const int SKILL_CLIPS[][4] = {
    {  10, 100, 101, 108},
    {150 , 100, 105, 102},
    {290, 70, 110, 137},
    {410, 40, 140, 160},
    {550, 20, 200, 190},
    {750, 20, 210, 187}};

const int SKILL_FRAMES = sizeof(SKILL_CLIPS)/sizeof(int)/4;

const int EX_CLIPS[][4] = {
    {  40, 60, 81, 57},
    {150 , 20, 149, 146},
    {300, 20, 151, 140},
    {500, 40, 127, 123}};

const int EX_FRAMES = sizeof(EX_CLIPS)/sizeof(int)/4;

const int BACK_CLIPS[][4] = {
    {  0, 0, 150, 140},
    { 170, 0, 150, 140},
    { 340,  0, 150, 140},
    {510, 0, 150, 140},
    {680, 0, 150, 140},
    {850, 0, 150, 140},
    {1020, 0, 150, 140},
    {1190, 0, 150, 140}};
const int BACK_FRAMES = sizeof(BACK_CLIPS)/sizeof(int)/4;

const int TURN_CLIPS[][4] = {
    {  0, 0, 150, 140},
    { 170, 0, 150, 140},
    { 340,  0, 150, 140},
    {510, 0, 150, 140},
    {680, 0, 150, 140},
    {850, 0, 150, 140},
    {1020, 0, 150, 140},
    {1190, 0, 150, 140}};
const int TURN_FRAMES = sizeof(TURN_CLIPS)/sizeof(int)/4;

const int SHOOT_CLIPS[][4] = {
    {  0, 0, 100, 126},
    {170, 0, 104, 126},
    {320, 0, 115, 125},
    {500, 0, 135, 126},
    {670,0, 133, 123}};
const int SHOOT_FRAMES = sizeof(SHOOT_CLIPS)/sizeof(int)/4;

const int SHOOTB_CLIPS[][4] = {
    {700,0, 92, 126},
    {530, 0, 99, 126},
    {360, 0, 113, 126},
    {160, 0, 131, 126},
    {  0, 0, 137, 123}};
const int SHOOTB_FRAMES = sizeof(SHOOTB_CLIPS)/sizeof(int)/4;

#endif
