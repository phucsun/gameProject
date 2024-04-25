#ifndef _DEFS__H
#define _DEFS__H

#define WINDOW_TITLE "CHICKEN INVADERS!"


#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 800

#define PLAYER_SPEED          6
#define PLAYER_BULLET_SPEED   16
#define PLAYER_RELOAD          8
#define MAX_KEYBOARD_KEYS 350

#define SIDE_PLAYER 0
#define SIDE_ALIEN  1

#define POS_X 100
#define POS_Y 600

#define FRAME_PER_SECOND 60

#define ENEMY_BULLET_SPEED    4

const int BACK_CLIPS[][4] = {
    {  0, 0, 50, 100},
    { 43, 0, 50, 100},
    {86, 0, 50, 100},
    {129, 0, 50, 100},
    {172, 0, 50, 100},
    {215, 0, 50, 100}};
const int BACK_FRAMES = sizeof(BACK_CLIPS)/sizeof(int)/4;

const int TURN_CLIPS[][4] = {
    {  0, 0, 50, 100},
    { 43, 0, 50, 100},
    {86, 0, 50, 100},
    {129, 0, 50, 100},
    {172, 0, 50, 100},
    {215, 0, 50, 100}};
const int TURN_FRAMES = sizeof(TURN_CLIPS)/sizeof(int)/4;

#endif
