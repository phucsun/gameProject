#ifndef _APP__H
#define _APP__H

#include<iostream>
#include<list>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
using namespace std;

struct GameObject {
	int x , y , w , h;
    float dx , dy;

    int sX , sY;
	int side;
	int health;
	int reload;
	int state;
	int score;
	int power;
	int moveDirection;
	bool damaged;
	bool collide;
	bool avoided;
	SDL_Texture *texture;

	bool checkCollision(GameObject* other);
	bool checkCollision_SKILL(GameObject *other);
	bool checkCollision_SKILL_BACK(GameObject *other);

    void player_move();

    void bullet_move(Sprite& e);
	void move();

	void move_();

    void AI_move(list<GameObject*>& bullets);

	bool offScreen();

	void initObject(int pos_x , int pos_y , int health_ , int reload_ , int side_);

};


#endif // _APP__H
