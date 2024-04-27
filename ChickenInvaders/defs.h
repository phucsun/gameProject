#ifndef _DEFS__H
#define _DEFS__H

#define WINDOW_TITLE "WIZARD!"


#define SCREEN_WIDTH 1550
#define SCREEN_HEIGHT 820

#define UP_STATE 8
#define DOWN_STATE 5
#define TURN_STATE  6
#define BACK_STATE  4
#define ATTACK_STATE 9
#define STAND_STATE 0

#define LIVE_STATE 0
#define DIE_STATE -1

#define BOOM_SPEED 15
#define BOOM_HEIGHT 53
#define BOOM_WIDTH 36


#define PLAYER_SPEED          10
#define PLAYER_BULLET_SPEED   16
#define PLAYER_RELOAD          20
#define MAX_KEYBOARD_KEYS 350
#define SKILL_STATE 3

#define MENU_STATE 1
#define PLAY_STATE 2
#define END_STATE 0

#define SIDE_PLAYER 0
#define SIDE_ALIEN  1

#define POS_X 100
#define POS_Y 600

#define FRAME_PER_SECOND 60

#define ENEMY_BULLET_SPEED    4

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
    {170, 0, 100, 126},
    {320, 0, 115, 125},
    {500, 0, 135, 126},
    {670,0, 133, 123}};
const int SHOOT_FRAMES = sizeof(SHOOT_CLIPS)/sizeof(int)/4;

#endif
