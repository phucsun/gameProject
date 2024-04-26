#ifndef _DEFS__H
#define _DEFS__H

#define WINDOW_TITLE "CHICKEN INVADERS!"


#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 800

#define UP_STATE 8
#define DOWN_STATE 5
#define TURN_STATE  6
#define BACK_STATE  4
#define ATTACK_STATE 9
#define STAND_STATE 0
#define BOOM_SPEED 12

#define PLAYER_SPEED          6
#define PLAYER_BULLET_SPEED   16
#define PLAYER_RELOAD          20
#define MAX_KEYBOARD_KEYS 350

#define SIDE_PLAYER 0
#define SIDE_ALIEN  1

#define POS_X 100
#define POS_Y 600

#define FRAME_PER_SECOND 60

#define ENEMY_BULLET_SPEED    4

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
    {170, 0, 100, 126},
    {320, 0, 115, 125},
    {500, 0, 135, 126},
    {670,0, 133, 123}};
const int SHOOT_FRAMES = sizeof(SHOOT_CLIPS)/sizeof(int)/4;

#endif
